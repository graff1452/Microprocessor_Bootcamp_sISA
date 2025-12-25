# miniRV Emulator (Golden Model)

This directory contains the **miniRV emulator**, which acts as a **golden reference model** for validating the Verilog `top` module implementation of a reduced RV32I (mini RISC-V) CPU.

The emulator executes the same instruction stream as the hardware design and produces reference values that are later compared against the Verilator simulation output.

---

## Instruction Files

Instruction programs are located in the `/instructions/` directory.

You may find instruction files in `.hex` or `.txt` format.  
`.hex` files **must be converted** into the emulator-compatible `instruction.txt` format before use.

### Convert `.hex` to `instruction.txt`

From the project root (`/minirv`):

```bash
cd instructions
python3 hex_to_txt.py <file.hex> instruction.txt
```

Running the Golden Model (Emulator)

The emulator performs the following steps:

- loads instruction.txt

- executes the program cycle-by-cycle

- dumps reference outputs (PC, instruction, registers, etc.) into text files

These files represent the expected (correct) behavior.

From the project root (/minirv):
```bash
cd emulator
g++ -std=c++17 -O2 -Wall -Wextra main.cpp minirv_emulator.cpp -o main
./main
```
Running the Verilog Top Module Testbench

To simulate the hardware implementation and generate comparable outputs:

From the project root (/minirv):
```bash
python3 run.py -s top
./obj_dir/Vtop
```
This runs the Verilator testbench for the top module and produces its own output files.

Comparing Emulator vs Hardware Results

After both the emulator and Verilator simulation have completed, compare their outputs:

From the project root (/minirv):
```bash
cd emulator
g++ compare.cpp -o compare
./compare
```
The comparison tool checks:

- PC values

- instructions

- register file contents

Any mismatch indicates a discrepancy between the golden model and the hardware design.

one-time run commands:
```bash
cd instructions
python3 hex_to_txt.py vga.hex instruction.txt

cd ../emulator
g++ -std=c++17 -O2 -Wall -Wextra main.cpp minirv_emulator.cpp -o main
./main

cd ..
python3 run.py -s top
./obj_dir/Vtop

cd emulator
g++ compare.cpp -o compare
./compare
```
