module unified_memory #(
    parameter integer MEM_BYTES = 128 * 1024 * 1024,     // 128 MiB for simulation
    parameter [31:0]  BASE_ADDR = 32'h8000_0000
)(
    input  wire [31:0] i_addr,
    output wire [31:0] i_rdata,

    // Data port (combinational read, synchronous write)
    input  wire [31:0] d_addr,
    input  wire [31:0] d_wdata,
    input  wire [3:0]  d_wstrb,   // byte enables: bit0->lowest byte
    input  wire        d_we,
    output wire [31:0] d_rdata,

    input  wire        clk
);

    // Byte-addressable memory
    reg [7:0] mem [0:MEM_BYTES-1];

    // Address offsets into mem[]
    wire [31:0] i_off = i_addr - BASE_ADDR;
    wire [31:0] d_off = d_addr - BASE_ADDR;

    // In-range checks (avoid indexing mem[] with invalid offsets)
    wire i_in_range = (i_addr >= BASE_ADDR) && (i_off + 32'd3 < MEM_BYTES);
    wire d_in_range = (d_addr >= BASE_ADDR) && (d_off + 32'd3 < MEM_BYTES);

    // -----------------------------
    // Combinational READS
    // -----------------------------
    // Instruction fetch: 32-bit little-endian
    assign i_rdata = i_in_range
        ? { mem[i_off + 32'd3], mem[i_off + 32'd2], mem[i_off + 32'd1], mem[i_off + 32'd0] }
        : 32'h0000_0000;

    // Data read: always returns the 32-bit word containing d_addr..d_addr+3 (little-endian)
    assign d_rdata = d_in_range
        ? { mem[d_off + 32'd3], mem[d_off + 32'd2], mem[d_off + 32'd1], mem[d_off + 32'd0] }
        : 32'h0000_0000;

    // -----------------------------
    // Synchronous WRITES (byte strobes)
    // -----------------------------
    always @(posedge clk) begin
        if (d_we && d_in_range) begin
            if (d_wstrb[0]) mem[d_off + 32'd0] <= d_wdata[7:0];
            if (d_wstrb[1]) mem[d_off + 32'd1] <= d_wdata[15:8];
            if (d_wstrb[2]) mem[d_off + 32'd2] <= d_wdata[23:16];
            if (d_wstrb[3]) mem[d_off + 32'd3] <= d_wdata[31:24];
        end
    end

endmodule
