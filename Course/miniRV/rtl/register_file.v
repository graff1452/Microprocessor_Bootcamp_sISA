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
    output wire [31:0] register_32bits_15_value
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

    register_32bits register_32bits_0 
    (
        .D(32'd0),
        .enable((rd_addr == 5'd0) && reg_write),
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

    mux_16to1_32bits mux_16to1_32bits_0 
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
        .sel(rs1_addr[3:0]),
        .mux_out(rs1_val)
    );

    mux_16to1_32bits mux_16to1_32bits_1
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
        .sel(rs2_addr[3:0]),
        .mux_out(rs2_val)
    );
endmodule
