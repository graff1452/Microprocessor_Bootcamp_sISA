#include <iostream>
#include <ctime>
#include <cstdint>
#include <bitset>
#include "Vadder_4bits.h"
#include "verilated.h" 
#include <cstdlib>

#define NUM_TESTS 1000000

int main(int argc, char** argv) 
{
    Verilated::commandArgs(argc, argv);
    Vadder_4bits* adder_4bits = new Vadder_4bits;
    std::srand(std::time(nullptr));
    uint8_t    A;
    uint8_t    B;
    uint8_t    Sum;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        A = (rand() >> 4) & 0x0F;
        B = (rand() >> 4) & 0x0F;
        Sum = A + B;
        adder_4bits->A = A;
        adder_4bits->B = B;
        adder_4bits->eval();

        if ((Sum & 0x0F) != (adder_4bits->Sum & 0x0F))
        {
            std::cout << "testN" << test
            <<  " Mismatch "
            <<  " A="           << std::bitset<4>(A)
            <<  " B="           << std::bitset<4>(B) 
            <<  " Expected="    << std::bitset<4>(Sum)
            <<  " Got="         << std::bitset<4>(adder_4bits->Sum)
            << std::endl;
        }
    }
    std::cout << "adder_4bits Testbench completed." << std::endl;
    delete adder_4bits;
    return 0;
}