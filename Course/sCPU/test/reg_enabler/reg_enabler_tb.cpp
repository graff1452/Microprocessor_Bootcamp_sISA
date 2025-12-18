#include <iostream>
#include "verilated.h"
#include "Vreg_enabler.h"
#include <cstdlib>
#include <cstdint>
#include <ctime>
#include <bitset>

#define NUM_TESTS 1000000 // Number of tests

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vreg_enabler* reg_enabler = new Vreg_enabler; // Creating register

    std::srand(std::time(nullptr));  // Seed for random values

    uint8_t rd;
    int bne;

    int reg0_en;
    int reg1_en;
    int reg2_en;
    int reg3_en;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        rd  = rand() & 0b11;
        bne = rand() % 2;

        reg_enabler->rd = rd;
        reg_enabler->bne = bne;
        reg_enabler->eval();

        reg0_en = 0;
        reg1_en = 0;
        reg2_en = 0;
        reg3_en = 0;

        if (bne == 0)
        {
            if (rd == 0b00)
            {
                reg0_en = 1;
            }
            else if (rd == 0b01) 
            {
                reg1_en = 1;
            }
            else if (rd == 0b10) 
            {
                reg2_en = 1;
            }
            else 
            {
                reg3_en = 1;
            }
        }

        if (reg0_en != reg_enabler->reg0_en ||
            reg1_en != reg_enabler->reg1_en ||
            reg2_en != reg_enabler->reg2_en ||
            reg3_en != reg_enabler->reg3_en) // Finding Mismatches
        {
            std::cout << "testN"    << test
            <<" Mismatch "
            << " rd="               << std::bitset<2>(rd) 
            << " bne="              << std::bitset<1>(bne)  
            << " Expected:"
            << " reg0_en="          << std::bitset<1>(reg0_en)
            << " reg1_en="          << std::bitset<1>(reg1_en)
            << " reg2_en="          << std::bitset<1>(reg2_en)
            << " reg3_en="          << std::bitset<1>(reg3_en)
            << " Got:"
            << " reg0_en="          << std::bitset<1>(reg_enabler->reg0_en)
            << " reg1_en="          << std::bitset<1>(reg_enabler->reg1_en)
            << " reg2_en="          << std::bitset<1>(reg_enabler->reg2_en)
            << " reg3_en="          << std::bitset<1>(reg_enabler->reg3_en)
            << std::endl;
        }
    }

    std::cout << "reg_enabler Testbench completed." << std::endl;
    delete reg_enabler;
    return 0;
}