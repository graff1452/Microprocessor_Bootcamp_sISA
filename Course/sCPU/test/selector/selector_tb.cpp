#include <iostream>
#include <ctime>
#include <cstdint>
#include <bitset>
#include "Vselector.h"
#include "verilated.h" 
#include <cstdlib>

#define NUM_TESTS 1000000

int main(int argc, char** argv) 
{
    Verilated::commandArgs(argc, argv);
    Vselector* selector = new Vselector;
    std::srand(std::time(nullptr));
    uint8_t    rs1;
    uint8_t    rs2;
    uint8_t    reg0_in;
    uint8_t    reg1_in;
    uint8_t    reg2_in;
    uint8_t    reg3_in;
    uint8_t    A;
    uint8_t    B;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        rs1 = (rand() >> 6) & 0b11;
        rs2 = (rand() >> 6) & 0b11;
        reg0_in = rand() & 0xFF;
        reg1_in = rand() & 0xFF;
        reg2_in = rand() & 0xFF;
        reg3_in = rand() & 0xFF;

        selector->rs1 = rs1;
        selector->rs2 = rs2;
        selector->reg0_in = reg0_in;
        selector->reg1_in = reg1_in;
        selector->reg2_in = reg2_in;
        selector->reg3_in = reg3_in;
        selector->eval();

        if (rs1 == 0b00)
        {
            A = reg0_in;
        }
        else if (rs1 == 0b01)
        {
            A = reg1_in;
        }
        else if (rs1 == 0b10)
        {
            A = reg2_in;
        }
        else 
        {
            A = reg3_in;
        }

        if (rs2 == 0b00)
        {
            B = reg0_in;
        }
        else if (rs2 == 0b01)
        {
            B = reg1_in;
        }
        else if (rs2 == 0b10)
        {
            B = reg2_in;
        }
        else 
        {
            B = reg3_in;
        }

        if ((A & 0xFF) != (selector->A & 0xFF) || (B & 0xFF) != (selector->B & 0xFF))
        {
            std::cout << "testN"    << test
            <<  " Mismatch "
            <<  " rs1="             << std::bitset<2>(rs1)
            <<  " rs2="             << std::bitset<2>(rs2)
            <<  " reg0_in="         << std::bitset<8>(reg0_in)
            <<  " reg1_in="         << std::bitset<8>(reg1_in)
            <<  " reg2_in="         << std::bitset<8>(reg2_in)
            <<  " reg3_in="         << std::bitset<8>(reg3_in)
            <<  " Expected:"
            <<  " A="               << std::bitset<8>(A)
            <<  " B="               << std::bitset<8>(B)
            <<  " Got:"
            <<  " A="               << std::bitset<8>(selector->A)
            <<  " B="               << std::bitset<8>(selector->B)
            << std::endl;
        }
    }
    std::cout << "selector Testbench completed." << std::endl;
    delete selector;
    return 0;
}