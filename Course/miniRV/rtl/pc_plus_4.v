module pc_plus_4
(
    input   wire [31:0] pc,
    output  wire [31:0] pc_plus_4_out
);
    assign pc_plus_4_out = pc + 4;
endmodule
