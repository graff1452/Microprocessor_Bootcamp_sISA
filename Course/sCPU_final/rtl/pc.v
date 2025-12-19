module pc 
(
    input   wire [3:0]  D,
    input   wire        enable,
    input   wire        clk,
    input   wire        rst,
    output  wire [3:0]  pc_out
);
    register_4bits register_4bits_1 
    (
        .D(D),
        .WE(enable),
        .clk(clk),
        .rst(rst),
        .Q(pc_out)
    );
    endmodule
