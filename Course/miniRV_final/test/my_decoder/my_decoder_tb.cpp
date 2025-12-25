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
    uint32_t instruction;
    uint8_t opcode;
    uint8_t rd;
    uint8_t funct3;
    uint8_t rs1;
    uint8_t rs2;
    uint8_t funct7;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        instruction = rand() & 0xFFFFFFFF;
        my_decoder->instruction = instruction;
        my_decoder->eval();

        opcode  = (instruction)         & 0x7f;
        rd      = (instruction >> 7)    & 0x1f;
        funct3  = (instruction >> 12)   & 0x7;
        rs1     = (instruction >> 15)   & 0x1f;
        rs2     = (instruction >> 20)   & 0x1f;
        funct7  = (instruction >> 25)   & 0x7f;

        if (opcode  != my_decoder->opcode   || 
            rd      != my_decoder->rd       ||
            funct3  != my_decoder->funct3   ||
            rs1     != my_decoder->rs1      ||
            rs2     != my_decoder->rs2      ||
            funct7  != my_decoder->funct7) 
        {
            std::cout << "testN"    << test
            <<  " Mismatch "
            <<  " instruction="     << std::bitset<32>(instruction)
            <<  " Expected:"
            <<  " opcode="          << std::bitset<7>(opcode)
            <<  " rd="              << std::bitset<5>(rd)
            <<  " funct3="          << std::bitset<3>(funct3)
            <<  " rs1="             << std::bitset<5>(rs1)
            <<  " rs2="             << std::bitset<5>(rs2)
            <<  " funct7="          << std::bitset<7>(funct7) 
            <<  " Got:"
            <<  " opcode="          << std::bitset<7>(my_decoder->opcode)
            <<  " rd="              << std::bitset<5>(my_decoder->rd)
            <<  " funct3="          << std::bitset<3>(my_decoder->funct3)
            <<  " rs1="             << std::bitset<5>(my_decoder->rs1)
            <<  " rs2="             << std::bitset<5>(my_decoder->rs2)
            <<  " funct7="          << std::bitset<7>(my_decoder->funct7) 
            << std::endl;
        }
    }
    std::cout << "my_decoder Testbench completed." << std::endl;
    delete my_decoder;
    return 0;
}