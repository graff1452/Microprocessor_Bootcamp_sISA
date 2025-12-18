module instruction_memory
(
    input   wire [3:0] sel,
    output  wire [7:0] instruction
);
    mux_16to1_8bits mux_16to1_8bits_1 
    (
        .in0(8'b10001010),
        .in1(8'b10010000),
        .in2(8'b10100000),
        .in3(8'b10110001),
        .in4(8'b00010111),
        .in5(8'b00101001),
        .in6(8'b11010001),
        .in7(8'b11011111),
        .in8(8'b00000000),
        .in9(8'b00000000),
        .in10(8'b00000000),
        .in11(8'b00000000),
        .in12(8'b00000000),
        .in13(8'b00000000),
        .in14(8'b00000000),
        .in15(8'b00000000),
        .sel(sel),
        .mux_out(instruction)
    );
endmodule
