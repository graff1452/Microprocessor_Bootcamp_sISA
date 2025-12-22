module b_mux 
(
    input   wire [31:0] rs2_val,
    input   wire [31:0] imm,
    input   wire        addi,
    input   wire        lw,
    input   wire        lbu,
    input   wire        sw,
    input   wire        sb,
    input   wire        jalr,
    output  wire [31:0] b
);
    assign b = (addi || lw || lbu || sw || sb || jalr) ? imm : rs2_val;
endmodule
