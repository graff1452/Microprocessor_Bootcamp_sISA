#include <iostream>
#include <ctime>
#include <cstdint>
#include <cstdlib>
#include "verilated.h"
#include "Vb_mux.h"
#include <bitset>

#define NUM_TESTS 1000000

int main (int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vb_mux* b_mux = new Vb_mux;

    std::srand(std::time(nullptr));

    uint32_t b;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        uint32_t rs2_val = rand() & 0xFFFFFFFF;
        uint32_t imm     = rand() & 0xFFFFFFFF;

        uint8_t addi = rand() & 0x1;
        uint8_t lw   = rand() & 0x1;
        uint8_t lbu  = rand() & 0x1;
        uint8_t sw   = rand() & 0x1;
        uint8_t sb   = rand() & 0x1;
        uint8_t jalr = rand() & 0x1;

        // Compute expected (match RTL exactly)
        if (addi || lw || lbu || sw || sb || jalr)
        {
            b = imm;
        }
        else
        {
            b = rs2_val;
        }

        b_mux->rs2_val = rs2_val;
        b_mux->imm     = imm;
        b_mux->addi    = addi;
        b_mux->lw      = lw;
        b_mux->lbu     = lbu;
        b_mux->sw      = sw;
        b_mux->sb      = sb;
        b_mux->jalr    = jalr;
        b_mux->eval();

        if (b != b_mux->b)
        {
            std::cout << "testN" << test
                      << " Mismatch "
                      << " rs2_val=" << std::bitset<32>(rs2_val)
                      << " imm="     << std::bitset<32>(imm)
                      << " addi="    << std::bitset<1>(addi)
                      << " lw="      << std::bitset<1>(lw)
                      << " lbu="     << std::bitset<1>(lbu)
                      << " sw="      << std::bitset<1>(sw)
                      << " sb="      << std::bitset<1>(sb)
                      << " jalr="    << std::bitset<1>(jalr)
                      << " Expected="<< std::bitset<32>(b)
                      << " Got="     << std::bitset<32>(b_mux->b)
                      << std::endl;

            // Optional: stop on first failure
            delete b_mux;
            return 1;
        }
    }

    std::cout << "b_mux Testbench completed." << std::endl;
    delete b_mux;
    return 0;
}
