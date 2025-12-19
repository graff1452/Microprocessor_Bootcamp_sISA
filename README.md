# sCPU Final Project

This repository contains the final implementation of a simple CPU (**sCPU**), including:
- Instruction generator
- Software golden model (emulator)
- RTL implementation (Verilog)
- Automated comparison between golden model and RTL output

The steps below describe how to build and run the complete flow.

---

## Project Structure

Course/
└── sCPU_final/
├── generator/ # Instruction generator
├── emulator/ # Golden model + comparison tools
├── rtl/ # Verilog RTL (used by Verilator)
├── run.py # RTL simulation script
|── test/ # testbenches

---

first of all, do not forget to change some filepathes in some files:
- Course/sCPU_final/emulator/compare.cpp
- Course/sCPU_final/emulator/main.cpp
- Course/sCPU_final/test/top/top_tb.cpp
- Course/sCPU_final/rtl/instruction_memory.v

## 1. Navigate to the Project Root

```bash
cd Course
cd sCPU_final
```

2. Generate Instructions

Generate the instruction memory contents.
```bash
cd generator
g++ scpu_generator.cpp -o scpu_generator
./scpu_generator 16
```
This generates 16 instructions and writes them to instructions.txt.

3. Run the Golden Model (Software Emulator)

The golden model executes the same instructions in software and produces reference outputs.
```bash
cd ..
cd emulator
g++ -std=c++17 main.cpp scpu_emulator.cpp -o main
./main
```
This step generates:

pc_out_golden_model.txt

register_golden_model.txt
4. Run the RTL Testbench (Verilog + Verilator)

Simulate the RTL design and collect hardware outputs.
```bash
cd ..
python3 run.py -s top
obj_dir/Vtop
```
This produces:

- pc_out_top_module.txt

- register_top_module.txt
5. Compare Golden Model vs RTL Output

Compare the golden model results against the RTL simulation.
```bash
cd emulator
g++ compare.cpp -o compare
./compare
```
The comparison checks:

Program counter (pc_out)

Register values (r0–r3)

If all values match, the RTL implementation is functionally correct.
Summary

Generate instructions

Run golden model (software reference)

Run RTL simulation (hardware model)

Compare results

Successful comparison confirms correctness of the RTL design.

Notes

Instruction memory size: 16 instructions

Program counter width: 4 bits

File I/O is simulation-only (golden model and Verilator)

Requirements

g++ (C++17)

Python 3

Verilator

Linux environment recommended

one-run commands:
```bash
cd Course
cd sCPU_final

cd generator
g++ scpu_generator.cpp -o scpu_generator
./scpu_generator 16

cd ..
cd emulator
g++ -std=c++17 main.cpp scpu_emulator.cpp -o main
./main

cd ..
python3 run.py -s top
obj_dir/Vtop

cd emulator
g++ compare.cpp -o compare
./compare


```