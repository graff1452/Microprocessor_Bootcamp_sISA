#include <iostream>
#include <ctime>
#include "verilated.h"
#include "Vwhich_type.h"
#include <bitset>
#include <cstdlib>
#include <cstdint>

#define NUM_TESTS 1000000

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Vwhich_type* which_type = new Vwhich_type;
    std::srand(std::time(nullptr));

    static const uint8_t valid_opcodes[5] = {
        0b0010011,
        0b0000011,
        0b1100111,
        0b0100011,
        0b0110111
    };

    uint32_t    opcode;
    uint8_t     r_type;
    uint8_t     i_type;
    uint8_t     s_type;
    uint8_t     u_type;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        //opcode = rand() & 0b1111111;
        opcode = valid_opcodes[rand() % 5];
        which_type->opcode = opcode;
        which_type->eval();

        r_type = 0;
        i_type = 0;
        s_type = 0;
        u_type = 0;

        if (opcode == 0b0110011)
        {
            r_type = 0b1;
        }
        else if (opcode == 0b0010011 || 
            opcode == 0b0000011 || 
            opcode == 0b1100111) 
        {
            i_type = 0b1;
        }
        else if (opcode == 0b0100011)
        {
            s_type = 0b1;
        }
        else if (opcode == 0b0110111)
        {
            u_type = 0b1;
        }
        else 
        {
            i_type = 0;
            s_type = 0;
            u_type = 0;
        }

        if (which_type->i_type != i_type || 
            which_type->s_type != s_type || 
            which_type->u_type != u_type)
        {
            std::cout << "testN"    << test
            <<  " Mismatch "
            <<  " opcode="          << std::bitset<7>(opcode) 
            <<  " Expected:"
            <<  " i_type="          << std::bitset<1>(i_type)
            <<  " s_type="          << std::bitset<1>(s_type)
            <<  " u_type="          << std::bitset<1>(u_type)
            <<  " Got:"
            <<  " i_type="          << std::bitset<1>(which_type->i_type)
            <<  " s_type="          << std::bitset<1>(which_type->s_type)
            <<  " u_type="          << std::bitset<1>(which_type->u_type)
            << std::endl;
        }

    }
    std::cout << "which_type Testbench completed." << std::endl;
    delete which_type;
    return 0;
}