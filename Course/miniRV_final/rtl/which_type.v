module which_type (
    input  wire [6:0]   opcode,
    output wire         r_type,
    output wire         i_type,
    output wire         s_type,
    output wire         u_type
);
    assign r_type = (opcode == 7'b0110011); // add
    assign i_type =
        (opcode == 7'b0010011) || // addi
        (opcode == 7'b0000011) || // lw, lbu
        (opcode == 7'b1100111);   // jalr

    assign s_type = (opcode == 7'b0100011); // sw, sb
    assign u_type = (opcode == 7'b0110111); // lui
endmodule
