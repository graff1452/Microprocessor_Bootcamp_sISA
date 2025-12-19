#include <iostream>
#include "verilated.h"
#include "Vregister_8bits.h"
#include <cstdlib>
#include <cstdint>
#include <ctime>
#include <bitset>

#define NUM_TESTS 1000000 // Number of tests

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vregister_8bits* register_8bits = new Vregister_8bits; // Creating register

    std::srand(std::time(nullptr));  // Seed for random values

    uint8_t D;
    int enable;
    int clk;
    int rst;
    uint8_t reg_out;
    for (int test = 0; test < NUM_TESTS; test++)
    {
        D = std::rand() & 0xFF;
        rst = std::rand() % 2;
        enable = std::rand() % 2;

        register_8bits->D = D; // Ensuring tests only in rising edge of the cloak
        register_8bits->rst = rst;
        register_8bits->enable = enable;
        
        register_8bits->clk = 0;
        register_8bits->eval();
        register_8bits->clk = 1;
        register_8bits->eval();
        
        if (rst) {reg_out = 0x00;}
        else if (enable) {reg_out = D;}

        if (reg_out != register_8bits->reg_out) // Finding Mismatches
        {
            std::cout << "testN" << test
            <<" Mismatch "
            << " D="        << std::bitset<8>(D) 
            << " rst="      << std::bitset<1>(rst) 
            << " enable="   << std::bitset<1>(enable) 
            << " Expected=" << std::bitset<8>(reg_out)
            << " Got="      << std::bitset<8>(register_8bits->reg_out)
            << std::endl;
        }
    }

    std::cout << "register_8bits Testbench completed." << std::endl;
    delete register_8bits;
    return 0;
}