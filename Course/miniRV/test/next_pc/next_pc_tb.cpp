#include <iostream>
#include <ctime>
#include <cstdint>
#include <cstdlib>
#include "verilated.h"
#include "Vnext_pc.h"
#include <bitset>

#define NUM_TESTS 1000000

int main (int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vnext_pc* next_pc = new Vnext_pc;

    std::srand(std::time(nullptr));

    uint32_t pc_next;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        uint32_t pc_plus_4 = rand() & 0xFFFF;
        uint32_t y         = rand() & 0xFFFF;
        uint32_t jalr      = rand() & 0x1;

        // Compute expected (match RTL exactly)
        if (jalr)
            pc_next = y & 0xFFFF'FFFC;   // mask low 2 bits
        else
            pc_next = pc_plus_4;

        // Drive DUT
        next_pc->pc_plus_4 = pc_plus_4;
        next_pc->y         = y;
        next_pc->jalr      = jalr;
        next_pc->eval();

        if (pc_next != next_pc->pc_next)
        {
            std::cout << "testN" << test
                      << " Mismatch "
                      << " pc_plus_4=" << std::bitset<32>(pc_plus_4)
                      << " y="         << std::bitset<32>(y)
                      << " jalr="      << std::bitset<1>(jalr)
                      << " Expected="  << std::bitset<32>(pc_next)
                      << " Got="       << std::bitset<32>(next_pc->pc_next)
                      << std::endl;

            // Optional: stop on first failure
            delete next_pc;
            return 1;
        }
    }

    std::cout << "next_pc Testbench completed." << std::endl;
    delete next_pc;
    return 0;
}
