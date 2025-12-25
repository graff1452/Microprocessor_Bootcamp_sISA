#include <iostream>
#include <ctime>
#include <cstdint>
#include <cstdlib>
#include "verilated.h"
#include "Vpc_plus_4.h"
#include <bitset>

#define NUM_TESTS 1000000

int main (int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vpc_plus_4* pc_plus_4 = new Vpc_plus_4;

    std::srand(std::time(nullptr));

    uint32_t pc;
    uint32_t pc_plus_4_out;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        pc = rand() & 0xFFFFFFFF;

        pc_plus_4_out = pc + 4;

        // Drive DUT
        pc_plus_4->pc = pc;
        pc_plus_4->eval();

        if (pc_plus_4_out != pc_plus_4->pc_plus_4_out)
        {
            std::cout << "testN" << test
                      << " Mismatch "
                      << " pc="       << std::bitset<32>(pc)
                      << " Expected=" << std::bitset<32>(pc_plus_4_out)
                      << " Got="      << std::bitset<32>(pc_plus_4->pc_plus_4_out)
                      << std::endl;

            // Optional: stop on first failure
            delete pc_plus_4;
            return 1;
        }
    }

    std::cout << "pc_plus_4 Testbench completed." << std::endl;
    delete pc_plus_4;
    return 0;
}
