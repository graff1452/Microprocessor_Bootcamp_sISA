#include <iostream>
#include "verilated.h"
#include "Vregister_32bits.h"
#include <cstdlib>
#include <cstdint>
#include <ctime>
#include <bitset>

#define NUM_TESTS 1000000 // Number of tests

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vregister_32bits* register_32bits = new Vregister_32bits; // Creating register

    std::srand(std::time(nullptr));  // Seed for random values

    uint32_t D;
    int enable;
    int clk;
    int rst;
    uint32_t reg_out;
    for (int test = 0; test < NUM_TESTS; test++)
    {
        D = std::rand() & 0xFFFFFFFF;
        rst = std::rand() % 2;
        enable = std::rand() % 2;

        register_32bits->D = D; // Ensuring tests only in rising edge of the cloak
        register_32bits->rst = rst;
        register_32bits->enable = enable;
        
        register_32bits->clk = 0;
        register_32bits->eval();
        register_32bits->clk = 1;
        register_32bits->eval();
        
        if (rst) {reg_out = 0x0;}
        else if (enable) {reg_out = D;}

        if (reg_out != register_32bits->reg_out) // Finding Mismatches
        {
            std::cout << "testN" << test
            <<" Mismatch "
            << " D="        << std::bitset<32>(D) 
            << " rst="      << std::bitset<1>(rst) 
            << " enable="   << std::bitset<1>(enable) 
            << " Expected=" << std::bitset<32>(reg_out)
            << " Got="      << std::bitset<32>(register_32bits->reg_out)
            << std::endl;
        }
    }

    std::cout << "register_32bits Testbench completed." << std::endl;
    delete register_32bits;
    return 0;
}