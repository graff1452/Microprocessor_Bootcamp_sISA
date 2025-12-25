#include <iostream>
#include <ctime>
#include <cstdint>
#include <cstdlib>
#include "verilated.h"
#include "Valu.h"
#include <bitset>

#define NUM_TESTS 1000000

int main (int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Valu* alu = new Valu;

    std::srand(std::time(nullptr));

    uint32_t y;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        uint32_t a = rand() & 0xFFFF;
        uint32_t b = rand() & 0xFFFF;

        y = a + b;

        alu->a = a;
        alu->b = b;
        alu->eval();

        if (y != alu->y)
        {
            std::cout << "testN" << test
                      << " Mismatch "
                      << " a="        << std::bitset<32>(a)
                      << " b="        << std::bitset<32>(b)
                      << " Expected=" << std::bitset<32>(y)
                      << " Got="      << std::bitset<32>(alu->y)
                      << std::endl;

            // Optional: stop on first failure
            delete alu;
            return 1;
        }
    }

    std::cout << "alu Testbench completed." << std::endl;
    delete alu;
    return 0;
}
