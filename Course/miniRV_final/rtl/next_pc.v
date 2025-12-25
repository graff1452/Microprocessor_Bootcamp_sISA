module next_pc 
(
    input   wire [31:0] pc_plus_4,
    input   wire [31:0] y,
    input   wire        jalr,
    output  wire [31:0] pc_next
);
    assign pc_next = jalr ? {y[31:1], 1'b0} : pc_plus_4;
endmodule
