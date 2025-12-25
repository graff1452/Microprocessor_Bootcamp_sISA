module top
(
    input   wire        clk,
    input   wire        rst,
    output  wire [31:0] pc_out,
    output  wire [31:0] instruction,
    output  wire        halt,
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
    output  wire [31:0] reg15_val,
    output  wire [31:0] reg16_val,
    output  wire [31:0] reg17_val,
    output  wire [31:0] reg18_val,
    output  wire [31:0] reg19_val,
    output  wire [31:0] reg20_val,
    output  wire [31:0] reg21_val,
    output  wire [31:0] reg22_val,
    output  wire [31:0] reg23_val,
    output  wire [31:0] reg24_val,
    output  wire [31:0] reg25_val,
    output  wire [31:0] reg26_val,
    output  wire [31:0] reg27_val,
    output  wire [31:0] reg28_val,
    output  wire [31:0] reg29_val,
    output  wire [31:0] reg30_val,
    output  wire [31:0] reg31_val
);
    // wires for pc
    wire [31:0] wire_pc_pc_out;

    // wires for my_decoder
    wire [6:0] wire_my_decoder_opcode;
    wire [4:0] wire_my_decoder_rd;
    wire [2:0] wire_my_decoder_funct3;
    wire [4:0] wire_my_decoder_rs1;
    wire [4:0] wire_my_decoder_rs2;
    wire [6:0] wire_my_decoder_funct7;
    wire       wire_my_decoder_ebreak;

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
    wire [31:0] wire_register_file_reg16_val;
    wire [31:0] wire_register_file_reg17_val;
    wire [31:0] wire_register_file_reg18_val;
    wire [31:0] wire_register_file_reg19_val;
    wire [31:0] wire_register_file_reg20_val;
    wire [31:0] wire_register_file_reg21_val;
    wire [31:0] wire_register_file_reg22_val;
    wire [31:0] wire_register_file_reg23_val;
    wire [31:0] wire_register_file_reg24_val;
    wire [31:0] wire_register_file_reg25_val;
    wire [31:0] wire_register_file_reg26_val;
    wire [31:0] wire_register_file_reg27_val;
    wire [31:0] wire_register_file_reg28_val;
    wire [31:0] wire_register_file_reg29_val;
    wire [31:0] wire_register_file_reg30_val;
    wire [31:0] wire_register_file_reg31_val;


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

    // wires for b_mux
    wire [31:0] wire_b_mux_b;

    // wires for alu
    wire [31:0] wire_alu_y;

    // wires for writeback_mux
    wire [31:0] wire_writeback_mux_rd_data;

    // wires for pc_plus_4
    wire [31:0] wire_pc_plus_4_pc_plus_4_out;

    // wires for next_pc
    wire [31:0] wire_next_pc_pc_next;

    // wires for reg_write_enabler
    wire wire_reg_write_enabler_reg_write;

    // wires for unified_memory
    wire [31:0] wire_unified_memory_i_rdata;
    wire [31:0] wire_unified_memory_d_rdata;

    // wires for memory_control
    wire [31:0] wire_memory_control_d_addr;
    wire [31:0] wire_memory_control_d_wdata;
    wire [3:0]  wire_memory_control_d_wstrb;
    wire        wire_memory_control_d_we;
    wire [31:0] wire_memory_control_load_data;
    
    // -------------------------------------------------------------------------
    // PC register
    // -------------------------------------------------------------------------
    pc pc_0 
    (
        .D      (wire_next_pc_pc_next),
        .enable (~wire_my_decoder_ebreak),
        .clk    (clk),
        .rst    (rst),
        .pc_out (wire_pc_pc_out)
    );

    unified_memory unified_memory_0
    (
        .i_addr    (wire_pc_pc_out),
        .i_rdata   (wire_unified_memory_i_rdata),
        .d_addr    (wire_memory_control_d_addr),
        .d_wdata   (wire_memory_control_d_wdata),
        .d_wstrb   (wire_memory_control_d_wstrb),
        .d_we      (wire_memory_control_d_we),
        .d_rdata   (wire_unified_memory_d_rdata),
        .clk       (clk)
    );

    memory_control memory_control_0
    (
        .y                  (wire_alu_y),
        .rs2_val            (wire_register_file_rs2_val),
        .lw                 (wire_which_instruction_lw),
        .lbu                (wire_which_instruction_lbu),
        .sw                 (wire_which_instruction_sw),
        .sb                 (wire_which_instruction_sb),
        .ebreak             (wire_my_decoder_ebreak),
        .d_rdata_word       (wire_unified_memory_d_rdata),
        .d_addr             (wire_memory_control_d_addr),
        .d_wdata            (wire_memory_control_d_wdata),
        .d_wstrb            (wire_memory_control_d_wstrb),
        .d_we               (wire_memory_control_d_we),
        .load_data          (wire_memory_control_load_data)
    );

    // -------------------------------------------------------------------------
    // Instruction field decoder
    // -------------------------------------------------------------------------
    my_decoder my_decoder_0 
    (
        .instruction (wire_unified_memory_i_rdata),
        .opcode      (wire_my_decoder_opcode),
        .rd          (wire_my_decoder_rd),
        .funct3      (wire_my_decoder_funct3),
        .rs1         (wire_my_decoder_rs1),
        .rs2         (wire_my_decoder_rs2),
        .funct7      (wire_my_decoder_funct7),
        .ebreak      (wire_my_decoder_ebreak)
    );

    // -------------------------------------------------------------------------
    // which_type: drives immediate format generation
    // -------------------------------------------------------------------------
    which_type which_type_0
    (
        .opcode (wire_my_decoder_opcode),
        .r_type (wire_which_type_r_type),
        .i_type (wire_which_type_i_type),
        .s_type (wire_which_type_s_type),
        .u_type (wire_which_type_u_type)
    );

    // -------------------------------------------------------------------------
    // which_instruction: real control decode (instruction-exact)
    // -------------------------------------------------------------------------
    which_instruction which_instruction_0
    (
        .opcode  (wire_my_decoder_opcode),
        .funct3  (wire_my_decoder_funct3),
        .funct7  (wire_my_decoder_funct7),
        .ebreak  (wire_my_decoder_ebreak),
        .add     (wire_which_instruction_add),
        .addi    (wire_which_instruction_addi),
        .lui     (wire_which_instruction_lui),
        .lw      (wire_which_instruction_lw),
        .lbu     (wire_which_instruction_lbu),
        .sw      (wire_which_instruction_sw),
        .sb      (wire_which_instruction_sb),
        .jalr    (wire_which_instruction_jalr),
        .illegal (wire_which_instruction_illegal)
    );

    // -------------------------------------------------------------------------
    // Immediate generator
    // -------------------------------------------------------------------------
    immediate_generator immediate_generator_0
    (
        .instruction (wire_unified_memory_i_rdata),
        .illegal     (wire_which_instruction_illegal),
        .r_type      (wire_which_type_r_type),
        .i_type      (wire_which_type_i_type),
        .s_type      (wire_which_type_s_type),
        .u_type      (wire_which_type_u_type),
        .imm         (wire_immediate_generator_imm)
    );

    // -------------------------------------------------------------------------
    // Register write enable
    // -------------------------------------------------------------------------
    reg_write_enabler reg_write_enabler_0
    (
        .add      (wire_which_instruction_add),
        .addi     (wire_which_instruction_addi),
        .lui      (wire_which_instruction_lui),
        .lw       (wire_which_instruction_lw),
        .lbu      (wire_which_instruction_lbu),
        .jalr     (wire_which_instruction_jalr),
        .illegal  (wire_which_instruction_illegal),
        .ebreak   (wire_my_decoder_ebreak),
        .reg_write(wire_reg_write_enabler_reg_write)
    );

    // -------------------------------------------------------------------------
    // Register file (16 regs: x0..x15)
    // -------------------------------------------------------------------------
    register_file register_file_0
    (
        .rs1_addr                   (wire_my_decoder_rs1),
        .rs2_addr                   (wire_my_decoder_rs2),
        .rd_addr                    (wire_my_decoder_rd),
        .reg_write                  (wire_reg_write_enabler_reg_write),
        .rd_data                    (wire_writeback_mux_rd_data),
        .clk                        (clk),
        .rst                        (rst),
        .rs1_val                    (wire_register_file_rs1_val),
        .rs2_val                    (wire_register_file_rs2_val),
        .register_32bits_0_value    (wire_register_file_reg0_val),
        .register_32bits_1_value    (wire_register_file_reg1_val),
        .register_32bits_2_value    (wire_register_file_reg2_val),
        .register_32bits_3_value    (wire_register_file_reg3_val),
        .register_32bits_4_value    (wire_register_file_reg4_val),
        .register_32bits_5_value    (wire_register_file_reg5_val),
        .register_32bits_6_value    (wire_register_file_reg6_val),
        .register_32bits_7_value    (wire_register_file_reg7_val),
        .register_32bits_8_value    (wire_register_file_reg8_val),
        .register_32bits_9_value    (wire_register_file_reg9_val),
        .register_32bits_10_value   (wire_register_file_reg10_val),
        .register_32bits_11_value   (wire_register_file_reg11_val),
        .register_32bits_12_value   (wire_register_file_reg12_val),
        .register_32bits_13_value   (wire_register_file_reg13_val),
        .register_32bits_14_value   (wire_register_file_reg14_val),
        .register_32bits_15_value   (wire_register_file_reg15_val),
        .register_32bits_16_value   (wire_register_file_reg16_val),
        .register_32bits_17_value   (wire_register_file_reg17_val),
        .register_32bits_18_value   (wire_register_file_reg18_val),
        .register_32bits_19_value   (wire_register_file_reg19_val),
        .register_32bits_20_value   (wire_register_file_reg20_val),
        .register_32bits_21_value   (wire_register_file_reg21_val),
        .register_32bits_22_value   (wire_register_file_reg22_val),
        .register_32bits_23_value   (wire_register_file_reg23_val),
        .register_32bits_24_value   (wire_register_file_reg24_val),
        .register_32bits_25_value   (wire_register_file_reg25_val),
        .register_32bits_26_value   (wire_register_file_reg26_val),
        .register_32bits_27_value   (wire_register_file_reg27_val),
        .register_32bits_28_value   (wire_register_file_reg28_val),
        .register_32bits_29_value   (wire_register_file_reg29_val),
        .register_32bits_30_value   (wire_register_file_reg30_val),
        .register_32bits_31_value   (wire_register_file_reg31_val)
    );

    // -------------------------------------------------------------------------
    // B mux: selects rs2 or immediate for ALU B input
    // -------------------------------------------------------------------------
    b_mux b_mux_0
    (
        .rs2_val (wire_register_file_rs2_val),
        .imm     (wire_immediate_generator_imm),
        .addi    (wire_which_instruction_addi),
        .lw      (wire_which_instruction_lw),
        .lbu     (wire_which_instruction_lbu),
        .sw      (wire_which_instruction_sw),
        .sb      (wire_which_instruction_sb),
        .jalr    (wire_which_instruction_jalr),
        .b       (wire_b_mux_b)
    );

    // -------------------------------------------------------------------------
    // ALU (add only)
    // -------------------------------------------------------------------------
    alu alu_0
    (
        .a (wire_register_file_rs1_val),
        .b (wire_b_mux_b),
        .y (wire_alu_y)
    );

    // -------------------------------------------------------------------------
    // PC+4
    // -------------------------------------------------------------------------
    pc_plus_4 pc_plus_4_0
    (
        .pc          (wire_pc_pc_out),
        .pc_plus_4_out(wire_pc_plus_4_pc_plus_4_out)
    );

    // -------------------------------------------------------------------------
    // Writeback mux (rd_data)
    // -------------------------------------------------------------------------
    writeback_mux writeback_mux_0
    (
        .y         (wire_alu_y),
        .imm       (wire_immediate_generator_imm),
        .read_data (wire_memory_control_load_data),
        .pc_plus_4 (wire_pc_plus_4_pc_plus_4_out),
        .lw        (wire_which_instruction_lw),
        .lbu       (wire_which_instruction_lbu),
        .lui       (wire_which_instruction_lui),
        .jalr      (wire_which_instruction_jalr),
        .rd_data   (wire_writeback_mux_rd_data)
    );

    // -------------------------------------------------------------------------
    // Next PC select
    // -------------------------------------------------------------------------
    next_pc next_pc_0
    (
        .pc_plus_4 (wire_pc_plus_4_pc_plus_4_out),
        .y         (wire_alu_y),
        .jalr      (wire_which_instruction_jalr),
        .pc_next   (wire_next_pc_pc_next)
    );

    // -------------------------------------------------------------------------
    // Top-level debug outputs
    // -------------------------------------------------------------------------
    assign pc_out      = wire_pc_pc_out;
    assign instruction = wire_unified_memory_i_rdata;
    assign halt        = wire_my_decoder_ebreak;

    assign reg0_val  = wire_register_file_reg0_val;
    assign reg1_val  = wire_register_file_reg1_val;
    assign reg2_val  = wire_register_file_reg2_val;
    assign reg3_val  = wire_register_file_reg3_val;
    assign reg4_val  = wire_register_file_reg4_val;
    assign reg5_val  = wire_register_file_reg5_val;
    assign reg6_val  = wire_register_file_reg6_val;
    assign reg7_val  = wire_register_file_reg7_val;
    assign reg8_val  = wire_register_file_reg8_val;
    assign reg9_val  = wire_register_file_reg9_val;
    assign reg10_val = wire_register_file_reg10_val;
    assign reg11_val = wire_register_file_reg11_val;
    assign reg12_val = wire_register_file_reg12_val;
    assign reg13_val = wire_register_file_reg13_val;
    assign reg14_val = wire_register_file_reg14_val;
    assign reg15_val = wire_register_file_reg15_val;
    assign reg16_val  = wire_register_file_reg16_val;
    assign reg17_val  = wire_register_file_reg17_val;
    assign reg18_val  = wire_register_file_reg18_val;
    assign reg19_val  = wire_register_file_reg19_val;
    assign reg20_val  = wire_register_file_reg20_val;
    assign reg21_val  = wire_register_file_reg21_val;
    assign reg22_val  = wire_register_file_reg22_val;
    assign reg23_val  = wire_register_file_reg23_val;
    assign reg24_val  = wire_register_file_reg24_val;
    assign reg25_val  = wire_register_file_reg25_val;
    assign reg26_val = wire_register_file_reg26_val;
    assign reg27_val = wire_register_file_reg27_val;
    assign reg28_val = wire_register_file_reg28_val;
    assign reg29_val = wire_register_file_reg29_val;
    assign reg30_val = wire_register_file_reg30_val;
    assign reg31_val = wire_register_file_reg31_val;

endmodule
