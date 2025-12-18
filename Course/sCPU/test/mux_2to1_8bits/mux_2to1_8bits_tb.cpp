#include <iostream>
#include <ctime>
#include <cstdint>
#include <cstdlib>
#include "verilated.h"
#include "Vmux_2to1_8bits.h"
#include <bitset>

#define NUM_TESTS 1000000

int main (int argc, char** argv) 
{
    Verilated::commandArgs(argc, argv);
    Vmux_2to1_8bits* mux_2to1_8bits = new Vmux_2to1_8bits;

    std::srand(std::time(nullptr));

    uint8_t mux_2to1_8bits_out;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        uint8_t in0 = rand() & 0xFF;
        uint8_t in1 = rand() & 0xFF;
        uint8_t sel = rand() % 2;

        switch (sel)
        {
            case 0b0: mux_2to1_8bits_out = in0; break;
            case 0b1: mux_2to1_8bits_out = in1; break;
            default:  mux_2to1_8bits_out = 0;
        }

        mux_2to1_8bits->in0 = in0;
        mux_2to1_8bits->in1 = in1;
        mux_2to1_8bits->sel = sel;
        mux_2to1_8bits->eval();

        if (mux_2to1_8bits_out != mux_2to1_8bits->mux_out)
        {
            std::cout << "testN" << test
            <<  " Mismatch "
            <<  " in0="         << std::bitset<4>(in0) 
            <<  " in1="         << std::bitset<4>(in1)
            <<  " sel="         << std::bitset<1>(sel)
            <<  " Expected="    << std::bitset<8>(mux_2to1_8bits_out)
            <<  " Got="         << std::bitset<8>(mux_2to1_8bits->mux_out)
            << std::endl;
        }
    }

    std::cout << "mux_2to1_8bits Testbench completed." << std::endl;
    delete mux_2to1_8bits;
    return 0;
}