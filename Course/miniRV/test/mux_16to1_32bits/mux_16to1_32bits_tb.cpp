#include <iostream>
#include <ctime>
#include <cstdint>
#include <cstdlib>
#include "verilated.h"
#include "Vmux_16to1_32bits.h"
#include <bitset>

#define NUM_TESTS 1000000

int main (int argc, char** argv) 
{
    Verilated::commandArgs(argc, argv);
    Vmux_16to1_32bits* mux_16to1_32bits = new Vmux_16to1_32bits;

    std::srand(std::time(nullptr));

    uint32_t mux_16to1_32bits_out;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        uint32_t in0 = rand()   & 0xFFFF;
        uint32_t in1 = rand()   & 0xFFFF;
        uint32_t in2 = rand()   & 0xFFFF;
        uint32_t in3 = rand()   & 0xFFFF;
        uint32_t in4 = rand()   & 0xFFFF;
        uint32_t in5 = rand()   & 0xFFFF;
        uint32_t in6 = rand()   & 0xFFFF;
        uint32_t in7 = rand()   & 0xFFFF;
        uint32_t in8 = rand()   & 0xFFFF;
        uint32_t in9 = rand()   & 0xFFFF;
        uint32_t in10 = rand()  & 0xFFFF;
        uint32_t in11 = rand()  & 0xFFFF;
        uint32_t in12 = rand()  & 0xFFFF;
        uint32_t in13 = rand()  & 0xFFFF;
        uint32_t in14 = rand()  & 0xFFFF;
        uint32_t in15 = rand()  & 0xFFFF;
        uint32_t sel = rand()   & 0b1111;

        switch (sel)
        {
            case 0x0: mux_16to1_32bits_out = in0; break;
            case 0x1: mux_16to1_32bits_out = in1; break;
            case 0x2: mux_16to1_32bits_out = in2; break;
            case 0x3: mux_16to1_32bits_out = in3; break;
            case 0x4: mux_16to1_32bits_out = in4; break;
            case 0x5: mux_16to1_32bits_out = in5; break;
            case 0x6: mux_16to1_32bits_out = in6; break;
            case 0x7: mux_16to1_32bits_out = in7; break;
            case 0x8: mux_16to1_32bits_out = in8; break;
            case 0x9: mux_16to1_32bits_out = in9; break;
            case 0xA: mux_16to1_32bits_out = in10; break;
            case 0xB: mux_16to1_32bits_out = in11; break;
            case 0xC: mux_16to1_32bits_out = in12; break;
            case 0xD: mux_16to1_32bits_out = in13; break;
            case 0xE: mux_16to1_32bits_out = in14; break;
            case 0xF: mux_16to1_32bits_out = in15; break;
            default:  mux_16to1_32bits_out = 0;
        }

        mux_16to1_32bits->in0    = in0;
        mux_16to1_32bits->in1    = in1;
        mux_16to1_32bits->in2    = in2;
        mux_16to1_32bits->in3    = in3;
        mux_16to1_32bits->in4    = in4;
        mux_16to1_32bits->in5    = in5;
        mux_16to1_32bits->in6    = in6;
        mux_16to1_32bits->in7    = in7;
        mux_16to1_32bits->in8    = in8;
        mux_16to1_32bits->in9    = in9;
        mux_16to1_32bits->in10   = in10;
        mux_16to1_32bits->in11   = in11;
        mux_16to1_32bits->in12   = in12;
        mux_16to1_32bits->in13   = in13;
        mux_16to1_32bits->in14   = in14;
        mux_16to1_32bits->in15   = in15;
        mux_16to1_32bits->sel    = sel;
        mux_16to1_32bits->eval();

        if (mux_16to1_32bits_out != mux_16to1_32bits->mux_out)
        {
            std::cout << "testN" << test
            <<  " Mismatch "
            <<  " in0="         << std::bitset<32>(in0) 
            <<  " in1="         << std::bitset<32>(in1)
            <<  " in2="         << std::bitset<32>(in2)
            <<  " in3="         << std::bitset<32>(in3)
            <<  " in4="         << std::bitset<32>(in4)
            <<  " in5="         << std::bitset<32>(in5)
            <<  " in6="         << std::bitset<32>(in6)
            <<  " in7="         << std::bitset<32>(in7)
            <<  " in8="         << std::bitset<32>(in8) 
            <<  " in9="         << std::bitset<32>(in9)
            <<  " in10="        << std::bitset<32>(in10)
            <<  " in11="        << std::bitset<32>(in11)
            <<  " in12="        << std::bitset<32>(in12)
            <<  " in13="        << std::bitset<32>(in13)
            <<  " in14="        << std::bitset<32>(in14)
            <<  " in15="        << std::bitset<32>(in15)
            <<  " sel="         << std::bitset<4>(sel)
            <<  " Expected="    << std::bitset<32>(mux_16to1_32bits_out)
            <<  " Got="         << std::bitset<32>(mux_16to1_32bits->mux_out)
            << std::endl;
        }
    }

    std::cout << "mux_16to1_32bits Testbench completed." << std::endl;
    delete mux_16to1_32bits;
    return 0;
}