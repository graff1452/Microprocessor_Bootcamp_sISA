module top(
	input clk,
	input rst,
  output ok
);

	reg [3:0] pc;
	reg [7:0] regs [3:0];
	reg [7:0] inst_mem [0:15];
	
  initial begin
    inst_mem[0] = 8'b10001010;  // 0: li r0, 10
    inst_mem[1] = 8'b10010000;  // 1: li r1, 0
    inst_mem[2] = 8'b10100000;  // 2: li r2, 0
    inst_mem[3] = 8'b10110001;  // 3: li r3, 1
    inst_mem[4] = 8'b00010111;  // 4: add r1, r1, r3
    inst_mem[5] = 8'b00101001;  // 5: add r2, r2, r1
    inst_mem[6] = 8'b11010001;  // 6: bner0 r1, 4
    inst_mem[7] = 8'b11011111;  // 7: bner0 r3, 7
  end

  // fetch
	wire [7:0] inst = inst_mem[pc];
	
  // decode
	wire [1:0] opcode = inst[7:6];
  wire [1:0] rd = inst[5:4];
	wire [1:0] rs1 = inst[3:2];
	wire [1:0] rs2 = inst[1:0];
	wire [3:0] imm = inst[3:0];
	wire [3:0] addr = inst[5:2];
	wire [7:0] rs1_val = regs[rs1];
	wire [7:0] rs2_val = regs[rs2];

  // execute
	wire [7:0] li_val = (opcode == 2'b10) ? {4'b0, imm[3:0]} : rs2_val;
	wire [7:0] rd_val = (opcode == 2'b00) ? (rs1_val + rs2_val) : li_val;
	wire wen = (opcode == 2'b11) ? 1'b0 : 1'b1;
    
	always @(posedge clk) begin // write
		if (wen) begin
			regs[rd] <= rd_val;
		end
	end

	// update pc
  wire branch_taken = (opcode == 2'b11) && (rs2_val != regs[0]);
	wire [3:0] next_pc = branch_taken ? addr : pc + 1;	
	always @(posedge clk) begin
    if (rst) pc <= 4'b0;
    else pc <= next_pc;
  end

  assign ok = (pc == 7) && (regs[2] == 55);
endmodule
