module mux_2to1_4bits 
(   
    input   wire    [3:0] in0,
    input   wire    [3:0] in1,
    input   wire          sel, 
    output  wire    [3:0] mux_out
);
    reg [3:0] reg_mux_out;

    always @(*) 
    begin
        case (sel)
            1'b0:       reg_mux_out = in0;
            1'b1:       reg_mux_out = in1;
            default:    reg_mux_out = 4'h0;
        endcase
    end

    assign mux_out = reg_mux_out;
endmodule
