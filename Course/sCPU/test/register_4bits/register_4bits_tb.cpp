#include <iostream>
#include "verilated.h"
#include "Vregister_4bits.h"
#include <cstdlib>
#include <cstdint>
#include <ctime>
#include <bitset>

#define NUM_TESTS 1000000 // Number of tests

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vregister_4bits* register_4bits = new Vregister_4bits; // Creating register

    std::srand(std::time(nullptr));  // Seed for random values

    uint8_t D;
    int WE;
    int clk;
    int rst;
    uint8_t Q;
    for (int test = 0; test < NUM_TESTS; test++)
    {
        D = std::rand() & 0x0F;
        rst = std::rand() % 2;
        WE = std::rand() % 2;

        register_4bits->D = D; // Ensuring tests only in rising edge of the cloak
        register_4bits->rst = rst;
        register_4bits->WE = WE;
        
        register_4bits->clk = 0;
        register_4bits->eval();
        register_4bits->clk = 1;
        register_4bits->eval();
        
        if (rst) {Q = 0x00;}
        else if (WE) {Q = D;}

        if (Q != register_4bits->Q) // Finding Mismatches
        {
            std::cout << "testN" << test
            <<" Mismatch "
            << " D="        << std::bitset<4>(D) 
            << " rst="      << std::bitset<1>(rst) 
            << " WE="       << std::bitset<1>(WE) 
            << " Expected=" << std::bitset<4>(Q)
            << " Got="      << std::bitset<4>(register_4bits->Q)
            << std::endl;
        }
    }

    std::cout << "register_4bits Testbench completed." << std::endl;
    delete register_4bits;
    return 0;
}