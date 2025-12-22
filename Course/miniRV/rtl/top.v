module top
(
    input   wire        clk,
    input   wire        rst,
    output  wire [31:0] pc_out,
    output  wire [31:0] instruction,
    output  wire [31:0] reg0_val,
    output  wire [31:0] reg1_val,
    output  wire [31:0] reg2_val,
    output  wire [31:0] reg3_val,
    output  wire [31:0] reg4_val,
    output  wire [31:0] reg5_val,
    output  wire [31:0] reg6_val,
    output  wire [31:0] reg7_val,
    output  wire [31:0] reg8_val,
    output  wire [31:0] reg9_val,
    output  wire [31:0] reg10_val,
    output  wire [31:0] reg11_val,
    output  wire [31:0] reg12_val,
    output  wire [31:0] reg13_val,
    output  wire [31:0] reg14_val,
    output  wire [31:0] reg15_val
);
    // wires for pc
    wire [31:0] wire_pc_pc_out;

    // wires for instruction-memory
    wire [31:0] wire_instruction_memory_instruction;

    // wires for my_decoder
    wire [6:0] wire_my_decoder_opcode;
    wire [4:0] wire_my_decoder_rd;
    wire [2:0] wire_my_decoder_funct3;
    wire [4:0] wire_my_decoder_rs1;
    wire [4:0] wire_my_decoder_rs2;
    wire [6:0] wire_my_decoder_funct7;

    // wires for which_type
    wire wire_which_type_r_type;
    wire wire_which_type_i_type;
    wire wire_which_type_s_type;
    wire wire_which_type_u_type;

    // wires for register_file
    wire [31:0] wire_register_file_rs1_val;
    wire [31:0] wire_register_file_rs2_val;
    wire [31:0] wire_register_file_reg0_val;
    wire [31:0] wire_register_file_reg1_val;
    wire [31:0] wire_register_file_reg2_val;
    wire [31:0] wire_register_file_reg3_val;
    wire [31:0] wire_register_file_reg4_val;
    wire [31:0] wire_register_file_reg5_val;
    wire [31:0] wire_register_file_reg6_val;
    wire [31:0] wire_register_file_reg7_val;
    wire [31:0] wire_register_file_reg8_val;
    wire [31:0] wire_register_file_reg9_val;
    wire [31:0] wire_register_file_reg10_val;
    wire [31:0] wire_register_file_reg11_val;
    wire [31:0] wire_register_file_reg12_val;
    wire [31:0] wire_register_file_reg13_val;
    wire [31:0] wire_register_file_reg14_val;
    wire [31:0] wire_register_file_reg15_val;

    // wires for immediate_generator
    wire [31:0] wire_immediate_generator_imm;

    // wires for which_instruction
    wire wire_which_instruction_add;
    wire wire_which_instruction_addi;
    wire wire_which_instruction_lui;
    wire wire_which_instruction_lw;
    wire wire_which_instruction_lbu;
    wire wire_which_instruction_sw;
    wire wire_which_instruction_sb;
    wire wire_which_instruction_jalr;
    wire wire_which_instruction_illegal;

    

endmodule
