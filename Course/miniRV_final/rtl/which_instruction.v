module which_instruction
(
    input   wire [6:0]  opcode,
    input   wire [2:0]  funct3,
    input   wire [6:0]  funct7,
    input   wire        ebreak,
    output  wire        add,
    output  wire        addi,
    output  wire        lui,
    output  wire        lw,
    output  wire        lbu,
    output  wire        sw,
    output  wire        sb,
    output  wire        jalr,
    output  wire        illegal
);

    localparam [6:0] OPCODE_RTYPE  = 7'b0110011; // 0x33
    localparam [6:0] OPCODE_ITYPE  = 7'b0010011; // addi
    localparam [6:0] OPCODE_LOAD   = 7'b0000011; // lw/lbu
    localparam [6:0] OPCODE_STORE  = 7'b0100011; // sw/sb
    localparam [6:0] OPCODE_LUI    = 7'b0110111; // lui
    localparam [6:0] OPCODE_JALR   = 7'b1100111; // jalr

    assign add  = (opcode == OPCODE_RTYPE) && (funct3 == 3'b000) && (funct7 == 7'b0000000) && ~ebreak;
    assign addi = (opcode == OPCODE_ITYPE) && (funct3 == 3'b000) && ~ebreak;
    assign lui  = (opcode == OPCODE_LUI) && ~ebreak;
    assign lw   = (opcode == OPCODE_LOAD)  && (funct3 == 3'b010) && ~ebreak;
    assign lbu  = (opcode == OPCODE_LOAD)  && (funct3 == 3'b100) && ~ebreak;
    assign sw   = (opcode == OPCODE_STORE) && (funct3 == 3'b010) && ~ebreak;
    assign sb   = (opcode == OPCODE_STORE) && (funct3 == 3'b000) && ~ebreak;
    assign jalr = (opcode == OPCODE_JALR)  && (funct3 == 3'b000) && ~ebreak;
    assign illegal = ~(add | addi | lui | lw | lbu | sw | sb | jalr) && ~ebreak;
endmodule
