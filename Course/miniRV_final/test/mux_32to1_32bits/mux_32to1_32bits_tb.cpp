#include <iostream>
#include <ctime>
#include <cstdint>
#include <cstdlib>
#include "verilated.h"
#include "Vmux_32to1_32bits.h"
#include <bitset>

#define NUM_TESTS 1000000

int main (int argc, char** argv) 
{
    Verilated::commandArgs(argc, argv);
    Vmux_32to1_32bits* mux_32to1_32bits = new Vmux_32to1_32bits;

    std::srand(std::time(nullptr));

    uint32_t mux_32to1_32bits_out;

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
        uint32_t in16 = rand()  & 0xFFFF;
        uint32_t in17 = rand()  & 0xFFFF;
        uint32_t in18 = rand()  & 0xFFFF;
        uint32_t in19 = rand()  & 0xFFFF;
        uint32_t in20 = rand()  & 0xFFFF;
        uint32_t in21 = rand()  & 0xFFFF;
        uint32_t in22 = rand()  & 0xFFFF;
        uint32_t in23 = rand()  & 0xFFFF;
        uint32_t in24 = rand()  & 0xFFFF;
        uint32_t in25 = rand()  & 0xFFFF;
        uint32_t in26 = rand()  & 0xFFFF;
        uint32_t in27 = rand()  & 0xFFFF;
        uint32_t in28 = rand()  & 0xFFFF;
        uint32_t in29 = rand()  & 0xFFFF;
        uint32_t in30 = rand()  & 0xFFFF;
        uint32_t in31 = rand()  & 0xFFFF;
        uint32_t sel = rand()   & 0b11111;

        switch (sel)
        {
            case 0x00: mux_32to1_32bits_out = in0; break;
            case 0x01: mux_32to1_32bits_out = in1; break;
            case 0x02: mux_32to1_32bits_out = in2; break;
            case 0x03: mux_32to1_32bits_out = in3; break;
            case 0x04: mux_32to1_32bits_out = in4; break;
            case 0x05: mux_32to1_32bits_out = in5; break;
            case 0x06: mux_32to1_32bits_out = in6; break;
            case 0x07: mux_32to1_32bits_out = in7; break;
            case 0x08: mux_32to1_32bits_out = in8; break;
            case 0x09: mux_32to1_32bits_out = in9; break;
            case 0x0A: mux_32to1_32bits_out = in10; break;
            case 0x0B: mux_32to1_32bits_out = in11; break;
            case 0x0C: mux_32to1_32bits_out = in12; break;
            case 0x0D: mux_32to1_32bits_out = in13; break;
            case 0x0E: mux_32to1_32bits_out = in14; break;
            case 0x0F: mux_32to1_32bits_out = in15; break;
            case 0x10: mux_32to1_32bits_out = in16; break;
            case 0x11: mux_32to1_32bits_out = in17; break;
            case 0x12: mux_32to1_32bits_out = in18; break;
            case 0x13: mux_32to1_32bits_out = in19; break;
            case 0x14: mux_32to1_32bits_out = in20; break;
            case 0x15: mux_32to1_32bits_out = in21; break;
            case 0x16: mux_32to1_32bits_out = in22; break;
            case 0x17: mux_32to1_32bits_out = in23; break;
            case 0x18: mux_32to1_32bits_out = in24; break;
            case 0x19: mux_32to1_32bits_out = in25; break;
            case 0x1A: mux_32to1_32bits_out = in26; break;
            case 0x1B: mux_32to1_32bits_out = in27; break;
            case 0x1C: mux_32to1_32bits_out = in28; break;
            case 0x1D: mux_32to1_32bits_out = in29; break;
            case 0x1E: mux_32to1_32bits_out = in30; break;
            case 0x1F: mux_32to1_32bits_out = in31; break;
            default:  mux_32to1_32bits_out = 0;
        }

        mux_32to1_32bits->in0    = in0;
        mux_32to1_32bits->in1    = in1;
        mux_32to1_32bits->in2    = in2;
        mux_32to1_32bits->in3    = in3;
        mux_32to1_32bits->in4    = in4;
        mux_32to1_32bits->in5    = in5;
        mux_32to1_32bits->in6    = in6;
        mux_32to1_32bits->in7    = in7;
        mux_32to1_32bits->in8    = in8;
        mux_32to1_32bits->in9    = in9;
        mux_32to1_32bits->in10   = in10;
        mux_32to1_32bits->in11   = in11;
        mux_32to1_32bits->in12   = in12;
        mux_32to1_32bits->in13   = in13;
        mux_32to1_32bits->in14   = in14;
        mux_32to1_32bits->in15   = in15;
        mux_32to1_32bits->in16   = in16;
        mux_32to1_32bits->in17   = in17;
        mux_32to1_32bits->in18   = in18;
        mux_32to1_32bits->in19   = in19;
        mux_32to1_32bits->in20   = in20;
        mux_32to1_32bits->in21   = in21;
        mux_32to1_32bits->in22   = in22;
        mux_32to1_32bits->in23   = in23;
        mux_32to1_32bits->in24   = in24;
        mux_32to1_32bits->in25   = in25;
        mux_32to1_32bits->in26   = in26;
        mux_32to1_32bits->in27   = in27;
        mux_32to1_32bits->in28   = in28;
        mux_32to1_32bits->in29   = in29;
        mux_32to1_32bits->in30   = in30;
        mux_32to1_32bits->in31   = in31;
        mux_32to1_32bits->sel    = sel;
        mux_32to1_32bits->eval();

        if (mux_32to1_32bits_out != mux_32to1_32bits->mux_out)
        {
            std::cout << "testN" << test
            <<  " Mismatch "
            <<  " in0="         << std::bitset<32>(in0) << std::endl    
            <<  " in1="         << std::bitset<32>(in1) << std::endl  
            <<  " in2="         << std::bitset<32>(in2) << std::endl  
            <<  " in3="         << std::bitset<32>(in3) << std::endl  
            <<  " in4="         << std::bitset<32>(in4) << std::endl  
            <<  " in5="         << std::bitset<32>(in5) << std::endl  
            <<  " in6="         << std::bitset<32>(in6) << std::endl  
            <<  " in7="         << std::bitset<32>(in7) << std::endl  
            <<  " in8="         << std::bitset<32>(in8) << std::endl   
            <<  " in9="         << std::bitset<32>(in9) << std::endl  
            <<  " in10="        << std::bitset<32>(in10) << std::endl 
            <<  " in11="        << std::bitset<32>(in11) << std::endl 
            <<  " in12="        << std::bitset<32>(in12) << std::endl 
            <<  " in13="        << std::bitset<32>(in13) << std::endl 
            <<  " in14="        << std::bitset<32>(in14) << std::endl 
            <<  " in15="        << std::bitset<32>(in15) << std::endl 
            <<  " in16="         << std::bitset<32>(in0)  << std::endl 
            <<  " in17="         << std::bitset<32>(in1) << std::endl 
            <<  " in18="         << std::bitset<32>(in2) << std::endl 
            <<  " in19="         << std::bitset<32>(in3) << std::endl 
            <<  " in20="         << std::bitset<32>(in4) << std::endl 
            <<  " in21="         << std::bitset<32>(in5) << std::endl 
            <<  " in22="         << std::bitset<32>(in6) << std::endl 
            <<  " in23="         << std::bitset<32>(in7) << std::endl 
            <<  " in24="         << std::bitset<32>(in8)  << std::endl 
            <<  " in25="         << std::bitset<32>(in9) << std::endl 
            <<  " in26="        << std::bitset<32>(in10) << std::endl 
            <<  " in27="        << std::bitset<32>(in11) << std::endl 
            <<  " in28="        << std::bitset<32>(in12) << std::endl 
            <<  " in29="        << std::bitset<32>(in13) << std::endl 
            <<  " in30="        << std::bitset<32>(in14) << std::endl 
            <<  " in31="        << std::bitset<32>(in15) << std::endl 
            <<  " sel="         << std::bitset<5>(sel) << std::endl
            <<  " Expected="    << std::bitset<32>(mux_32to1_32bits_out) << std::endl
            <<  " Got="         << std::bitset<32>(mux_32to1_32bits->mux_out)
            << std::endl;
        }
    }

    std::cout << "mux_32to1_32bits Testbench completed." << std::endl;
    delete mux_32to1_32bits;
    return 0;
}