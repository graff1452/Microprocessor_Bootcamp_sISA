#include <iostream>
#include <ctime>
#include <cstdint>
#include <bitset>
#include "Vwhich_type.h"
#include "verilated.h" 
#include <cstdlib>

#define NUM_TESTS 1000000

int main(int argc, char** argv) 
{
    Verilated::commandArgs(argc, argv);
    Vwhich_type* which_type = new Vwhich_type;
    std::srand(std::time(nullptr));
    uint8_t op;
    int add;
    int li;
    int bne;
    int empty_inst;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        op = (rand() >> 6) & 0b11;
        which_type->op = op;
        which_type->eval();

        if (op == 0b00) 
        {
            add = 1;
            li = 0;
            bne = 0;
            empty_inst = 0;
        }
        else if (op == 0b01)
        {
            add = 0;
            li = 0;
            bne = 0;
            empty_inst = 1;
        }
        else if (op == 0b10)
        {
            add = 0;
            li = 1;
            bne = 0;
            empty_inst = 0;
        }
        else 
        {
            add = 0;
            li = 0;
            bne = 1;
            empty_inst = 0;
        }

        if (add != which_type->add  || 
            li != which_type->li    ||
            bne != which_type->bne  ||
            empty_inst != which_type->empty_inst)
        {
            std::cout << "testN"    << test
            <<  " Mismatch "
            <<  " op="              << std::bitset<2>(op)
            <<  " Expected:"
            <<  " add="             << std::bitset<1>(add)
            <<  " li="              << std::bitset<1>(li)
            <<  " bne="             << std::bitset<1>(bne)
            <<  " empty_inst="      << std::bitset<1>(empty_inst)
            <<  " Got:"
            <<  " add="             << std::bitset<1>(which_type->add)
            <<  " li="              << std::bitset<1>(which_type->li)
            <<  " bne="             << std::bitset<1>(which_type->bne)
            <<  " empty_inst="      << std::bitset<1>(which_type->empty_inst)
            << std::endl;
        }
    }
    std::cout << "which_type Testbench completed." << std::endl;
    delete which_type;
    return 0;
}