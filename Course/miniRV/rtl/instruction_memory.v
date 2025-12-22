module instruction_memory (
    input  wire [31:0] pc,
    output wire [31:0] instruction
);
    // 16,777,216 instructions × 32 bits = 16 MB
    reg [31:0] rom [0:16777215];

    wire [23:0] instr_index;
    assign instr_index = pc[25:2];  // pc >> 2

    // Combinational read
    assign instruction = rom[instr_index];

    initial begin
        $readmemh("/home/graff145/Desktop/Microprocessor_Bootcamp_sISA/Course/miniRV/instructions/instruction.txt", rom);
    end
endmodule
