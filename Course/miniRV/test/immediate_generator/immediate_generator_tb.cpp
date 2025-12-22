#include <iostream>
#include <ctime>
#include <cstdint>
#include <cstdlib>
#include "verilated.h"
#include "Vimmediate_generator.h"
#include <bitset>

#define NUM_TESTS 1000000

int main (int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vimmediate_generator* immediate_generator = new Vimmediate_generator;

    std::srand(std::time(nullptr));

    uint32_t imm;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        uint32_t instruction = rand() & 0xFFFFFFFF;

        uint8_t illegal = rand() & 0x1;
        uint8_t r_type  = rand() & 0x1;
        uint8_t i_type  = rand() & 0x1;
        uint8_t s_type  = rand() & 0x1;
        uint8_t u_type  = rand() & 0x1;

        if (i_type == 1)
        {
            uint32_t imm12 = (instruction >> 20) & 0xFFF;
            imm = (imm12 & 0x800) ? (imm12 | 0xFFFFF000) : imm12;
        }
        else if (s_type == 1)
        {
            uint32_t imm12 = (((instruction >> 25) & 0x7F) << 5)  // inst[31:25] -> [11:5]
                          | ((instruction >> 7)  & 0x1F);         // inst[11:7]  -> [4:0]
            // sign-extend 12-bit
            imm = (imm12 & 0x800) ? (imm12 | 0xFFFFF000) : imm12;
        }
        else if (u_type == 1)
        {
            imm = instruction & 0xFFFFF000;              // inst[31:12] << 12
        }
        else
        {
            imm = 0;
        }

        immediate_generator->instruction = instruction;
        immediate_generator->illegal     = illegal;
        immediate_generator->r_type      = r_type;
        immediate_generator->i_type      = i_type;
        immediate_generator->s_type      = s_type;
        immediate_generator->u_type      = u_type;
        immediate_generator->eval();

        if (imm != immediate_generator->imm)
        {
            std::cout << "testN" << test
            <<  " Mismatch "
            <<  " instruction=" << std::bitset<32>(instruction)
            <<  " illegal="     << std::bitset<1>(illegal)
            <<  " r_type="      << std::bitset<1>(r_type)
            <<  " i_type="      << std::bitset<1>(i_type)
            <<  " s_type="      << std::bitset<1>(s_type)
            <<  " u_type="      << std::bitset<1>(u_type)
            <<  " Expected="    << std::bitset<32>(imm)
            <<  " Got="         << std::bitset<32>(immediate_generator->imm)
            << std::endl;
            delete immediate_generator;
            return 1;
        }
    }

    std::cout << "immediate_generator Testbench completed." << std::endl;
    delete immediate_generator;
    return 0;
}
