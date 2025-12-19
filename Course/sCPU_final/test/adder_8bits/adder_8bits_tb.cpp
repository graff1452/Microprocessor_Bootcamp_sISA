#include <iostream>
#include <ctime>
#include <cstdint>
#include <bitset>
#include "Vadder_8bits.h"
#include "verilated.h" 
#include <cstdlib>

#define NUM_TESTS 1000000

int main(int argc, char** argv) 
{
    Verilated::commandArgs(argc, argv);
    Vadder_8bits* adder_8bits = new Vadder_8bits;
    std::srand(std::time(nullptr));
    uint8_t    A;
    uint8_t    B;
    uint8_t    Sum;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        A = rand() & 0xFF;
        B = rand() & 0xFF;
        Sum = A + B;
        adder_8bits->A = A;
        adder_8bits->B = B;
        adder_8bits->eval();

        if ((Sum & 0xFF) != (adder_8bits->Sum & 0xFF))
        {
            std::cout << "testN" << test
            <<  " Mismatch "
            <<  " A="           << std::bitset<4>(A)
            <<  " B="           << std::bitset<4>(B) 
            <<  " Expected="    << std::bitset<4>(Sum)
            <<  " Got="         << std::bitset<4>(adder_8bits->Sum)
            << std::endl;
        }
    }
    std::cout << "adder_8bits Testbench completed." << std::endl;
    delete adder_8bits;
    return 0;
}