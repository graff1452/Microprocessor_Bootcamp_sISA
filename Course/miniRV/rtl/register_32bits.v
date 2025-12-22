module register_32bits 
(
    input   wire [31:0]     D,
    input   wire            enable,
    input   wire            clk,
    input   wire            rst,
    output  wire [31:0]     reg_out
);
    reg [31:0] reg_reg_out;
    
    always @(posedge clk or posedge rst)
    begin
        if (rst) 
        begin
            reg_reg_out <= 32'b0;
        end
        else 
        begin
            if (clk) 
            begin
                if (enable) 
                begin
                    reg_reg_out <= D;
                end
            end
        end
    end

    assign reg_out = reg_reg_out;
endmodule
