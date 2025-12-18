module mux_2to1_8bits 
(   
    input   wire    [7:0] in0,
    input   wire    [7:0] in1,
    input   wire          sel, 
    output  wire    [7:0] mux_out
);
    reg [7:0] reg_mux_out;

    always @(*) 
    begin
        case (sel)
            1'b0:       reg_mux_out = in0;
            1'b1:       reg_mux_out = in1;
            default:    reg_mux_out = 8'b0;
        endcase
    end

    assign mux_out = reg_mux_out;
endmodule
