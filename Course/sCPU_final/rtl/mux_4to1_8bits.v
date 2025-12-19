module mux_4to1_8bits 
(   
    input   wire    [7:0] in0,
    input   wire    [7:0] in1,
    input   wire    [7:0] in2,
    input   wire    [7:0] in3,
    input   wire    [1:0] sel, 
    output  wire    [7:0] mux_out
);
    reg [7:0] reg_mux_out;

    always @(*) 
    begin
        case (sel)
            2'b00:      reg_mux_out = in0;
            2'b01:      reg_mux_out = in1;
            2'b10:      reg_mux_out = in2;
            2'b11:      reg_mux_out = in3;
            default:    reg_mux_out = 0;
        endcase
    end
    assign mux_out = reg_mux_out;
endmodule
