module which_type 
(
    input wire [1:0]    op,
    output wire         add,
    output wire         li,
    output wire         bne,
    output wire         empty_inst
);  
    reg reg_add;
    reg reg_li;
    reg reg_bne;
    reg reg_empty_inst;

    always @(*)
    begin
        case (op)
            2'b00: begin reg_add = 1'b1; reg_li = 1'b0; reg_bne = 1'b0; reg_empty_inst = 1'b0; end
            2'b01: begin reg_add = 1'b0; reg_li = 1'b0; reg_bne = 1'b0; reg_empty_inst = 1'b1; end
            2'b10: begin reg_add = 1'b0; reg_li = 1'b1; reg_bne = 1'b0; reg_empty_inst = 1'b0; end
            2'b11: begin reg_add = 1'b0; reg_li = 1'b0; reg_bne = 1'b1; reg_empty_inst = 1'b0; end
        endcase
    end
    assign add  = reg_add;
    assign li   = reg_li;
    assign bne  = reg_bne;
    assign empty_inst = reg_empty_inst;
endmodule
