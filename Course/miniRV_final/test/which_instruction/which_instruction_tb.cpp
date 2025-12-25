#include <iostream>
#include <ctime>
#include <cstdint>
#include <cstdlib>
#include "verilated.h"
#include "Vwhich_instruction.h"
#include <bitset>

#define NUM_TESTS 1000000

int main (int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Vwhich_instruction* which_instruction = new Vwhich_instruction;
    std::srand(std::time(nullptr));

    uint8_t opcode;
    uint8_t funct3;
    uint8_t funct7;

    uint8_t add;
    uint8_t addi;
    uint8_t lui;
    uint8_t lw;
    uint8_t lbu;
    uint8_t sw;
    uint8_t sb;
    uint8_t jalr;
    uint8_t illegal;

    for (int test = 0; test < NUM_TESTS; test++)
    {
        opcode = rand() & 0x7F;  // 7-bit
        funct3 = rand() & 0x7;   // 3-bit
        funct7 = rand() & 0x7F;  // 7-bit

        add  = (opcode == 0b0110011) && (funct3 == 0b000) && (funct7 == 0b0000000);
        addi = (opcode == 0b0010011) && (funct3 == 0b000);
        lui  = (opcode == 0b0110111);
        lw   = (opcode == 0b0000011) && (funct3 == 0b010);
        lbu  = (opcode == 0b0000011) && (funct3 == 0b100);
        sw   = (opcode == 0b0100011) && (funct3 == 0b010);
        sb   = (opcode == 0b0100011) && (funct3 == 0b000);
        jalr = (opcode == 0b1100111) && (funct3 == 0b000);

        illegal = !(add | addi | lui | lw | lbu | sw | sb | jalr);

        // Drive which_instruction
        which_instruction->opcode = opcode;
        which_instruction->funct3 = funct3;
        which_instruction->funct7 = funct7;
        which_instruction->eval();

        // Compare all outputs; report full state on any mismatch
        bool mismatch =
            (which_instruction->add     != add)  ||
            (which_instruction->addi    != addi) ||
            (which_instruction->lui     != lui)  ||
            (which_instruction->lw      != lw)   ||
            (which_instruction->lbu     != lbu)  ||
            (which_instruction->sw      != sw)   ||
            (which_instruction->sb      != sb)   ||
            (which_instruction->jalr    != jalr) ||
            (which_instruction->illegal != illegal);

        if (mismatch)
        {
            std::cout << "testN" << test
                      << " Mismatch "
                      << " opcode="  << std::bitset<7>(opcode)
                      << " funct3="  << std::bitset<3>(funct3)
                      << " funct7="  << std::bitset<7>(funct7)
                      << " Expected:"
                      << " add="     << std::bitset<1>(add)
                      << " addi="    << std::bitset<1>(addi)
                      << " lui="     << std::bitset<1>(lui)
                      << " lw="      << std::bitset<1>(lw)
                      << " lbu="     << std::bitset<1>(lbu)
                      << " sw="      << std::bitset<1>(sw)
                      << " sb="      << std::bitset<1>(sb)
                      << " jalr="    << std::bitset<1>(jalr)
                      << " illegal=" << std::bitset<1>(illegal)
                      << " Got:"
                      << " add="     << std::bitset<1>((uint8_t)which_instruction->add)
                      << " addi="    << std::bitset<1>((uint8_t)which_instruction->addi)
                      << " lui="     << std::bitset<1>((uint8_t)which_instruction->lui)
                      << " lw="      << std::bitset<1>((uint8_t)which_instruction->lw)
                      << " lbu="     << std::bitset<1>((uint8_t)which_instruction->lbu)
                      << " sw="      << std::bitset<1>((uint8_t)which_instruction->sw)
                      << " sb="      << std::bitset<1>((uint8_t)which_instruction->sb)
                      << " jalr="    << std::bitset<1>((uint8_t)which_instruction->jalr)
                      << " illegal=" << std::bitset<1>((uint8_t)which_instruction->illegal)
                      << std::endl;

            // Optional: stop at first failure
            delete which_instruction;
            return 1;
        }

        // Optional invariant check: illegal must be complement of OR of others
        uint8_t got_or = (uint8_t)which_instruction->add | (uint8_t)which_instruction->addi | (uint8_t)which_instruction->lui | (uint8_t)which_instruction->lw |
                         (uint8_t)which_instruction->lbu | (uint8_t)which_instruction->sw | (uint8_t)which_instruction->sb | (uint8_t)which_instruction->jalr;
        uint8_t got_illegal_should = !got_or;
        if ((uint8_t)which_instruction->illegal != got_illegal_should)
        {
            std::cout << "testN" << test
                      << " InvariantFail "
                      << " illegal != ~(OR of valids)"
                      << " opcode=" << std::bitset<7>(opcode)
                      << " funct3=" << std::bitset<3>(funct3)
                      << " funct7=" << std::bitset<7>(funct7)
                      << " illegal=" << int((uint8_t)which_instruction->illegal)
                      << " or_valid=" << int(got_or)
                      << std::endl;

            // Optional: stop
            delete which_instruction;
            return 1;
        }
    }

    std::cout << "which_instruction Testbench completed." << std::endl;
    delete which_instruction;
    return 0;
}
