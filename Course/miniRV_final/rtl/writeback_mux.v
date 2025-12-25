module writeback_mux
(
    input   wire [31:0] y,
    input   wire [31:0] imm,
    input   wire [31:0] read_data,
    input   wire [31:0] pc_plus_4,
    input   wire        lw,
    input   wire        lbu,
    input   wire        lui,
    input   wire        jalr,
    output  wire [31:0] rd_data
);

    assign rd_data =
        (lw  || lbu) ? read_data :
        (lui)        ? imm       :
        (jalr)       ? pc_plus_4  :
                       y;
endmodule
