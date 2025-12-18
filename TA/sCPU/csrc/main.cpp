#include <stdio.h>
#include <Vtop___024root.h>
#include <Vtop.h>
#include <verilated.h>
#include <verilated_vcd_c.h>

static VerilatedContext *contextp = NULL;
static VerilatedVcdC *tfp = NULL;
static Vtop *top = NULL;

void inst_cycle();
uint8_t* semu_get_regs();

static void step_and_dump_wave() {
	top->eval();
	contextp->timeInc(1);
	tfp->dump(contextp->time());
}

static void single_cycle() {
	top->clk = 0; step_and_dump_wave();
	top->clk = 1; step_and_dump_wave();
}

static void reset(int n) {
	top->rst = 1;
	while (n-- > 0) single_cycle();
	top->rst = 0;
}

static void sim_init() {
	contextp = new VerilatedContext;
	tfp = new VerilatedVcdC;
	top = new Vtop{contextp};
	contextp->traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("wave.vcd");
}

static void sim_exit() {
	step_and_dump_wave();
	tfp->close();
	delete tfp;
	delete contextp;
}

int main() {
	sim_init();
  reset(5);
	int cycle = 35;
  uint8_t *R_dut = (uint8_t *)(void *)&top->rootp->top__DOT__regs;
	while (cycle --) {
		single_cycle();
		printf("[RTL] - R[0] = %d, R[1] = %d, R[2] = %d, R[3] = %d\n",
        R_dut[0], R_dut[1], R_dut[2], R_dut[3]);

#ifdef DIFFTEST
		inst_cycle();
    uint8_t *R_ref = semu_get_regs();
		for (int i = 0; i < 4; i++) {
			if (R_dut[i] != R_ref[i]) {
        printf("[ERROR] - DUT[%d] = %d, REF[%d] = %d\n", i, R_dut[i], i, R_ref[i]);
        sim_exit();
        return 1;
      }
		}
#endif
	}

  int ok = top->ok;
  printf("Simulation result: %s\n", ok ? "right" : "wrong");
	sim_exit();
	return 0;
}
