module reg_enabler 
(
    input   wire [1:0]  rd,
    input   wire        bne,
    input   wire        empty_inst,
    output  wire        reg0_en,
    output  wire        reg1_en,
    output  wire        reg2_en,
    output  wire        reg3_en 
);
    reg reg_reg0_en;
    reg reg_reg1_en;
    reg reg_reg2_en;
    reg reg_reg3_en;
    always @(*) 
    begin
        reg_reg0_en = 1'b0;
        reg_reg1_en = 1'b0;
        reg_reg2_en = 1'b0;
        reg_reg3_en = 1'b0;

        if (~bne) 
        begin
            if (empty_inst == 1'b0)
            begin
                case (rd)
                    2'b00: reg_reg0_en = 1'b1;
                    2'b01: reg_reg1_en = 1'b1;
                    2'b10: reg_reg2_en = 1'b1;
                    2'b11: reg_reg3_en = 1'b1;
                endcase
            end
        end
    end
    assign reg0_en = reg_reg0_en;
    assign reg1_en = reg_reg1_en;
    assign reg2_en = reg_reg2_en;
    assign reg3_en = reg_reg3_en;
endmodule
