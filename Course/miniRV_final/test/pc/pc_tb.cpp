#include <iostream>
#include "Vpc.h"
#include "verilated.h"
#include <bitset>
#include <ctime>
#include <cstdint>
#include <cstdlib>

#define NUM_TESTS 1000000

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vpc* pc = new Vpc;

    std::srand(std::time(nullptr));

    for (int test = 0; test < NUM_TESTS; test++)
    {
        uint32_t D = rand() & 0xFFFFFFFF;
        int enable = rand() % 2;
        int rst = rand() % 2;
        uint32_t pc_out;

        pc->D = D;
        pc->enable = enable;
        pc->rst = rst;
        pc->clk = 0;
        pc->eval();
        pc->clk = 1;
        pc->eval();

        if (rst) 
        {
            pc_out = 0;
        }
        else 
        {
            if (enable) 
            {
                pc_out = D;
            }
        }

        if (pc->pc_out != pc_out)
        {
            std::cout << "testN" << test
            <<  " Mismatch "
            <<  " D="           << std::bitset<32>(D) 
            <<  " enable="      << std::bitset<1>(enable) 
            <<  " rst="         << std::bitset<1>(rst) 
            <<  " Expected="    << std::bitset<32>(pc_out)
            <<  " Got="         << std::bitset<32>(pc->pc_out)
            << std::endl;
        }
    }

    std::cout << "PC Testbench completed." << std::endl;

    delete pc;
    return 0;
}
