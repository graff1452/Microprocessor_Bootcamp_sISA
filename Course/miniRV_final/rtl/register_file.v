module register_file
(
    input   wire [4:0]  rs1_addr,
    input   wire [4:0]  rs2_addr,
    input   wire [4:0]  rd_addr,
    input   wire        reg_write,
    input   wire [31:0] rd_data,
    input   wire        clk,
    input   wire        rst,
    output  wire [31:0] rs1_val,
    output  wire [31:0] rs2_val,
    output wire [31:0] register_32bits_0_value,
    output wire [31:0] register_32bits_1_value,
    output wire [31:0] register_32bits_2_value,
    output wire [31:0] register_32bits_3_value,
    output wire [31:0] register_32bits_4_value,
    output wire [31:0] register_32bits_5_value,
    output wire [31:0] register_32bits_6_value,
    output wire [31:0] register_32bits_7_value,
    output wire [31:0] register_32bits_8_value,
    output wire [31:0] register_32bits_9_value,
    output wire [31:0] register_32bits_10_value,
    output wire [31:0] register_32bits_11_value,
    output wire [31:0] register_32bits_12_value,
    output wire [31:0] register_32bits_13_value,
    output wire [31:0] register_32bits_14_value,
    output wire [31:0] register_32bits_15_value,
    output wire [31:0] register_32bits_16_value,
    output wire [31:0] register_32bits_17_value,
    output wire [31:0] register_32bits_18_value,
    output wire [31:0] register_32bits_19_value,
    output wire [31:0] register_32bits_20_value,
    output wire [31:0] register_32bits_21_value,
    output wire [31:0] register_32bits_22_value,
    output wire [31:0] register_32bits_23_value,
    output wire [31:0] register_32bits_24_value,
    output wire [31:0] register_32bits_25_value,
    output wire [31:0] register_32bits_26_value,
    output wire [31:0] register_32bits_27_value,
    output wire [31:0] register_32bits_28_value,
    output wire [31:0] register_32bits_29_value,
    output wire [31:0] register_32bits_30_value,
    output wire [31:0] register_32bits_31_value
);
    // wires for register outputs
    wire [31:0] wire_register_32bits_0_reg_out;
    wire [31:0] wire_register_32bits_1_reg_out;
    wire [31:0] wire_register_32bits_2_reg_out;
    wire [31:0] wire_register_32bits_3_reg_out;
    wire [31:0] wire_register_32bits_4_reg_out;
    wire [31:0] wire_register_32bits_5_reg_out;
    wire [31:0] wire_register_32bits_6_reg_out;
    wire [31:0] wire_register_32bits_7_reg_out;
    wire [31:0] wire_register_32bits_8_reg_out;
    wire [31:0] wire_register_32bits_9_reg_out;
    wire [31:0] wire_register_32bits_10_reg_out;
    wire [31:0] wire_register_32bits_11_reg_out;
    wire [31:0] wire_register_32bits_12_reg_out;
    wire [31:0] wire_register_32bits_13_reg_out;
    wire [31:0] wire_register_32bits_14_reg_out;
    wire [31:0] wire_register_32bits_15_reg_out;
    wire [31:0] wire_register_32bits_16_reg_out;
    wire [31:0] wire_register_32bits_17_reg_out;
    wire [31:0] wire_register_32bits_18_reg_out;
    wire [31:0] wire_register_32bits_19_reg_out;
    wire [31:0] wire_register_32bits_20_reg_out;
    wire [31:0] wire_register_32bits_21_reg_out;
    wire [31:0] wire_register_32bits_22_reg_out;
    wire [31:0] wire_register_32bits_23_reg_out;
    wire [31:0] wire_register_32bits_24_reg_out;
    wire [31:0] wire_register_32bits_25_reg_out;
    wire [31:0] wire_register_32bits_26_reg_out;
    wire [31:0] wire_register_32bits_27_reg_out;
    wire [31:0] wire_register_32bits_28_reg_out;
    wire [31:0] wire_register_32bits_29_reg_out;
    wire [31:0] wire_register_32bits_30_reg_out;
    wire [31:0] wire_register_32bits_31_reg_out;

    assign register_32bits_0_value  = wire_register_32bits_0_reg_out;
    assign register_32bits_1_value  = wire_register_32bits_1_reg_out;
    assign register_32bits_2_value  = wire_register_32bits_2_reg_out;
    assign register_32bits_3_value  = wire_register_32bits_3_reg_out;
    assign register_32bits_4_value  = wire_register_32bits_4_reg_out;
    assign register_32bits_5_value  = wire_register_32bits_5_reg_out;
    assign register_32bits_6_value  = wire_register_32bits_6_reg_out;
    assign register_32bits_7_value  = wire_register_32bits_7_reg_out;
    assign register_32bits_8_value  = wire_register_32bits_8_reg_out;
    assign register_32bits_9_value  = wire_register_32bits_9_reg_out;
    assign register_32bits_10_value = wire_register_32bits_10_reg_out;
    assign register_32bits_11_value = wire_register_32bits_11_reg_out;
    assign register_32bits_12_value = wire_register_32bits_12_reg_out;
    assign register_32bits_13_value = wire_register_32bits_13_reg_out;
    assign register_32bits_14_value = wire_register_32bits_14_reg_out;
    assign register_32bits_15_value = wire_register_32bits_15_reg_out;
    assign register_32bits_16_value = wire_register_32bits_16_reg_out;
    assign register_32bits_17_value = wire_register_32bits_17_reg_out;
    assign register_32bits_18_value = wire_register_32bits_18_reg_out;
    assign register_32bits_19_value = wire_register_32bits_19_reg_out;
    assign register_32bits_20_value = wire_register_32bits_20_reg_out;
    assign register_32bits_21_value = wire_register_32bits_21_reg_out;
    assign register_32bits_22_value = wire_register_32bits_22_reg_out;
    assign register_32bits_23_value = wire_register_32bits_23_reg_out;
    assign register_32bits_24_value = wire_register_32bits_24_reg_out;
    assign register_32bits_25_value = wire_register_32bits_25_reg_out;
    assign register_32bits_26_value = wire_register_32bits_26_reg_out;
    assign register_32bits_27_value = wire_register_32bits_27_reg_out;
    assign register_32bits_28_value = wire_register_32bits_28_reg_out;
    assign register_32bits_29_value = wire_register_32bits_29_reg_out;
    assign register_32bits_30_value = wire_register_32bits_30_reg_out;
    assign register_32bits_31_value = wire_register_32bits_31_reg_out;

    register_32bits register_32bits_0 
    (
        .D(32'd0),
        .enable(1'b0),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_0_reg_out)
    );

    register_32bits register_32bits_1 
    (
        .D(rd_data),
        .enable((rd_addr == 5'd1) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_1_reg_out)
    );

    register_32bits register_32bits_2
    (
        .D(rd_data),
        .enable((rd_addr == 5'd2) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_2_reg_out)
    );

    register_32bits register_32bits_3
    (
        .D(rd_data),
        .enable((rd_addr == 5'd3) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_3_reg_out)
    );

    register_32bits register_32bits_4 
    (
        .D(rd_data),
        .enable((rd_addr == 5'd4) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_4_reg_out)
    );

    register_32bits register_32bits_5
    (
        .D(rd_data),
        .enable((rd_addr == 5'd5) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_5_reg_out)
    );

    register_32bits register_32bits_6 
    (
        .D(rd_data),
        .enable((rd_addr == 5'd6) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_6_reg_out)
    );

    register_32bits register_32bits_7 
    (
        .D(rd_data),
        .enable((rd_addr == 5'd7) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_7_reg_out)
    );

    register_32bits register_32bits_8 
    (
        .D(rd_data),
        .enable((rd_addr == 5'd8) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_8_reg_out)
    );

    register_32bits register_32bits_9 
    (
        .D(rd_data),
        .enable((rd_addr == 5'd9) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_9_reg_out)
    );

    register_32bits register_32bits_10 
    (
        .D(rd_data),
        .enable((rd_addr == 5'd10) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_10_reg_out)
    );

    register_32bits register_32bits_11 
    (
        .D(rd_data),
        .enable((rd_addr == 5'd11) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_11_reg_out)
    );

    register_32bits register_32bits_12 
    (
        .D(rd_data),
        .enable((rd_addr == 5'd12) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_12_reg_out)
    );

    register_32bits register_32bits_13 
    (
        .D(rd_data),
        .enable((rd_addr == 5'd13) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_13_reg_out)
    );

    register_32bits register_32bits_14 
    (
        .D(rd_data),
        .enable((rd_addr == 5'd14) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_14_reg_out)
    );

    register_32bits register_32bits_15 
    (
        .D(rd_data),
        .enable((rd_addr == 5'd15) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_15_reg_out)
    );

    register_32bits register_32bits_16
    (
        .D(rd_data),
        .enable((rd_addr == 5'd16) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_16_reg_out)
    );

    register_32bits register_32bits_17
    (
        .D(rd_data),
        .enable((rd_addr == 5'd17) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_17_reg_out)
    );

    register_32bits register_32bits_18
    (
        .D(rd_data),
        .enable((rd_addr == 5'd18) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_18_reg_out)
    );

    register_32bits register_32bits_19
    (
        .D(rd_data),
        .enable((rd_addr == 5'd19) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_19_reg_out)
    );

    register_32bits register_32bits_20
    (
        .D(rd_data),
        .enable((rd_addr == 5'd20) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_20_reg_out)
    );

    register_32bits register_32bits_21
    (
        .D(rd_data),
        .enable((rd_addr == 5'd21) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_21_reg_out)
    );

    register_32bits register_32bits_22
    (
        .D(rd_data),
        .enable((rd_addr == 5'd22) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_22_reg_out)
    );

    register_32bits register_32bits_23
    (
        .D(rd_data),
        .enable((rd_addr == 5'd23) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_23_reg_out)
    );

    register_32bits register_32bits_24
    (
        .D(rd_data),
        .enable((rd_addr == 5'd24) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_24_reg_out)
    );

    register_32bits register_32bits_25
    (
        .D(rd_data),
        .enable((rd_addr == 5'd25) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_25_reg_out)
    );

    register_32bits register_32bits_26
    (
        .D(rd_data),
        .enable((rd_addr == 5'd26) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_26_reg_out)
    );

    register_32bits register_32bits_27
    (
        .D(rd_data),
        .enable((rd_addr == 5'd27) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_27_reg_out)
    );

    register_32bits register_32bits_28
    (
        .D(rd_data),
        .enable((rd_addr == 5'd28) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_28_reg_out)
    );

    register_32bits register_32bits_29
    (
        .D(rd_data),
        .enable((rd_addr == 5'd29) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_29_reg_out)
    );

    register_32bits register_32bits_30
    (
        .D(rd_data),
        .enable((rd_addr == 5'd30) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_30_reg_out)
    );

    register_32bits register_32bits_31
    (
        .D(rd_data),
        .enable((rd_addr == 5'd31) && reg_write),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_register_32bits_31_reg_out)
    );

    mux_32to1_32bits mux_32to1_32bits_0 
    (
        .in0(wire_register_32bits_0_reg_out),
        .in1(wire_register_32bits_1_reg_out),
        .in2(wire_register_32bits_2_reg_out),
        .in3(wire_register_32bits_3_reg_out),
        .in4(wire_register_32bits_4_reg_out),
        .in5(wire_register_32bits_5_reg_out),
        .in6(wire_register_32bits_6_reg_out),
        .in7(wire_register_32bits_7_reg_out),
        .in8(wire_register_32bits_8_reg_out),
        .in9(wire_register_32bits_9_reg_out),
        .in10(wire_register_32bits_10_reg_out),
        .in11(wire_register_32bits_11_reg_out),
        .in12(wire_register_32bits_12_reg_out),
        .in13(wire_register_32bits_13_reg_out),
        .in14(wire_register_32bits_14_reg_out),
        .in15(wire_register_32bits_15_reg_out),
        .in16(wire_register_32bits_16_reg_out),
        .in17(wire_register_32bits_17_reg_out),
        .in18(wire_register_32bits_18_reg_out),
        .in19(wire_register_32bits_19_reg_out),
        .in20(wire_register_32bits_20_reg_out),
        .in21(wire_register_32bits_21_reg_out),
        .in22(wire_register_32bits_22_reg_out),
        .in23(wire_register_32bits_23_reg_out),
        .in24(wire_register_32bits_24_reg_out),
        .in25(wire_register_32bits_25_reg_out),
        .in26(wire_register_32bits_26_reg_out),
        .in27(wire_register_32bits_27_reg_out),
        .in28(wire_register_32bits_28_reg_out),
        .in29(wire_register_32bits_29_reg_out),
        .in30(wire_register_32bits_30_reg_out),
        .in31(wire_register_32bits_31_reg_out),
        .sel(rs1_addr),
        .mux_out(rs1_val)
    );

    mux_32to1_32bits mux_32to1_32bits_1
    (
        .in0(wire_register_32bits_0_reg_out),
        .in1(wire_register_32bits_1_reg_out),
        .in2(wire_register_32bits_2_reg_out),
        .in3(wire_register_32bits_3_reg_out),
        .in4(wire_register_32bits_4_reg_out),
        .in5(wire_register_32bits_5_reg_out),
        .in6(wire_register_32bits_6_reg_out),
        .in7(wire_register_32bits_7_reg_out),
        .in8(wire_register_32bits_8_reg_out),
        .in9(wire_register_32bits_9_reg_out),
        .in10(wire_register_32bits_10_reg_out),
        .in11(wire_register_32bits_11_reg_out),
        .in12(wire_register_32bits_12_reg_out),
        .in13(wire_register_32bits_13_reg_out),
        .in14(wire_register_32bits_14_reg_out),
        .in15(wire_register_32bits_15_reg_out),
        .in16(wire_register_32bits_16_reg_out),
        .in17(wire_register_32bits_17_reg_out),
        .in18(wire_register_32bits_18_reg_out),
        .in19(wire_register_32bits_19_reg_out),
        .in20(wire_register_32bits_20_reg_out),
        .in21(wire_register_32bits_21_reg_out),
        .in22(wire_register_32bits_22_reg_out),
        .in23(wire_register_32bits_23_reg_out),
        .in24(wire_register_32bits_24_reg_out),
        .in25(wire_register_32bits_25_reg_out),
        .in26(wire_register_32bits_26_reg_out),
        .in27(wire_register_32bits_27_reg_out),
        .in28(wire_register_32bits_28_reg_out),
        .in29(wire_register_32bits_29_reg_out),
        .in30(wire_register_32bits_30_reg_out),
        .in31(wire_register_32bits_31_reg_out),
        .sel(rs2_addr),
        .mux_out(rs2_val)
    );
endmodule
