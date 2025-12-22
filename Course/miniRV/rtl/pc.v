module pc 
(
    input   wire [31:0]     D,
    input   wire            enable,
    input   wire            clk,
    input   wire            rst,
    output  wire [31:0]     pc_out
);
    register_32bits register_32bits_0
    (
        .D(D),
        .enable(enable),
        .clk(clk),
        .rst(rst),
        .reg_out(pc_out)
    );
    endmodule
