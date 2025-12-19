#include <iostream>
#include <ctime>
#include <cstdint>
#include <cstdlib>
#include "verilated.h"
#include "Vmux_4to1_8bits.h"
#include <bitset>

#define NUM_TESTS 1000000

int main (int argc, char** argv) 
{
    Verilated::commandArgs(argc, argv);
    Vmux_4to1_8bits* mux_4to1_8bits = new Vmux_4to1_8bits;

    std::srand(std::time(nullptr));

    u_int8_t mux_4to1_8bits_out;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        uint8_t in0 = rand() & 0xFF;
        uint8_t in1 = rand() & 0xFF;
        uint8_t in2 = rand() & 0xFF;
        uint8_t in3 = rand() & 0xFF;
        uint8_t sel = (rand() >> 6) & 0b11;

        switch (sel)
        {
            case 0b00: mux_4to1_8bits_out = in0; break;
            case 0b01: mux_4to1_8bits_out = in1; break;
            case 0b10: mux_4to1_8bits_out = in2; break;
            case 0b11: mux_4to1_8bits_out = in3; break;
            default:  mux_4to1_8bits_out = 0;
        }

        mux_4to1_8bits->in0    = in0;
        mux_4to1_8bits->in1    = in1;
        mux_4to1_8bits->in2    = in2;
        mux_4to1_8bits->in3    = in3;
        mux_4to1_8bits->sel    = sel;
        mux_4to1_8bits->eval();

        if (mux_4to1_8bits_out != mux_4to1_8bits->mux_out)
        {
            std::cout << "testN" << test
            <<  " Mismatch "
            <<  " in0="         << std::bitset<8>(in0) 
            <<  " in1="         << std::bitset<8>(in1)
            <<  " in2="         << std::bitset<8>(in2)
            <<  " in3="         << std::bitset<8>(in3)
            <<  " sel="         << std::bitset<4>(sel)
            <<  " Expected="    << std::bitset<8>(mux_4to1_8bits_out)
            <<  " Got="         << std::bitset<8>(mux_4to1_8bits->mux_out)
            << std::endl;
        }
    }

    std::cout << "mux_4to1_8bits Testbench completed." << std::endl;
    delete mux_4to1_8bits;
    return 0;
}