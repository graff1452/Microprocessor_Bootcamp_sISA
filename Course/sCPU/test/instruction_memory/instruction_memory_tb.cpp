#include <iostream>
#include <ctime>
#include <cstdint>
#include <bitset>
#include "Vinstruction_memory.h"
#include "verilated.h" 
#include <cstdlib>

#define NUM_TESTS 1000000

int main(int argc, char** argv) 
{
    Verilated::commandArgs(argc, argv);
    Vinstruction_memory* instruction_memory = new Vinstruction_memory;
    std::srand(std::time(nullptr));
    uint8_t sel;
    uint8_t instruction;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        sel = rand() & 0x0F;
        instruction_memory->sel = sel;
        instruction_memory->eval();
        switch (sel)
        {
            case 0x00:  instruction = 0b10001010; break;
            case 0x01:  instruction = 0b10010000; break;
            case 0x02:  instruction = 0b10100000; break;
            case 0x03:  instruction = 0b10110001; break;
            case 0x04:  instruction = 0b00010111; break;
            case 0x05:  instruction = 0b00101001; break;
            case 0x06:  instruction = 0b11010001; break;
            case 0x07:  instruction = 0b11011111; break;
            default:    instruction = 0;
        }

        if (instruction != instruction_memory->instruction)
        {
            std::cout << "testN" << test
            <<  " Mismatch "
            <<  " sel="         << std::bitset<4>(sel) 
            <<  " Expected="    << std::bitset<8>(instruction)
            <<  " Got="         << std::bitset<8>(instruction_memory->instruction)
            << std::endl;
        }
    }
    std::cout << "Instruction memory Testbench completed." << std::endl;
    delete instruction_memory;
    return 0;
}