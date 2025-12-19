module register_4bits 
(
    input   wire [3:0]      D,
    input   wire            WE,
    input   wire            clk,
    input   wire            rst,
    output  wire [3:0]      Q
);
    reg [3:0] reg_Q;
    
    always @(posedge clk or posedge rst)
    begin
        if (rst) 
        begin
            reg_Q <= 4'b0;
        end
        else 
        begin
            if (clk) 
            begin
                if (WE) 
                begin
                    reg_Q <= D;
                end
            end
        end
    end

    assign Q = reg_Q;
endmodule
