module comparator_8bits
(
    input wire [7:0] A,
    input wire [7:0] B,
    output wire equal
);
    assign equal = (A == B);
endmodule
