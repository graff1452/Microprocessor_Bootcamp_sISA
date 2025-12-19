#include <iostream>
#include "scpu_emulator.h"
#include <bitset>
#include <fstream>
#include <cstdint>

#define NUM_INST 16
#define NUM_TESTS 1000000
#define LOADFILEPATH "/home/graff145/Desktop/Microprocessor_Bootcamp_sISA/Course/sCPU_final/generator/instructions.txt"
#define PCOUTFILEPATH "/home/graff145/Desktop/Microprocessor_Bootcamp_sISA/Course/sCPU_final/emulator/txt/pc_out_golden_model.txt"
#define REGISTERFILEPATH "/home/graff145/Desktop/Microprocessor_Bootcamp_sISA/Course/sCPU_final/emulator/txt/register_golden_model.txt"

int main()
{
    ScpuEmulator emulator;
    emulator.LoadInstructionMemoryFromFile(LOADFILEPATH, 0);
    for (int i = 0; i < NUM_INST; i++)
    {
        std::cout << "Memory[" << std::dec << i << "]: " << std::hex << static_cast<int>(emulator.GetInstructionMemoryValue(i)) << std::endl;
    }
    std::cout << "Loaded instructions from file." << std::endl;
    std::cout << "Starting execution...\n" << std::endl;

    std::ofstream pcOutFile(PCOUTFILEPATH);
    if (!pcOutFile.is_open()) 
    {
        std::cerr << "Error: Could not open file pc_out.txt for writing." << std::endl;
        return 1;
    }

    std::ofstream registerFile(REGISTERFILEPATH);
    if (!pcOutFile.is_open()) 
    {
        std::cerr << "Error: Could not open file register.txt for writing." << std::endl;
        return 1;
    }

    for (int test = 0; test < NUM_TESTS; test++) //Uncomment to Debug
    {   
        // std::cout << "Cycle:\t\t"           << std::dec << test << std::endl;
        // std::cout << "PC:\t\t"              << std::bitset<4>(emulator.GetPCValue()) << " (DEC: " << std::dec << static_cast<int>((emulator.GetPCValue())) << ")" << " (HEX: " << std::hex << static_cast<int>(emulator.GetPCValue()) << ")" << std::endl;
        // std::cout << "Instruction:\t"       << std::bitset<8>(emulator.GetInstructionMemoryValue(emulator.GetPCValue())) << " (DEC: " << std::dec << static_cast<int>((emulator.GetInstructionMemoryValue(emulator.GetPCValue()))) << ")" << " (HEX: " << std::hex << static_cast<int>(emulator.GetInstructionMemoryValue(emulator.GetPCValue())) << ")" << std::endl;
        // std::cout << "Operation:\t";
        // if (((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 6) & 0b11) == 0b00) // add 
        // {
        //     std::cout << "ADD";
        // }
        // else if (((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 6) & 0b11) == 0b01) // void instruction
        // {
        //     std::cout << "VOID";
        // }
        // else if (((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 6) & 0b11) == 0b10) // load immediate
        // {
        //     std::cout << "LI";
        // }
        // else 
        // {
        //     std::cout << "BNE"; // branch if R0 != RS2;
        // }
        // std::cout << std::endl;

        // std::cout << "RD:\t\t";
        // if (((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 4) & 0b11) == 0b00) 
        // {
        //     std::cout << "R0";
        // }
        // else if (((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 4) & 0b11) == 0b01)
        // {
        //     std::cout << "R1";
        // }
        // else if (((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 4) & 0b11) == 0b10)
        // {
        //     std::cout << "R2";
        // }
        // else 
        // {
        //     std::cout << "R3";
        // }
        // std::cout << std::endl;

        // std::cout << "RS1:\t\t";
        // if (((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 2) & 0b11) == 0b00) 
        // {
        //     std::cout << "R0";
        // }
        // else if (((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 2) & 0b11) == 0b01)
        // {
        //     std::cout << "R1";
        // }
        // else if (((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 2) & 0b11) == 0b10)
        // {
        //     std::cout << "R2";
        // }
        // else 
        // {
        //     std::cout << "R3";
        // }
        // std::cout << std::endl;

        // std::cout << "RS2:\t\t";
        // if ((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) & 0b11) == 0b00) 
        // {
        //     std::cout << "R0";
        // }
        // else if ((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) & 0b11) == 0b01)
        // {
        //     std::cout << "R1";
        // }
        // else if ((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) & 0b11) == 0b10)
        // {
        //     std::cout << "R2";
        // }
        // else 
        // {
        //     std::cout << "R3";
        // }
        // std::cout << std::endl;

        // std::cout << "ADDR:\t\t" << std::bitset<4>((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 2) & 0b1111) << " (DEC: " << std::dec << static_cast<int>((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 2) & 0b1111) << ") (HEX: " << std::hex << static_cast<int>((emulator.GetInstructionMemoryValue(emulator.GetPCValue()) >> 2) & 0b1111) << ")" << std::endl;
        // std::cout << "IMM:\t\t" << std::bitset<4>(emulator.GetInstructionMemoryValue(emulator.GetPCValue()) & 0b1111) << " (DEC: " << std::dec << static_cast<int>(emulator.GetInstructionMemoryValue(emulator.GetPCValue()) & 0b1111) << ") (HEX: " << std::hex << static_cast<int>(emulator.GetInstructionMemoryValue(emulator.GetPCValue()) & 0b1111) << ")" << std::endl;

        // std::cout << "Register 0:\t" << std::hex << std::bitset<8>(emulator.GetRegisterValue(0)) << " (DEC: " << std::dec << static_cast<int>(emulator.GetRegisterValue(0)) << ") (HEX: " << std::hex << static_cast<int>(emulator.GetRegisterValue(0)) << ")" << std::endl;
        // std::cout << "Register 1:\t" << std::hex << std::bitset<8>(emulator.GetRegisterValue(1)) << " (DEC: " << std::dec << static_cast<int>(emulator.GetRegisterValue(1)) << ") (HEX: " << std::hex << static_cast<int>(emulator.GetRegisterValue(1)) << ")" << std::endl;
        // std::cout << "Register 2:\t" << std::hex << std::bitset<8>(emulator.GetRegisterValue(2)) << " (DEC: " << std::dec << static_cast<int>(emulator.GetRegisterValue(2)) << ") (HEX: " << std::hex << static_cast<int>(emulator.GetRegisterValue(2)) << ")" << std::endl;
        // std::cout << "Register 3:\t" << std::hex << std::bitset<8>(emulator.GetRegisterValue(3)) << " (DEC: " << std::dec << static_cast<int>(emulator.GetRegisterValue(3)) << ") (HEX: " << std::hex << static_cast<int>(emulator.GetRegisterValue(3)) << ")" << std::endl << std::endl;
        
        registerFile << std::bitset<8>(emulator.GetRegisterValue(0));
        registerFile << std::bitset<8>(emulator.GetRegisterValue(1));
        registerFile << std::bitset<8>(emulator.GetRegisterValue(2));
        registerFile << std::bitset<8>(emulator.GetRegisterValue(3));

        pcOutFile << std::bitset<4>(emulator.GetPCValue()); 
        emulator.Step();
    }

    pcOutFile.close();
    registerFile.close();
    return 0;
}