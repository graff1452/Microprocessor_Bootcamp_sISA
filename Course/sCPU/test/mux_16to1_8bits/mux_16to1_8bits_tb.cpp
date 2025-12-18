#include <iostream>
#include <ctime>
#include <cstdint>
#include <cstdlib>
#include "verilated.h"
#include "Vmux_16to1_8bits.h"
#include <bitset>

#define NUM_TESTS 1000000

int main (int argc, char** argv) 
{
    Verilated::commandArgs(argc, argv);
    Vmux_16to1_8bits* mux_16to1_8bits = new Vmux_16to1_8bits;

    std::srand(std::time(nullptr));

    u_int8_t mux_16to1_8bits_out;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        uint8_t in0 = rand()   & 0x0F;
        uint8_t in1 = rand()   & 0x0F;
        uint8_t in2 = rand()   & 0x0F;
        uint8_t in3 = rand()   & 0x0F;
        uint8_t in4 = rand()   & 0x0F;
        uint8_t in5 = rand()   & 0x0F;
        uint8_t in6 = rand()   & 0x0F;
        uint8_t in7 = rand()   & 0x0F;
        uint8_t in8 = rand()   & 0x0F;
        uint8_t in9 = rand()   & 0x0F;
        uint8_t in10 = rand()  & 0x0F;
        uint8_t in11 = rand()  & 0x0F;
        uint8_t in12 = rand()  & 0x0F;
        uint8_t in13 = rand()  & 0x0F;
        uint8_t in14 = rand()  & 0x0F;
        uint8_t in15 = rand()  & 0x0F;
        uint8_t sel = rand()   & 0x0F;

        switch (sel)
        {
            case 0x0: mux_16to1_8bits_out = in0; break;
            case 0x1: mux_16to1_8bits_out = in1; break;
            case 0x2: mux_16to1_8bits_out = in2; break;
            case 0x3: mux_16to1_8bits_out = in3; break;
            case 0x4: mux_16to1_8bits_out = in4; break;
            case 0x5: mux_16to1_8bits_out = in5; break;
            case 0x6: mux_16to1_8bits_out = in6; break;
            case 0x7: mux_16to1_8bits_out = in7; break;
            case 0x8: mux_16to1_8bits_out = in8; break;
            case 0x9: mux_16to1_8bits_out = in9; break;
            case 0xA: mux_16to1_8bits_out = in10; break;
            case 0xB: mux_16to1_8bits_out = in11; break;
            case 0xC: mux_16to1_8bits_out = in12; break;
            case 0xD: mux_16to1_8bits_out = in13; break;
            case 0xE: mux_16to1_8bits_out = in14; break;
            case 0xF: mux_16to1_8bits_out = in15; break;
            default:  mux_16to1_8bits_out = 0;
        }

        mux_16to1_8bits->in0    = in0;
        mux_16to1_8bits->in1    = in1;
        mux_16to1_8bits->in2    = in2;
        mux_16to1_8bits->in3    = in3;
        mux_16to1_8bits->in4    = in4;
        mux_16to1_8bits->in5    = in5;
        mux_16to1_8bits->in6    = in6;
        mux_16to1_8bits->in7    = in7;
        mux_16to1_8bits->in8    = in8;
        mux_16to1_8bits->in9    = in9;
        mux_16to1_8bits->in10   = in10;
        mux_16to1_8bits->in11   = in11;
        mux_16to1_8bits->in12   = in12;
        mux_16to1_8bits->in13   = in13;
        mux_16to1_8bits->in14   = in14;
        mux_16to1_8bits->in15   = in15;
        mux_16to1_8bits->sel    = sel;
        mux_16to1_8bits->eval();

        if (mux_16to1_8bits_out != mux_16to1_8bits->mux_out)
        {
            std::cout << "testN" << test
            <<  " Mismatch "
            <<  " in0="         << std::bitset<8>(in0) 
            <<  " in1="         << std::bitset<8>(in1)
            <<  " in2="         << std::bitset<8>(in2)
            <<  " in3="         << std::bitset<8>(in3)
            <<  " in4="         << std::bitset<8>(in4)
            <<  " in5="         << std::bitset<8>(in5)
            <<  " in6="         << std::bitset<8>(in6)
            <<  " in7="         << std::bitset<8>(in7)
            <<  " in0="         << std::bitset<8>(in8) 
            <<  " in1="         << std::bitset<8>(in9)
            <<  " in2="         << std::bitset<8>(in10)
            <<  " in3="         << std::bitset<8>(in11)
            <<  " in4="         << std::bitset<8>(in12)
            <<  " in5="         << std::bitset<8>(in13)
            <<  " in6="         << std::bitset<8>(in14)
            <<  " in7="         << std::bitset<8>(in15)
            <<  " sel="         << std::bitset<4>(sel)
            <<  " Expected="    << std::bitset<8>(mux_16to1_8bits_out)
            <<  " Got="         << std::bitset<8>(mux_16to1_8bits->mux_out)
            << std::endl;
        }
    }

    std::cout << "mux_16to1_8bits Testbench completed." << std::endl;
    delete mux_16to1_8bits;
    return 0;
}