// main.cpp — miniRV emulator runner (similar style to your sCPU runner)

#include <bitset>
#include <cstdint>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "minirv_emulator.h"

// ----------------------- CONFIG -----------------------
#define NUM_INST   6000
#define NUM_TESTS  6000
// ------------------------------------------------------

static void Print32(const std::string& label, uint32_t v) {
    std::cout << label << ":\t"
              << std::bitset<32>(v)
              << " (DEC: " << std::dec << v << ")"
              << " (HEX: 0x" << std::hex << std::setw(8) << std::setfill('0') << v << ")"
              << std::dec << std::setfill(' ') << "\n";
}

static const char* DecodeOpName(uint32_t inst) {
    uint32_t opcode = inst & 0x7F;
    uint32_t funct3 = (inst >> 12) & 0x7;
    uint32_t funct7 = (inst >> 25) & 0x7F;

    if (opcode == 0x33 && funct3 == 0x0 && funct7 == 0x00) return "ADD";
    if (opcode == 0x13 && funct3 == 0x0)                  return "ADDI";
    if (opcode == 0x37)                                   return "LUI";
    if (opcode == 0x03 && funct3 == 0x2)                  return "LW";
    if (opcode == 0x03 && funct3 == 0x4)                  return "LBU";
    if (opcode == 0x23 && funct3 == 0x2)                  return "SW";
    if (opcode == 0x23 && funct3 == 0x0)                  return "SB";
    if (opcode == 0x67 && funct3 == 0x0)                  return "JALR";
    return "ILLEGAL";
}

int main() {
    minirvEmulator emulator;

    if (!emulator.LoadInstructionMemoryFromFile(std::filesystem::current_path() / ".." / "instructions" / "instruction.txt", 0)) {
        std::cerr << "Failed to load instruction memory from: " << std::filesystem::current_path() / "instructions" / "instruction.txt" << "\n";
        return 1;
    }

    // Dump first NUM_INST words (PC=0 corresponds to word_index=0)
    std::cout << "Loaded instructions from file.\n";

    // for (int i = 0; i < NUM_INST; ++i) {
    //     uint32_t addr = static_cast<uint32_t>(i) * 4; // byte address
    //     try {
    //         uint32_t w = emulator.GetInstructionMemoryValue(addr);
    //         std::cout << "IMEM[" << std::dec << i << "] @0x"
    //                   << std::hex << std::setw(8) << std::setfill('0') << addr
    //                   << " = 0x" << std::setw(8) << w
    //                   << std::dec << std::setfill(' ') << "\n";
    //     } catch (...) {
    //         std::cout << "IMEM[" << i << "] out of range\n";
    //         break;
    //     }
    // }

    std::cout << "\nStarting execution...\n\n";

    std::ofstream pcOutFile(std::filesystem::current_path() / "txt" / "golden_model_pc.txt");
    if (!pcOutFile.is_open()) 
    {
        std::cerr << "Error: Could not open file golden_model_pc.txt for writing." << std::endl;
        return 1;
    }

    std::ofstream registerOutFile(std::filesystem::current_path() / "txt" / "golden_model_register.txt");
    if (!registerOutFile.is_open()) 
    {
        std::cerr << "Error: Could not open file golden_model_instruction.txt for writing." << std::endl;
        return 1;
    }

    std::ofstream instructionOutFile(std::filesystem::current_path() / "txt" / "golden_model_instruction.txt");
    if (!instructionOutFile.is_open()) 
    {
        std::cerr << "Error: Could not open file golden_model_register.txt for writing." << std::endl;
        return 1;
    }
    
    for (int cycle = 0; cycle < NUM_TESTS; ++cycle) {
        try {
            uint32_t pc = emulator.GetPCValue();
            uint32_t inst = emulator.GetInstructionMemoryValue(pc);

            std::cout << "Cycle:\t\t" << std::dec << cycle << "\n";
            Print32("PC", pc);
            Print32("Instruction", inst);
            std::cout << "Operation:\t" << DecodeOpName(inst) << "\n";

            // Show decoded fields (RV32)
            uint32_t opcode = inst & 0x7F;
            uint32_t rd     = (inst >> 7)  & 0x1F;
            uint32_t funct3 = (inst >> 12) & 0x7;
            uint32_t rs1    = (inst >> 15) & 0x1F;
            uint32_t rs2    = (inst >> 20) & 0x1F;
            uint32_t funct7 = (inst >> 25) & 0x7F;

            std::cout << "Fields:\t\t"
                      << "opcode=" << std::hex << std::bitset<7>(opcode)
                      << " rd=x" << std::dec << rd
                      << " rs1=x" << rs1
                      << " rs2=x" << rs2
                      << " funct3=0x" << std::hex << funct3
                      << " funct7=0x" << funct7
                      << std::dec << "\n";

            // Show x0..x15 (your CPU only has 16 regs)
            for (int r = 0; r < 16; ++r) {
                uint32_t rv = emulator.GetRegisterValue(static_cast<uint8_t>(r));
                std::string name = "x" + std::to_string(r);
                Print32(name, rv);
            }

            std::cout << "----------------------------------------\n";

            instructionOutFile << std::bitset<32>(inst);
            registerOutFile << std::bitset<32>(emulator.GetRegisterValue(0));
            registerOutFile << std::bitset<32>(emulator.GetRegisterValue(1));
            registerOutFile << std::bitset<32>(emulator.GetRegisterValue(2));
            registerOutFile << std::bitset<32>(emulator.GetRegisterValue(3));
            registerOutFile << std::bitset<32>(emulator.GetRegisterValue(4));
            registerOutFile << std::bitset<32>(emulator.GetRegisterValue(5));
            registerOutFile << std::bitset<32>(emulator.GetRegisterValue(6));
            registerOutFile << std::bitset<32>(emulator.GetRegisterValue(7));
            registerOutFile << std::bitset<32>(emulator.GetRegisterValue(8));
            registerOutFile << std::bitset<32>(emulator.GetRegisterValue(9));
            registerOutFile << std::bitset<32>(emulator.GetRegisterValue(10));
            registerOutFile << std::bitset<32>(emulator.GetRegisterValue(11));
            registerOutFile << std::bitset<32>(emulator.GetRegisterValue(12));
            registerOutFile << std::bitset<32>(emulator.GetRegisterValue(13));
            registerOutFile << std::bitset<32>(emulator.GetRegisterValue(14));
            registerOutFile << std::bitset<32>(emulator.GetRegisterValue(15));
            pcOutFile << std::bitset<32>(pc);

            emulator.Step();
        } catch (const std::exception& e) {
            std::cerr << "HALT/EXCEPTION at cycle " << cycle << ": " << e.what() << "\n";
            std::cerr << "PC was 0x" << std::hex << emulator.GetPCValue() << std::dec << "\n";
            return 1;
        }
    }

    pcOutFile.close();
    registerOutFile.close();
    instructionOutFile.close();
    return 0;
}
