module selector 
(
    input   wire [1:0] rs1,
    input   wire [1:0] rs2,
    input   wire [7:0] reg0_in,
    input   wire [7:0] reg1_in,
    input   wire [7:0] reg2_in,
    input   wire [7:0] reg3_in,
    output  wire [7:0] A,
    output  wire [7:0] B
);
    mux_4to1_8bits mux_4to1_8bits_1 
    (
        .in0(reg0_in),
        .in1(reg1_in),
        .in2(reg2_in),
        .in3(reg3_in),
        .sel(rs1),
        .mux_out(A)
    );

    mux_4to1_8bits mux_4to1_8bits_2 
    (
        .in0(reg0_in),
        .in1(reg1_in),
        .in2(reg2_in),
        .in3(reg3_in),
        .sel(rs2),
        .mux_out(B)
    );
endmodule
