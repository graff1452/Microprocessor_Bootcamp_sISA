#include <iostream>
#include <ctime>
#include <cstdint>
#include <cstdlib>
#include "verilated.h"
#include "Vreg_write_enabler.h"
#include <bitset>

#define NUM_TESTS 1000000

int main (int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vreg_write_enabler* reg_write_enabler = new Vreg_write_enabler;

    std::srand(std::time(nullptr));

    uint8_t reg_write;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        uint8_t add     = rand() & 0x1;
        uint8_t addi    = rand() & 0x1;
        uint8_t lui     = rand() & 0x1;
        uint8_t lw      = rand() & 0x1;
        uint8_t lbu     = rand() & 0x1;
        uint8_t jalr    = rand() & 0x1;
        uint8_t illegal = rand() & 0x1;

        // Expected behavior (match RTL exactly)
        reg_write =
            ((add || addi || lui || lw || lbu || jalr) && !illegal);

        // Drive DUT
        reg_write_enabler->add     = add;
        reg_write_enabler->addi    = addi;
        reg_write_enabler->lui     = lui;
        reg_write_enabler->lw      = lw;
        reg_write_enabler->lbu     = lbu;
        reg_write_enabler->jalr    = jalr;
        reg_write_enabler->illegal = illegal;
        reg_write_enabler->eval();

        if (reg_write != reg_write_enabler->reg_write)
        {
            std::cout << "testN" << test
                      << " Mismatch "
                      << " add="     << std::bitset<1>(add)
                      << " addi="    << std::bitset<1>(addi)
                      << " lui="     << std::bitset<1>(lui)
                      << " lw="      << std::bitset<1>(lw)
                      << " lbu="     << std::bitset<1>(lbu)
                      << " jalr="    << std::bitset<1>(jalr)
                      << " illegal=" << std::bitset<1>(illegal)
                      << " Expected="<< std::bitset<1>(reg_write)
                      << " Got="     << std::bitset<1>(reg_write_enabler->reg_write)
                      << std::endl;

            // Optional: stop on first failure
            delete reg_write_enabler;
            return 1;
        }
    }

    std::cout << "reg_write_enabler Testbench completed." << std::endl;
    delete reg_write_enabler;
    return 0;
}
