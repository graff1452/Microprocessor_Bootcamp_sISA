module pc
(
    input  wire [31:0]  D,
    input  wire         enable,
    input  wire         clk,
    input  wire         rst,
    output wire [31:0]  pc_out
);
    reg [31:0] reg_pc_out;
    always @(posedge clk or posedge rst)
    begin
        if (rst) 
        begin
            reg_pc_out <= 32'h80000000;
        end else if (enable) 
        begin
            reg_pc_out <= D;
        end
    end
    assign pc_out = reg_pc_out;
endmodule
