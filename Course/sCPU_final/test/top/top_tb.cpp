#include <iostream>
#include <ctime>
#include <cstdint>
#include <bitset>
#include "Vtop.h"
#include "verilated.h" 
#include <cstdlib>
#include <fstream>

#define NUM_TESTS 1000000

#define PCOUTFILEPATH "/home/graff145/Desktop/Microprocessor_Bootcamp_sISA/Course/sCPU_final/emulator/txt/pc_out_top_module.txt"
#define REGISTERFILEPATH "/home/graff145/Desktop/Microprocessor_Bootcamp_sISA/Course/sCPU_final/emulator/txt/register_top_module.txt"

int main(int argc, char** argv) 
{
    Verilated::commandArgs(argc, argv);
    Vtop* top = new Vtop;
    std::srand(std::time(nullptr));

    std::ofstream pcOutFile(PCOUTFILEPATH);
    if (!pcOutFile.is_open()) {
        std::cerr << "Failed to open PC output file\n";
        return 1;
    }

    std::ofstream registerFile(REGISTERFILEPATH);
    if (!registerFile.is_open()) {
        std::cerr << "Failed to open register output file\n";
        return 1;
    }

    int clk;
    int rst;
    uint8_t reg0_out;
    uint8_t reg1_out;
    uint8_t reg2_out;
    uint8_t reg3_out;
    uint8_t pc_out;
    uint8_t instruction;
    uint8_t alu_out;
    top->clk = 0;
    top->eval();

    for (int test = 0; test < NUM_TESTS; test++) //Uncomment to Debug
    {
        pcOutFile << std::bitset<4>(top->pc_out);
        registerFile << std::bitset<8>(top->reg0_out);
        registerFile << std::bitset<8>(top->reg1_out);
        registerFile << std::bitset<8>(top->reg2_out);
        registerFile << std::bitset<8>(top->reg3_out);
        // std::cout   << "Iteration = "   << test << "\n"
        //             << "reg0_out = " << std::bitset<8>(top->reg0_out) << " (" << static_cast<int>(top->reg0_out) << ")\n"
        //             << "reg1_out = " << std::bitset<8>(top->reg1_out) << " (" << static_cast<int>(top->reg1_out) << ")\n"
        //             << "reg2_out = " << std::bitset<8>(top->reg2_out) << " (" << static_cast<int>(top->reg2_out) << ")\n"
        //             << "reg3_out = " << std::bitset<8>(top->reg3_out) << " (" << static_cast<int>(top->reg3_out) << ")\n"
        //             << "pc_out = "      << std::bitset<4>(top->pc_out)      << " (" << std::dec << static_cast<int>(top->pc_out)   << ")" << "\n"
        //             << "instruction = " << std::bitset<8>(top->instruction) << "\n"
        //             << "alu_out = "     << std::bitset<8>(top->alu_out)     << " (" << std::dec << static_cast<int>(top->alu_out) << ")" << "\n\n";
        top->clk = 0;
        top->eval();
        top->clk = 1;
        top->eval();
    }
    pcOutFile.close();
    registerFile.close();
    std::cout << "top Testbench completed." << std::endl;
    delete top;
    return 0;
}