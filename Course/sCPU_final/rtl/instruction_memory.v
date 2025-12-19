module instruction_memory
(
    input   wire [3:0] sel,
    output  wire [7:0] instruction
);
    reg [7:0] instr_mem [0:15];  // 8-byte instruction memory
    initial begin
        $readmemh("/home/graff145/Desktop/Microprocessor_Bootcamp_sISA/Course/sCPU_final/generator/instructions.txt", instr_mem);
    end
    mux_16to1_8bits mux_16to1_8bits_1 
    (
        .in0(instr_mem[0]),
        .in1(instr_mem[1]),
        .in2(instr_mem[2]),
        .in3(instr_mem[3]),
        .in4(instr_mem[4]),
        .in5(instr_mem[5]),
        .in6(instr_mem[6]),
        .in7(instr_mem[7]),
        .in8(instr_mem[8]),
        .in9(instr_mem[9]),
        .in10(instr_mem[10]),
        .in11(instr_mem[11]),
        .in12(instr_mem[12]),
        .in13(instr_mem[13]),
        .in14(instr_mem[14]),
        .in15(instr_mem[15]),
        .sel(sel),
        .mux_out(instruction)
    );
endmodule
