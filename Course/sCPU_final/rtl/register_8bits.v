module register_8bits 
(
    input   wire [7:0]      D,
    input   wire            enable,
    input   wire            clk,
    input   wire            rst,
    output  wire [7:0]      reg_out
);
    reg [7:0] reg_reg_out;
    
    always @(posedge clk or posedge rst)
    begin
        if (rst) 
        begin
            reg_reg_out <= 8'b0;
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
