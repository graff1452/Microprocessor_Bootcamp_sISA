module data_memory #(
    parameter integer ADDR_BITS = 26  // 2^26 bytes
)(
    input  wire [31:0] addr,
    input  wire [31:0] write_data,
    input  wire        sw,
    input  wire        sb,
    input  wire        lw,
    input  wire        lbu,
    input  wire        clk,
    output wire [31:0] read_data
);

    localparam integer DEPTH = (1 << ADDR_BITS);

    reg [7:0] ram0 [0:DEPTH-1];
    reg [7:0] ram1 [0:DEPTH-1];
    reg [7:0] ram2 [0:DEPTH-1];
    reg [7:0] ram3 [0:DEPTH-1];

    wire [ADDR_BITS-1:0] a = addr[ADDR_BITS-1:0];
    // for store
    always @(posedge clk) begin
        if (sw) 
        begin
            ram0[a + 0] <= write_data[7:0];
            ram1[a + 1] <= write_data[15:8];
            ram2[a + 2] <= write_data[23:16];
            ram3[a + 3] <= write_data[31:24];
        end
        else if (sb) 
        begin
            case (addr[1:0])
                2'b00: ram0[a] <= write_data[7:0];
                2'b01: ram1[a] <= write_data[7:0];
                2'b10: ram2[a] <= write_data[7:0];
                2'b11: ram3[a] <= write_data[7:0];
            endcase
        end
    end

    // for load
    wire [7:0] byte0 = ram0[a + 0];
    wire [7:0] byte1 = ram1[a + 1];
    wire [7:0] byte2 = ram2[a + 2];
    wire [7:0] byte3 = ram3[a + 3];

    wire [31:0] lw_word = {byte3, byte2, byte1, byte0};

    wire [7:0] sel_byte =
        (addr[1:0] == 2'b00) ? ram0[a] :
        (addr[1:0] == 2'b01) ? ram1[a] :
        (addr[1:0] == 2'b10) ? ram2[a] :
                               ram3[a];

    assign  read_data = lw  ? lw_word           : 
                        lbu ? {24'b0, sel_byte} : 
                        32'b0;
endmodule
