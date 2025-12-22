module immediate_generator (
    input   wire [31:0] instruction,
    input   wire        illegal,
    input   wire        r_type,
    input   wire        i_type,
    input   wire        s_type,
    input   wire        u_type,
    output  wire [31:0] imm
);
    reg     [31:0] reg_imm;
    wire    [11:0] imm_i = instruction[31:20];
    wire    [11:0] imm_s = {instruction[31:25], instruction[11:7]};
    wire    [19:0] imm_u = instruction[31:12];

    always @(*) 
    begin
        if (i_type) 
        begin
            reg_imm = {{20{imm_i[11]}}, imm_i};
        end
        else if (s_type) 
        begin
            reg_imm = {{20{imm_s[11]}}, imm_s};
        end
        else if (u_type) 
        begin
            reg_imm = {imm_u, 12'b0};
        end
        else 
        begin
            reg_imm = 32'b0;
        end
    end
    assign imm = reg_imm;
endmodule
