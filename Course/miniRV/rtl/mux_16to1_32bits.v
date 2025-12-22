module mux_16to1_32bits 
(   
    input   wire    [31:0]  in0,
    input   wire    [31:0]  in1,
    input   wire    [31:0]  in2,
    input   wire    [31:0]  in3,
    input   wire    [31:0]  in4,
    input   wire    [31:0]  in5,
    input   wire    [31:0]  in6,
    input   wire    [31:0]  in7,
    input   wire    [31:0]  in8,
    input   wire    [31:0]  in9,
    input   wire    [31:0]  in10,
    input   wire    [31:0]  in11,
    input   wire    [31:0]  in12,
    input   wire    [31:0]  in13,
    input   wire    [31:0]  in14,
    input   wire    [31:0]  in15,
    input   wire    [3:0]   sel, 
    output  wire    [31:0]  mux_out
);
    reg [31:0] reg_mux_out;

    always @(*) 
    begin
        case (sel)
            4'b0000: reg_mux_out = in0;
            4'b0001: reg_mux_out = in1;
            4'b0010: reg_mux_out = in2;
            4'b0011: reg_mux_out = in3;
            4'b0100: reg_mux_out = in4;
            4'b0101: reg_mux_out = in5;
            4'b0110: reg_mux_out = in6;
            4'b0111: reg_mux_out = in7;
            4'b1000: reg_mux_out = in8;
            4'b1001: reg_mux_out = in9;
            4'b1010: reg_mux_out = in10;
            4'b1011: reg_mux_out = in11;
            4'b1100: reg_mux_out = in12;
            4'b1101: reg_mux_out = in13;
            4'b1110: reg_mux_out = in14;
            4'b1111: reg_mux_out = in15;
            default: reg_mux_out = 32'd0;
        endcase
    end

    assign mux_out = reg_mux_out;
endmodule
