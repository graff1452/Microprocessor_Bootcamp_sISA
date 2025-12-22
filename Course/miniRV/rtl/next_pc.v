module next_pc 
(
    input   wire [31:0] pc_plus_4,
    input   wire [31:0] y,
    input   wire        jalr,
    output  wire [31:0] pc_next
);
    assign pc_next = jalr ? (y & 32'hFFFF_FFFC) : pc_plus_4;
endmodule
