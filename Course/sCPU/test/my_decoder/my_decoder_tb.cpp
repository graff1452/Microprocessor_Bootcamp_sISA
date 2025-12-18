#include <iostream>
#include <ctime>
#include <cstdint>
#include <bitset>
#include "Vmy_decoder.h"
#include "verilated.h" 
#include <cstdlib>

#define NUM_TESTS 1000000

int main(int argc, char** argv) 
{
    Verilated::commandArgs(argc, argv);
    Vmy_decoder* my_decoder = new Vmy_decoder;
    std::srand(std::time(nullptr));
    uint8_t D;
    uint8_t op;
    uint8_t rd;
    uint8_t rs1;
    uint8_t rs2;
    uint8_t addr;
    uint8_t imm;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        D = rand() & 0xFF;
        my_decoder->D = D;
        my_decoder->eval();

        op      = (D >> 6) & 0b11;
        rd      = (D >> 4) & 0b11;
        rs1     = (D >> 2) & 0b11;
        rs2     = D & 0b11;
        addr    = (D >> 2) & 0b1111;
        imm     = D & 0b1111;

        if (op != my_decoder->op        || 
            rd != my_decoder->rd        ||
            rs1 != my_decoder->rs1      ||
            rs2 != my_decoder->rs2      ||
            addr != my_decoder->addr    ||
            imm != my_decoder->imm) 
        {
            std::cout << "testN"    << test
            <<  " Mismatch "
            <<  " D="               << std::bitset<8>(D)
            <<  " Expected:"
            <<  " op="              << std::bitset<2>(op)
            <<  " rd="              << std::bitset<2>(rd)
            <<  " rs1="             << std::bitset<2>(rs1)
            <<  " rs2="             << std::bitset<2>(rs2)
            <<  " addr="            << std::bitset<4>(addr)
            <<  " imm="             << std::bitset<4>(imm) 
            <<  " Got:"
            <<  " op="              << std::bitset<2>(my_decoder->op)
            <<  " rd="              << std::bitset<2>(my_decoder->rd)
            <<  " rs1="             << std::bitset<2>(my_decoder->rs1)
            <<  " rs2="             << std::bitset<2>(my_decoder->rs2)
            <<  " addr="            << std::bitset<4>(my_decoder->addr)
            <<  " imm="             << std::bitset<4>(my_decoder->imm) 
            << std::endl;
        }
    }
    std::cout << "my_decoder Testbench completed." << std::endl;
    delete my_decoder;
    return 0;
}