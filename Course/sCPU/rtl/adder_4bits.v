module adder_4bits 
(
    input   wire [3:0] A,
    input   wire [3:0] B,
    output  wire [3:0] Sum
);
    assign Sum = A + B;
endmodule
