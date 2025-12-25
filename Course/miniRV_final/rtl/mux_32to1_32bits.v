module mux_32to1_32bits 
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
    input   wire    [31:0]  in16,
    input   wire    [31:0]  in17,
    input   wire    [31:0]  in18,
    input   wire    [31:0]  in19,
    input   wire    [31:0]  in20,
    input   wire    [31:0]  in21,
    input   wire    [31:0]  in22,
    input   wire    [31:0]  in23,
    input   wire    [31:0]  in24,
    input   wire    [31:0]  in25,
    input   wire    [31:0]  in26,
    input   wire    [31:0]  in27,
    input   wire    [31:0]  in28,
    input   wire    [31:0]  in29,
    input   wire    [31:0]  in30,
    input   wire    [31:0]  in31,
    input   wire    [4:0]   sel, 
    output  wire    [31:0]  mux_out
);
    reg [31:0] reg_mux_out;

    always @(*) 
    begin
        case (sel)
            5'b00000: reg_mux_out = in0;
            5'b00001: reg_mux_out = in1;
            5'b00010: reg_mux_out = in2;
            5'b00011: reg_mux_out = in3;
            5'b00100: reg_mux_out = in4;
            5'b00101: reg_mux_out = in5;
            5'b00110: reg_mux_out = in6;
            5'b00111: reg_mux_out = in7;
            5'b01000: reg_mux_out = in8;
            5'b01001: reg_mux_out = in9;
            5'b01010: reg_mux_out = in10;
            5'b01011: reg_mux_out = in11;
            5'b01100: reg_mux_out = in12;
            5'b01101: reg_mux_out = in13;
            5'b01110: reg_mux_out = in14;
            5'b01111: reg_mux_out = in15;
            5'b10000: reg_mux_out = in16;
            5'b10001: reg_mux_out = in17;
            5'b10010: reg_mux_out = in18;
            5'b10011: reg_mux_out = in19;
            5'b10100: reg_mux_out = in20;
            5'b10101: reg_mux_out = in21;
            5'b10110: reg_mux_out = in22;
            5'b10111: reg_mux_out = in23;
            5'b11000: reg_mux_out = in24;
            5'b11001: reg_mux_out = in25;
            5'b11010: reg_mux_out = in26;
            5'b11011: reg_mux_out = in27;
            5'b11100: reg_mux_out = in28;
            5'b11101: reg_mux_out = in29;
            5'b11110: reg_mux_out = in30;
            5'b11111: reg_mux_out = in31;
            default: reg_mux_out = 32'd0;
        endcase
    end

    assign mux_out = reg_mux_out;
endmodule
