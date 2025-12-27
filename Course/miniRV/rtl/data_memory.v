module data_memory#(
    // number of WORD index bits (not bytes)
    // DEPTH_WORDS = 2^WORD_BITS words => bytes = 2^(WORD_BITS+2)
    parameter integer WORD_BITS = 25
)(
    input  wire [31:0] addr,        // byte address
    input  wire [31:0] write_data,
    input  wire        sw,
    input  wire        sb,
    input  wire        lw,
    input  wire        lbu,
    input  wire        clk,
    output wire [31:0] read_data
);

    localparam integer DEPTH_WORDS = (1 << WORD_BITS);

    reg [31:0] mem [0:DEPTH_WORDS-1];

    initial begin
        $readmemh("/home/graff145/Desktop/Microprocessor_Bootcamp_sISA/Course/miniRV/instructions/instruction.txt", mem);
    end

    // Word index and byte offset within the word
    wire [WORD_BITS-1:0] widx   = addr[WORD_BITS+1:2]; // == (addr >> 2)
    wire [1:0]           boff   = addr[1:0];

    // Current word (combinational read)
    wire [31:0] cur_word = mem[widx];

    // -------- STORE (sync) --------
    always @(posedge clk) begin
        if (sw) begin
            mem[widx] <= write_data;
        end else if (sb) begin
            case (boff)
                2'b00: mem[widx] <= {cur_word[31:8],  write_data[7:0]};
                2'b01: mem[widx] <= {cur_word[31:16], write_data[7:0], cur_word[7:0]};
                2'b10: mem[widx] <= {cur_word[31:24], write_data[7:0], cur_word[15:0]};
                2'b11: mem[widx] <= {write_data[7:0], cur_word[23:0]};
            endcase
        end
    end

    // -------- LOAD (combinational) --------
    wire [7:0] sel_byte =
        (boff == 2'b00) ? cur_word[7:0]   :
        (boff == 2'b01) ? cur_word[15:8]  :
        (boff == 2'b10) ? cur_word[23:16] :
                          cur_word[31:24];

    assign read_data =
        lw  ? cur_word            :
        lbu ? {24'b0, sel_byte}   :
              32'b0;

endmodule
