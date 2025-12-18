module my_decoder 
(
    input   wire [7:0] D,
    output  wire [1:0] op,
    output  wire [1:0] rd,
    output  wire [1:0] rs1,
    output  wire [1:0] rs2,
    output  wire [3:0] addr,
    output  wire [3:0] imm
);
    assign op   = D[7:6];
    assign rd   = D[5:4];
    assign rs1  = D[3:2];
    assign rs2  = D[1:0];
    assign addr = D[5:2];
    assign imm  = D[3:0];
endmodule
