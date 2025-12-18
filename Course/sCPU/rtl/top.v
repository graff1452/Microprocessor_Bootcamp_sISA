module top
(
    input wire clk,
    input wire rst,
    output wire [3:0] pc_out,
    output wire [7:0] instruction,
    output wire [7:0] reg0_out,
    output wire [7:0] reg1_out,
    output wire [7:0] reg2_out,
    output wire [7:0] reg3_out,
    output wire [7:0] alu_out
);
    // wire for pc
    wire [3:0] wire_pc_pc_out;

    //wire for instruction memory
    wire [7:0] wire_instruction_memory_instruction;

    // wire for decoder
    wire [1:0] wire_my_decoder_op;
    wire [1:0] wire_my_decoder_rd;
    wire [1:0] wire_my_decoder_rs1;
    wire [1:0] wire_my_decoder_rs2;
    wire [3:0] wire_my_decoder_addr;
    wire [3:0] wire_my_decoder_imm;

    // wire for which_type
    wire wire_which_type_add;
    wire wire_which_type_li;
    wire wire_which_type_bne;

    // wire for PC_changer
    wire [3:0] wire_pc_changer_changer_out;

    // wire for selector
    wire [7:0] wire_selector_A;
    wire [7:0] wire_selector_B;

    // wire for ALU
    wire [7:0]  wire_alu_alu_out;
    wire        wire_alu_equal;

    // wire for reg_enabler
    wire wire_reg_enabler_reg0_en;
    wire wire_reg_enabler_reg1_en;
    wire wire_reg_enabler_reg2_en;
    wire wire_reg_enabler_reg3_en;

    // wire for reg0
    wire [7:0] wire_reg0_reg_out;

    // wire for reg1
    wire [7:0] wire_reg1_reg_out;

    // wire for reg2
    wire [7:0] wire_reg2_reg_out;

    // wire for reg3
    wire [7:0] wire_reg3_reg_out;

    pc pc_1 
    (
        .D(wire_pc_changer_changer_out),
        .enable(1'b1),
        .clk(clk),
        .rst(rst),
        .pc_out(wire_pc_pc_out)
    );

    instruction_memory instruction_memory_1 
    (
        .sel(wire_pc_pc_out),
        .instruction(wire_instruction_memory_instruction)
    );

    my_decoder my_decoder_1 
    (
        .D(wire_instruction_memory_instruction),
        .op(wire_my_decoder_op),
        .rd(wire_my_decoder_rd),
        .rs1(wire_my_decoder_rs1),
        .rs2(wire_my_decoder_rs2),
        .addr(wire_my_decoder_addr),
        .imm(wire_my_decoder_imm)
    );

    which_type which_type_1 
    (
        .op(wire_my_decoder_op),
        .add(wire_which_type_add),
        .li(wire_which_type_li),
        .bne(wire_which_type_bne)
    );

    pc_changer pc_changer_1 
    (
        .PC(wire_pc_pc_out),
        .add(wire_which_type_add),
        .li(wire_which_type_li),
        .addr(wire_my_decoder_addr),
        .equal(wire_alu_equal),
        .changer_out(wire_pc_changer_changer_out)
    );

    selector selector_1 
    (
        .rs1(wire_my_decoder_rs1),
        .rs2(wire_my_decoder_rs2),
        .reg0_in(wire_reg0_reg_out),
        .reg1_in(wire_reg1_reg_out),
        .reg2_in(wire_reg2_reg_out),
        .reg3_in(wire_reg3_reg_out),
        .A(wire_selector_A),
        .B(wire_selector_B)
    );

    alu alu_1
    (
        .A(wire_selector_A),
        .B(wire_selector_B),
        .imm(wire_my_decoder_imm),
        .reg0_val(wire_reg0_reg_out),
        .add(wire_which_type_add),
        .ALU_out(wire_alu_alu_out),
        .equal(wire_alu_equal)
    );

    reg_enabler reg_enabler_1 
    (
        .rd(wire_my_decoder_rd),
        .bne(wire_which_type_bne),
        .reg0_en(wire_reg_enabler_reg0_en),
        .reg1_en(wire_reg_enabler_reg1_en),
        .reg2_en(wire_reg_enabler_reg2_en),
        .reg3_en(wire_reg_enabler_reg3_en)
    );

    register_8bits reg0 
    (
        .D(wire_alu_alu_out),
        .enable(wire_reg_enabler_reg0_en),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_reg0_reg_out)
    );

    register_8bits reg1 
    (
        .D(wire_alu_alu_out),
        .enable(wire_reg_enabler_reg1_en),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_reg1_reg_out)
    );

    register_8bits reg2 
    (
        .D(wire_alu_alu_out),
        .enable(wire_reg_enabler_reg2_en),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_reg2_reg_out)
    );

    register_8bits reg3 
    (
        .D(wire_alu_alu_out),
        .enable(wire_reg_enabler_reg3_en),
        .clk(clk),
        .rst(rst),
        .reg_out(wire_reg3_reg_out)
    );

    assign pc_out = wire_pc_pc_out;
    assign instruction = wire_instruction_memory_instruction;
    assign reg0_out = wire_reg0_reg_out;
    assign reg1_out = wire_reg1_reg_out;
    assign reg2_out = wire_reg2_reg_out;
    assign reg3_out = wire_reg3_reg_out;
    assign alu_out = wire_alu_alu_out;
endmodule
