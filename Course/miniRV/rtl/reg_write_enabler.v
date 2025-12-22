module reg_write_enabler
(
    input   wire add,
    input   wire addi,
    input   wire lui,
    input   wire lw,
    input   wire lbu,
    input   wire jalr,
    input   wire illegal,
    output  wire reg_write
);
    assign reg_write = ((add || addi || lui || lw || lbu || jalr) && ~illegal);
endmodule
