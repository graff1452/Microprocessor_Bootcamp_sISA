module pc_changer(
    input   wire [3:0]  PC,
    input   wire        add,
    input   wire        li,
    input   wire [3:0]  addr,
    input   wire        equal,
    input   wire        empty_inst,    
    output  wire [3:0]  changer_out
);
    wire [3:0] adder_4bits_1_out;
    wire [3:0] mux_2to1_4bits_1_out;
    wire [3:0] mux_2to1_4bits_2_out;

    adder_4bits adder_4bits_1 
    (
        .A(PC),
        .B(4'b0001),
        .Sum(adder_4bits_1_out)
    );

    mux_2to1_4bits mux_2to1_4bits_1 
    (
        .in0(adder_4bits_1_out),
        .in1(mux_2to1_4bits_2_out),
        .sel(~(add | li)),
        .mux_out(mux_2to1_4bits_1_out)
    );

    mux_2to1_4bits mux_2to1_4bits_2 
    (
        .in0(adder_4bits_1_out),
        .in1(addr),
        .sel(~equal),
        .mux_out(mux_2to1_4bits_2_out)
    );

    mux_2to1_4bits mux_2to1_4bits_3 
    (
        .in0(mux_2to1_4bits_1_out),
        .in1(adder_4bits_1_out),
        .sel(empty_inst),
        .mux_out(changer_out)
    );
endmodule
