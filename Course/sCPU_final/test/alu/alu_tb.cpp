#include <iostream>
#include <ctime>
#include <cstdint>
#include <bitset>
#include "Valu.h"
#include "verilated.h" 
#include <cstdlib>

#define NUM_TESTS 1000000

int main(int argc, char** argv) 
{
    Verilated::commandArgs(argc, argv);
    Valu* alu = new Valu;
    std::srand(std::time(nullptr));
    uint8_t     A;
    uint8_t     B;
    uint8_t     imm;
    uint8_t     reg0_val;
    int         add;

    uint8_t     ALU_out;
    int         equal;

    uint8_t adder_8bits_out;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        A           = rand() & 0xFF;
        B           = rand() & 0xFF;
        imm         = rand() & 0x0F;
        reg0_val    = rand() & 0xFF;
        add         = rand() % 2;

        alu->A = A;
        alu->B = B;
        alu->imm = imm;
        alu->reg0_val = reg0_val;
        alu->add = add;
        alu->eval();

        adder_8bits_out = A + B;
        if (add == 0)
        {
            ALU_out = imm;
        }
        else 
        {
            ALU_out = adder_8bits_out;
        }

        if (B == reg0_val)
        {
            equal = 1;
        }
        else 
        {
            equal = 0;
        }

        if (ALU_out != alu->ALU_out || equal != alu->equal)
        {
            std::cout << "testN"    << test
            <<  " Mismatch "
            <<  " A="               << std::bitset<8>(A)
            <<  " B="               << std::bitset<8>(B)
            <<  " imm="             << std::bitset<4>(imm)
            <<  " reg0_val="        << std::bitset<8>(reg0_val)
            <<  " add="             << std::bitset<1>(add) 
            <<  " Expected:"   
            <<  " ALU_out="          << std::bitset<8>(ALU_out) 
            <<  " equal="            << std::bitset<1>(equal) 
            <<  " Got:"
            <<  " ALU_out="          << std::bitset<8>(alu->ALU_out) 
            <<  " equal="            << std::bitset<1>(alu->equal) 
            << std::endl;
        }
    }
    std::cout << "alu Testbench completed." << std::endl;
    delete alu;
    return 0;
}