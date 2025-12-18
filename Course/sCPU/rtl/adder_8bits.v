module adder_8bits 
(
    input   wire [7:0] A,
    input   wire [7:0] B,
    output  wire [7:0] Sum
);
    assign Sum = A + B;
endmodule
