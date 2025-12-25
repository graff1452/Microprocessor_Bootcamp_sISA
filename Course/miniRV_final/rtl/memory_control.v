module memory_control
(
    // CPU-side inputs
    input  wire [31:0] y,         // ALU result (byte address)
    input  wire [31:0] rs2_val,    // rs2 value
    input  wire        lw,
    input  wire        lbu,
    input  wire        sw,
    input  wire        sb,
    input  wire        ebreak,     // asserted on ebreak; blocks writes

    // From unified_memory
    input  wire [31:0] d_rdata_word,  // word read from memory at aligned address

    // To unified_memory
    output wire [31:0] d_addr,        // address presented to memory (aligned)
    output wire [31:0] d_wdata,       // store data formatted for byte/word
    output wire [3:0]  d_wstrb,       // byte enables
    output wire        d_we,          // write enable

    // To CPU writeback
    output wire [31:0] load_data      // formatted load result (lw/lbu)
);

    // Align address down to word boundary for memory word access
    wire [31:0] addr_aligned = {y[31:2], 2'b00};
    assign d_addr = addr_aligned;

    // Write enable only for stores, and never during ebreak/halt
    assign d_we = (sw | sb) & ~ebreak;

    // Byte strobes: sw writes all lanes; sb writes one lane selected by y[1:0]
    assign d_wstrb =
        sw ? 4'b1111 :
        sb ? (4'b0001 << y[1:0]) :
             4'b0000;

    // Write data:
    // - sw: store the full 32-bit word
    // - sb: replicate the low byte across all lanes; strobe selects target lane
    assign d_wdata =
        sw ? rs2_val :
        sb ? {4{rs2_val[7:0]}} :
             32'b0;

    // Load formatting:
    // - lw: pass through word
    // - lbu: select addressed byte from the aligned word and zero-extend
    wire [7:0] sel_byte =
        (y[1:0] == 2'b00) ? d_rdata_word[7:0]   :
        (y[1:0] == 2'b01) ? d_rdata_word[15:8]  :
        (y[1:0] == 2'b10) ? d_rdata_word[23:16] :
                            d_rdata_word[31:24];

    assign load_data =
        lw  ? d_rdata_word :
        lbu ? {24'b0, sel_byte} :
              32'b0;

endmodule
