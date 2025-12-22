#include <iostream>
#include <ctime>
#include <cstdint>
#include <cstdlib>
#include "verilated.h"
#include "Vwriteback_mux.h"
#include <bitset>

#define NUM_TESTS 1000000

int main (int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vwriteback_mux* writeback_mux = new Vwriteback_mux;

    std::srand(std::time(nullptr));

    uint32_t rd_data;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        uint32_t y         = rand() & 0xFFFF;
        uint32_t imm       = rand() & 0xFFFF;
        uint32_t read_data = rand() & 0xFFFF;
        uint32_t pc_plus_4 = rand() & 0xFFFF;

        uint8_t lw   = rand() & 0x1;
        uint8_t lbu  = rand() & 0x1;
        uint8_t lui  = rand() & 0x1;
        uint8_t jalr = rand() & 0x1;

        if (lw || lbu)
            rd_data = read_data;
        else if (lui)
            rd_data = imm;
        else if (jalr)
            rd_data = pc_plus_4;
        else
            rd_data = y;

        writeback_mux->y         = y;
        writeback_mux->imm       = imm;
        writeback_mux->read_data = read_data;
        writeback_mux->pc_plus_4 = pc_plus_4;
        writeback_mux->lw        = lw;
        writeback_mux->lbu       = lbu;
        writeback_mux->lui       = lui;
        writeback_mux->jalr      = jalr;
        writeback_mux->eval();

        if (rd_data != writeback_mux->rd_data)
        {
            std::cout << "testN" << test
                      << " Mismatch "
                      << " y="         << std::bitset<32>(y)
                      << " imm="       << std::bitset<32>(imm)
                      << " read_data=" << std::bitset<32>(read_data)
                      << " pc_plus_4=" << std::bitset<32>(pc_plus_4)
                      << " lw="        << std::bitset<1>(lw)
                      << " lbu="       << std::bitset<1>(lbu)
                      << " lui="       << std::bitset<1>(lui)
                      << " jalr="      << std::bitset<1>(jalr)
                      << " Expected="  << std::bitset<32>(rd_data)
                      << " Got="       << std::bitset<32>(writeback_mux->rd_data)
                      << std::endl;

            // Optional: stop on first failure
            delete writeback_mux;
            return 1;
        }
    }

    std::cout << "writeback_mux Testbench completed." << std::endl;
    delete writeback_mux;
    return 0;
}
