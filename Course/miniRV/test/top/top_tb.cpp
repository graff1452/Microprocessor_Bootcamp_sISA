#include <iostream>
#include <cstdint>
#include <bitset>
#include <fstream>
#include "verilated.h"
#include "Vtop.h"
#include <filesystem>

#define NUM_CYCLES 142014

static void tick(Vtop* dut)
{
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
}

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vtop* top = new Vtop;

    std::ofstream pcOutFile(std::filesystem::current_path() / "emulator" / "txt" / "top_module_pc.txt");
    if (!pcOutFile.is_open()) 
    {
        std::cerr << "Error: Could not open file golden_model_pc.txt for writing." << std::endl;
        return 1;
    }

    std::ofstream registerOutFile(std::filesystem::current_path() / "emulator" / "txt" / "top_module_register.txt");
    if (!registerOutFile.is_open()) 
    {
        std::cerr << "Error: Could not open file golden_model_instruction.txt for writing." << std::endl;
        return 1;
    }

    std::ofstream instructionOutFile(std::filesystem::current_path() / "emulator" / "txt" / "top_module_instruction.txt");
    if (!instructionOutFile.is_open()) 
    {
        std::cerr << "Error: Could not open file golden_model_register.txt for writing." << std::endl;
        return 1;
    }

    top->clk = 0;
    top->rst = 1;
    top->eval();

    tick(top);
    tick(top);

    top->rst = 0;
    top->eval();

    for (int cycle = 0; cycle < NUM_CYCLES; cycle++)
    {
        instructionOutFile << std::bitset<32>(top->instruction);
        registerOutFile << std::bitset<32>(top->reg0_val);
        registerOutFile << std::bitset<32>(top->reg1_val);
        registerOutFile << std::bitset<32>(top->reg2_val);
        registerOutFile << std::bitset<32>(top->reg3_val);
        registerOutFile << std::bitset<32>(top->reg4_val);
        registerOutFile << std::bitset<32>(top->reg5_val);
        registerOutFile << std::bitset<32>(top->reg6_val);
        registerOutFile << std::bitset<32>(top->reg7_val);
        registerOutFile << std::bitset<32>(top->reg8_val);
        registerOutFile << std::bitset<32>(top->reg9_val);
        registerOutFile << std::bitset<32>(top->reg10_val);
        registerOutFile << std::bitset<32>(top->reg11_val);
        registerOutFile << std::bitset<32>(top->reg12_val);
        registerOutFile << std::bitset<32>(top->reg13_val);
        registerOutFile << std::bitset<32>(top->reg14_val);
        registerOutFile << std::bitset<32>(top->reg15_val);
        pcOutFile << std::bitset<32>(top->pc_out);
        // std::cout
        //     << "Cycle " << cycle << "\n"

        //     << "PC\t\t= "
        //     << std::bitset<32>(top->pc_out)
        //     << " (DEC: " << std::dec << (uint32_t)top->pc_out
        //     << ") (HEX: 0x" << std::hex << (uint32_t)top->pc_out << std::dec << ")\n"

        //     << "Instruction\t= "
        //     << std::bitset<32>(top->instruction)
        //     << " (HEX: 0x" << std::hex << (uint32_t)top->instruction << std::dec << ")\n"

        //     << "x0  = " << std::bitset<32>(top->reg0_val)
        //     << " (DEC: " << std::dec << (uint32_t)top->reg0_val
        //     << ") (HEX: 0x" << std::hex << (uint32_t)top->reg0_val << std::dec << ")\n"

        //     << "x1  = " << std::bitset<32>(top->reg1_val)
        //     << " (DEC: " << std::dec << (uint32_t)top->reg1_val
        //     << ") (HEX: 0x" << std::hex << (uint32_t)top->reg1_val << std::dec << ")\n"

        //     << "x2  = " << std::bitset<32>(top->reg2_val)
        //     << " (DEC: " << std::dec << (uint32_t)top->reg2_val
        //     << ") (HEX: 0x" << std::hex << (uint32_t)top->reg2_val << std::dec << ")\n"

        //     << "x3  = " << std::bitset<32>(top->reg3_val)
        //     << " (DEC: " << std::dec << (uint32_t)top->reg3_val
        //     << ") (HEX: 0x" << std::hex << (uint32_t)top->reg3_val << std::dec << ")\n"

        //     << "x4  = " << std::bitset<32>(top->reg4_val)
        //     << " (DEC: " << std::dec << (uint32_t)top->reg4_val
        //     << ") (HEX: 0x" << std::hex << (uint32_t)top->reg4_val << std::dec << ")\n"

        //     << "x5  = " << std::bitset<32>(top->reg5_val)
        //     << " (DEC: " << std::dec << (uint32_t)top->reg5_val
        //     << ") (HEX: 0x" << std::hex << (uint32_t)top->reg5_val << std::dec << ")\n"

        //     << "x6  = " << std::bitset<32>(top->reg6_val)
        //     << " (DEC: " << std::dec << (uint32_t)top->reg6_val
        //     << ") (HEX: 0x" << std::hex << (uint32_t)top->reg6_val << std::dec << ")\n"

        //     << "x7  = " << std::bitset<32>(top->reg7_val)
        //     << " (DEC: " << std::dec << (uint32_t)top->reg7_val
        //     << ") (HEX: 0x" << std::hex << (uint32_t)top->reg7_val << std::dec << ")\n"

        //     << "x8  = " << std::bitset<32>(top->reg8_val)
        //     << " (DEC: " << std::dec << (uint32_t)top->reg8_val
        //     << ") (HEX: 0x" << std::hex << (uint32_t)top->reg8_val << std::dec << ")\n"

        //     << "x9  = " << std::bitset<32>(top->reg9_val)
        //     << " (DEC: " << std::dec << (uint32_t)top->reg9_val
        //     << ") (HEX: 0x" << std::hex << (uint32_t)top->reg9_val << std::dec << ")\n"

        //     << "x10 = " << std::bitset<32>(top->reg10_val)
        //     << " (DEC: " << std::dec << (uint32_t)top->reg10_val
        //     << ") (HEX: 0x" << std::hex << (uint32_t)top->reg10_val << std::dec << ")\n"

        //     << "x11 = " << std::bitset<32>(top->reg11_val)
        //     << " (DEC: " << std::dec << (uint32_t)top->reg11_val
        //     << ") (HEX: 0x" << std::hex << (uint32_t)top->reg11_val << std::dec << ")\n"

        //     << "x12 = " << std::bitset<32>(top->reg12_val)
        //     << " (DEC: " << std::dec << (uint32_t)top->reg12_val
        //     << ") (HEX: 0x" << std::hex << (uint32_t)top->reg12_val << std::dec << ")\n"

        //     << "x13 = " << std::bitset<32>(top->reg13_val)
        //     << " (DEC: " << std::dec << (uint32_t)top->reg13_val
        //     << ") (HEX: 0x" << std::hex << (uint32_t)top->reg13_val << std::dec << ")\n"

        //     << "x14 = " << std::bitset<32>(top->reg14_val)
        //     << " (DEC: " << std::dec << (uint32_t)top->reg14_val
        //     << ") (HEX: 0x" << std::hex << (uint32_t)top->reg14_val << std::dec << ")\n"

        //     << "x15 = " << std::bitset<32>(top->reg15_val)
        //     << " (DEC: " << std::dec << (uint32_t)top->reg15_val
        //     << ") (HEX: 0x" << std::hex << (uint32_t)top->reg15_val << std::dec << ")\n"

        //     << std::endl;

        tick(top);

        if (Verilated::gotFinish())
            break;
    }

    std::cout << "top Testbench completed." << std::endl;
    delete top;
    return 0;
}
