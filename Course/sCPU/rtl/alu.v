module alu
(
    input   wire [7:0]  A,
    input   wire [7:0]  B,
    input   wire [3:0]  imm,
    input   wire [7:0]  reg0_val,
    input   wire        add,
    output  wire [7:0]  ALU_out,
    output  wire        equal
);
    wire [7:0] adder_8bits_1_out;
    adder_8bits adder_8bits_1 
    (
        .A(A),
        .B(B),
        .Sum(adder_8bits_1_out)
    );

    mux_2to1_8bits mux_2to1_8bits_1 
    (
        .in0(adder_8bits_1_out),
        .in1({4'b0000, imm}),
        .sel(~add),
        .mux_out(ALU_out)
    );

    comparator_8bits comparator_8bits_1 
    (
        .A(B),
        .B(reg0_val),
        .equal(equal)
    );
endmodule
