#include <iostream>
#include <ctime>
#include <cstdint>
#include <bitset>
#include "Vcomparator_8bits.h"
#include "verilated.h" 
#include <cstdlib>

#define NUM_TESTS 1000000

int main(int argc, char** argv) 
{
    Verilated::commandArgs(argc, argv);
    Vcomparator_8bits* comparator_8bits = new Vcomparator_8bits;
    std::srand(std::time(nullptr));
    uint8_t     A;
    uint8_t     B;
    int         equal;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        A = rand() & 0xFF;
        B = rand() & 0xFF;
        comparator_8bits->A = A;
        comparator_8bits->B = B;
        comparator_8bits->eval();

        if (A == B) 
        {
            equal = 1;
        }
        else 
        {
            equal = 0;
        }

        if (equal != comparator_8bits->equal)
        {
            std::cout << "testN" << test
            <<  " Mismatch "
            <<  " A="           << std::bitset<8>(A)
            <<  " B="           << std::bitset<8>(B) 
            <<  " Expected="    << std::bitset<1>(equal)
            <<  " Got="         << std::bitset<1>(comparator_8bits->equal)
            << std::endl;
        }
    }
    std::cout << "comparator_8bits Testbench completed." << std::endl;
    delete comparator_8bits;
    return 0;
}