CXX = g++
CC = gcc
VERILATOR = verilator

CSRC_DIR = csrc
BUILD_DIR = obj_dir

VL_FLAGS = --cc --exe --build -j 0 -Wall --trace -CFLAGS "-DDIFFTEST"
TOP_MODULE = top
VERILOG_SRCS = vsrc/top.v
SIM_SRCS = csrc/main.cpp 
SIM_SRCS += csrc/semu.c

all: run

sim: $(VERILOG_SRCS) $(SIM_SRCS)
	$(VERILATOR) $(VL_FLAGS) $(VERILOG_SRCS) $(SIM_SRCS) --top-module $(TOP_MODULE)

run: sim
	./$(BUILD_DIR)/V$(TOP_MODULE)

clean:
	-rm -rf $(BUILD_DIR) wave.vcd

.PHONY: all sim run clean
