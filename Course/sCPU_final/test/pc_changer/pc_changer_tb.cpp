#include <iostream>
#include "verilated.h"
#include "Vpc_changer.h"
#include <cstdlib>
#include <cstdint>
#include <ctime>
#include <bitset>

#define NUM_TESTS 1000000 // Number of tests

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vpc_changer* pc_changer = new Vpc_changer; // Creating register

    std::srand(std::time(nullptr));  // Seed for random values

    uint8_t PC;
    int add;
    int li;
    uint8_t addr;
    int equal;
    int empty_inst;
    uint8_t changer_out;

    uint8_t adder_4bits_1_out;
    uint8_t mux_2to1_4bits_1_out;
    uint8_t mux_2to1_4bits_2_out;
    for (int test = 0; test < NUM_TESTS; test++)
    {
        PC          = (rand() >> 4) & 0x0F;
        add         = rand() % 2;
        li          = rand() % 2;
        addr        = (rand() >> 4) & 0x0F;
        equal       = rand() % 2;
        empty_inst  = rand() % 2;

        pc_changer->PC = PC;
        pc_changer->add = add;
        pc_changer->li = li;
        pc_changer->addr = addr;
        pc_changer->equal = equal;
        pc_changer->empty_inst = empty_inst;
        pc_changer->eval();

        adder_4bits_1_out = PC + 1;

        if (equal == 0)
        {
            mux_2to1_4bits_2_out = addr;
        }
        else 
        {
            mux_2to1_4bits_2_out = adder_4bits_1_out;
        }

        if (add == 0 && li == 0) 
        {
            mux_2to1_4bits_1_out = mux_2to1_4bits_2_out;
        }   
        else
        {
            mux_2to1_4bits_1_out = adder_4bits_1_out;
        }

        if (empty_inst == 0)
        {
            changer_out = mux_2to1_4bits_1_out;
        }
        else 
        {
            changer_out = adder_4bits_1_out;
        }

        if ((changer_out & 0x0F) != (pc_changer->changer_out & 0x0F)) // Finding Mismatches
        {
            std::cout << "testN"    << test
            <<" Mismatch "
            << " PC="               << std::bitset<4>(PC) 
            << " add="              << std::bitset<1>(add) 
            << " li="               << std::bitset<1>(li)
            << " addr="             << std::bitset<4>(addr)
            << " equal="            << std::bitset<1>(equal)
            << " empty_inst="       << std::bitset<1>(empty_inst)
            << " Expected="         << std::bitset<4>(changer_out)
            << " Got="              << std::bitset<4>(pc_changer->changer_out)
            << std::endl;
        }
    }

    std::cout << "pc_changer Testbench completed." << std::endl;
    delete pc_changer;
    return 0;
}