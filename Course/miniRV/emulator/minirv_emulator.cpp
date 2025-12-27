#include "minirv_emulator.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

static inline uint32_t get_bits(uint32_t x, int hi, int lo) {
    uint32_t width = (uint32_t)(hi - lo + 1);
    uint32_t mask  = (width == 32) ? 0xFFFFFFFFu : ((1u << width) - 1u);
    return (x >> lo) & mask;
}

static inline int32_t sign_extend(uint32_t x, int bits) {
    // bits: number of valid bits in x (e.g., 12)
    if (bits == 32) return (int32_t)x;
    uint32_t m = 1u << (bits - 1);
    uint32_t r = (x ^ m) - m;
    return (int32_t)r;
}

void minirvEmulator::Evaluate(uint32_t instruction)
{
    uint8_t opcode =  instruction        & 0x7F;
    uint8_t rd     = (instruction >> 7)  & 0x1F;  rd  &= 0x0F;
    uint8_t funct3 = (instruction >> 12) & 0x07;
    uint8_t rs1    = (instruction >> 15) & 0x1F;  rs1 &= 0x0F;
    uint8_t rs2    = (instruction >> 20) & 0x1F;  rs2 &= 0x0F;
    uint8_t funct7 = (instruction >> 25) & 0x7F;

    // which_instruction
    uint8_t add=0, addi=0, lui=0, lw=0, lbu=0, sw=0, sb=0, jalr=0, illegal=0;

    if (opcode == 0b0110011 && funct3 == 0b000 && funct7 == 0b0000000) add = 1;
    else if (opcode == 0b0010011 && funct3 == 0b000) addi = 1;
    else if (opcode == 0b0110111) lui = 1;
    else if (opcode == 0b0000011 && funct3 == 0b010) lw = 1;
    else if (opcode == 0b0000011 && funct3 == 0b100) lbu = 1;
    else if (opcode == 0b0100011 && funct3 == 0b010) sw = 1;
    else if (opcode == 0b0100011 && funct3 == 0b000) sb = 1;
    else if (opcode == 0b1100111 && funct3 == 0b000) jalr = 1;
    else illegal = 1;

    if (illegal) 
    {
        throw std::runtime_error("Illegal instruction");
    }

    // immediate
    uint32_t imm = 0;
    if (addi || lw || lbu || jalr) // i-type 
    {
        uint32_t imm12 = get_bits(instruction, 31, 20);
        imm = (uint32_t)sign_extend(imm12, 12);
    } 
    else if (sw || sb) // s-type 
    {
        uint32_t imm12 = (get_bits(instruction, 31, 25) << 5) | get_bits(instruction, 11, 7);
        imm = (uint32_t)sign_extend(imm12, 12);
    } 
    else if (lui) // u-type 
    { 
        imm = instruction & 0xFFFFF000u;
    }

    uint32_t rs1_val = registers_[rs1];
    uint32_t rs2_val = registers_[rs2];

    // b mux
    uint32_t b = (addi || lw || lbu || sw || sb || jalr) ? imm : rs2_val;

    // ALU (add only)
    uint32_t y = rs1_val + b;

    // data memory (word array version)
    uint32_t read_data = 0;
    if (sw || sb || lw || lbu) 
    {
        uint32_t word_index = y >> 2;
        if (word_index >= data_memory_.size()) 
        {
            throw std::out_of_range("Data memory address out of range");
        }
        if (sw) 
        {
            data_memory_[word_index] = rs2_val;
        }
        else if (sb) 
        {
            uint32_t byte_offset = y & 0x3;
            uint32_t shift       = byte_offset * 8;
            uint32_t old_word    = data_memory_[word_index];
            uint32_t mask        = ~(0xFFu << shift);
            data_memory_[word_index] = (old_word & mask) | ((rs2_val & 0xFFu) << shift);
        }
        else if (lw) 
        {
            read_data = data_memory_[word_index];
        }
        else if (lbu) 
        {
            uint32_t word        = data_memory_[word_index];
            uint32_t byte_offset = y & 0x3;
            uint32_t shift       = byte_offset * 8;
            read_data = (word >> shift) & 0xFFu;
        }
    }

    // writeback mux
    uint32_t pc_plus_4 = pc_ + 4;
    uint32_t rd_data = 0;
    bool reg_write = false;

    if (add || addi) 
    {
        rd_data = y; 
        reg_write = true; 
    }
    else if (lui)    
    {
        rd_data = imm; 
        reg_write = true; 
    }
    else if (lw || lbu) 
    { 
        rd_data = read_data; 
        reg_write = true; 
    }
    else if (jalr)   
    { 
        rd_data = pc_plus_4; 
        reg_write = true; 
    }

    if (reg_write) 
    {
        if (rd != 0) 
        {
            registers_[rd] = rd_data;
        }
    }
    registers_[0] = 0;

    // next pc
    pc_ = jalr ? (y & 0xFFFF'FFFCu) : pc_plus_4;
}


uint32_t minirvEmulator::GetRegisterValue(uint8_t reg_num)
{
    return registers_[reg_num & 0x0F];
}

uint32_t minirvEmulator::GetPCValue()
{
    return pc_;
}

uint32_t minirvEmulator::GetInstructionMemoryValue(uint32_t address)
{
    uint32_t idx = address >> 2;
    if (idx >= instruction_memory_.size()) {
        throw std::out_of_range("Instruction memory address out of range");
    }
    return instruction_memory_[idx];
}

uint32_t minirvEmulator::GetDataMemoryValue(uint32_t address)
{
    uint32_t word_index = address >> 2;   // byte address → word index
    if (word_index >= data_memory_.size()) {
        throw std::out_of_range("Data memory address out of range");
    }
    return data_memory_[word_index];
}

void minirvEmulator::SetRegisterValue(uint8_t reg_num, uint32_t value)
{
    reg_num &= 0x0F;
    if (reg_num == 0) return;
    registers_[reg_num] = value;
}

void minirvEmulator::SetPCValue(uint32_t pc)
{
    pc_ = pc;
}

void minirvEmulator::SetInstructionMemoryValue(uint32_t address, uint32_t value)
{
    uint32_t idx = address >> 2;
    if (idx >= instruction_memory_.size()) {
        throw std::out_of_range("Instruction memory address out of range");
    }
    instruction_memory_[idx] = value;
}

void minirvEmulator::SetDataMemoryValue(uint32_t address, uint32_t value)
{
    uint32_t word_index = address >> 2;   // byte address → word index
    if (word_index >= data_memory_.size()) {
        throw std::out_of_range("Data memory address out of range");
    }
    data_memory_[word_index] = value;
}


void minirvEmulator::ResetRegisters()
{
    registers_.assign(registers_.size(), 0); 
}

void minirvEmulator::ResetInstructionMemory()
{
    instruction_memory_.assign(instruction_memory_.size(), 0);
}

void minirvEmulator::ResetPC()
{
    pc_ = 0;
}

void minirvEmulator::ResetDataMemory()
{
    data_memory_.assign(data_memory_.size(), 0);
}

void minirvEmulator::Step()
{
    uint32_t word_index = pc_ >> 2;   // byte PC -> word index
    if (word_index >= instruction_memory_.size()) {
        throw std::out_of_range("PC out of instruction memory range");
    }
    uint32_t instruction = instruction_memory_[word_index];
    Evaluate(instruction);
}


bool minirvEmulator::LoadInstructionMemoryFromFile(const std::string& filename, uint32_t start_word_index)
{
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    std::string line;
    uint32_t idx = start_word_index;

    while (std::getline(file, line)) {
        auto first = line.find_first_not_of(" \t\r\n");
        if (first == std::string::npos) continue;

        auto token = line.substr(first, line.find_first_of(" \t#\r\n", first) - first);
        if (token.empty()) continue;

        uint32_t word = 0;
        try {
            word = static_cast<uint32_t>(std::stoul(token, nullptr, 16));
        } catch (...) {
            std::cerr << "Invalid hex word: " << line << "\n";
            continue;
        }

        if (idx >= instruction_memory_.size()) {
            std::cerr << "Instruction memory overflow at word index: " << idx << "\n";
            break;
        }
        instruction_memory_[idx] = word;
        data_memory_[idx] = word;
        idx++;
    }
    return true;
}
