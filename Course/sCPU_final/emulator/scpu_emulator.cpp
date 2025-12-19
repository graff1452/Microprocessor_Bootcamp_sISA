#include "scpu_emulator.h"
#include <iostream>
#include <fstream>

void ScpuEmulator::Evaluate(uint8_t instruction)
{       
    uint8_t op      = (instruction >> 6)    & 0b11;
    uint8_t rd      = (instruction >> 4)    & 0b11;
    uint8_t rs1     = (instruction >> 2)    & 0b11;
    uint8_t rs2     = (instruction)         & 0b11;
    uint8_t addr    = (instruction >> 2)    & 0b1111;
    uint8_t imm     = (instruction)         & 0b1111;

    if (op == 0b00) // add
    {
        uint8_t sum = static_cast<uint8_t>(registers_[rs1] + registers_[rs2]);
        registers_[rd] = sum;
        alu_ = sum;
        pc_++;
    }
    else if (op == 0b01) // nothing
    {
        pc_++;
        alu_ = 0;
    }
    else if (op == 0b10) // li
    {
        registers_[rd] = imm;
        pc_++;
        alu_ = imm;
    }
    else // bneR0 
    {
        if (registers_[0] != registers_[rs2])
        {
            pc_ = addr;
        }
        else 
        {
            pc_++;
        }
        alu_ = 0;
    }
}

uint8_t ScpuEmulator::GetRegisterValue(uint8_t reg_num)
{
    if (reg_num >= registers_.size()) 
    {
        throw std::out_of_range("register address out of range");
    }
    return registers_[reg_num];
}

uint8_t ScpuEmulator::GetPCValue()
{
    return pc_;
}

uint8_t ScpuEmulator::GetInstructionMemoryValue(uint8_t address)
{
    if (address >= instruction_memory_.size())
    {
        throw std::out_of_range("Instruction memory address out of range");
    }
    return instruction_memory_[address];
}

uint8_t ScpuEmulator::GetAluValue()
{
    return alu_;
}

void ScpuEmulator::SetRegisterValue(uint8_t reg_num, uint8_t value)
{
    if (reg_num >= registers_.size())
    {
        throw std::out_of_range("Register number out of range");
    }
    registers_[reg_num] = value;
    return;
}

void ScpuEmulator::SetPCValue(uint8_t pc)
{
    pc_ = pc;
}

void ScpuEmulator::SetInstructionMemoryValue(uint8_t address, uint8_t value)
{
    if (address >= instruction_memory_.size())
    {
        throw std::out_of_range("Memory address out of range");
    }
    instruction_memory_[address] = value;
}

void ScpuEmulator::SetAluValue(uint8_t value)
{
    alu_ = value;
}

void ScpuEmulator::ResetRegisters()
{
    registers_.assign(registers_.size(), 0); 
}

void ScpuEmulator::ResetInstructionMemory()
{
    instruction_memory_.assign(instruction_memory_.size(), 0);
}

void ScpuEmulator::ResetPC()
{
    pc_ = 0;
}

void ScpuEmulator::ResetAlu()
{
    alu_ = 0;
}

void ScpuEmulator::Step()
{
    pc_ &= 0x0F;  // keep pc_ in 0..15
    uint8_t instruction = instruction_memory_[pc_];
    Evaluate(instruction);
}

bool ScpuEmulator::LoadInstructionMemoryFromFile(const std::string& filename, uint8_t start_address)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }
    std::string line;
    uint8_t address = start_address;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        try {
            // If your lines are like "8A # comment", parse only the first token
            auto token = line.substr(0, line.find_first_of(" \t#"));
            uint8_t instruction = static_cast<uint8_t>(std::stoul(token, nullptr, 16));

            if (address < instruction_memory_.size()) {
                instruction_memory_[address++] = instruction;
            } else {
                std::cerr << "Memory overflow at address: " << address << "\n";
                break;
            }
        } catch (const std::exception&) {
            std::cerr << "Invalid instruction format: " << line << "\n";
        }
    }

    file.close();
    return true;
}