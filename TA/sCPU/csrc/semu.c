#include <stdint.h>
#include <stdio.h>

static uint8_t PC = 0;
static uint8_t R[4];
static uint8_t M[16] = {
  0b10001010,    // 0: li r0, 10
  0b10010000,    // 1: li r1, 0
  0b10100000,    // 2: li r2, 0
  0b10110001,    // 3: li r3, 1
  0b00010111,    // 4: add r1, r1, r3
  0b00101001,    // 5: add r2, r2, r1
  0b11010001,    // 6: bner0 r1, 4
  0b11011111     // 7: bner0 r3, 7
};

void inst_cycle() {
  // fetch
  uint8_t inst = M[PC];

  // decode
  uint8_t opcode = (inst >> 6) & 0x3;
  uint8_t next_pc = PC + 1;
  uint8_t rd = (inst >> 4) & 0x3;
  uint8_t rs1 = (inst >> 2) & 0x3;
  uint8_t rs2 = inst & 0x3;
  uint8_t imm = inst & 0xf;
  uint8_t addr = (inst >> 2) & 0xf;

  // execute
  switch (opcode) {
    case 0b00: R[rd] = R[rs1] + R[rs2];            break;  // add
    case 0b10: R[rd] = imm;                        break;  // li
    case 0b11: if (R[0] != R[rs2]) next_pc = addr; break; // bner0
  }

  // update PC
  PC = next_pc;

#ifndef DIFFTEST
  printf("[inst] = %x, R[0] = %d, R[1] = %d, R[2] = %d, R[3] = %d\n", inst, R[0], R[1], R[2], R[3]);
#endif
}

#ifdef DIFFTEST
uint8_t* semu_get_regs() { return R; }

#else
int main(int argc, char *argv[]) {
  int cycle = 35;
  while (cycle --) { 
    inst_cycle(); 
  }
  return 0;
}
#endif
