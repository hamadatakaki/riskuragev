// 命令コード
`define INST_ADD    6'd0
`define INST_SUB    6'd1
`define INST_SLL    6'd2
`define INST_SLT    6'd3
`define INST_SLTU   6'd4
`define INST_XOR    6'd5
`define INST_SRL    6'd6
`define INST_SRA    6'd7
`define INST_OR     6'd8
`define INST_AND    6'd9
`define INST_LUI    6'd10
`define INST_AUIPC  6'd11
`define INST_JAL    6'd12
`define INST_JALR   6'd13
`define INST_BEQ    6'd14
`define INST_BNE    6'd15
`define INST_BLT    6'd16
`define INST_BGE    6'd17
`define INST_BLTU   6'd18
`define INST_BGEU   6'd19
`define INST_LB     6'd20
`define INST_LH     6'd21
`define INST_LW     6'd22
`define INST_LBU    6'd23
`define INST_LHU    6'd24
`define INST_SB     6'd25
`define INST_SH     6'd26
`define INST_SW     6'd27
`define INST_NOP    6'h3F

// ALU left-hand-side input type
`define LHS_INPUT_RS1   2'd0
`define LHS_INPUT_PC    2'd1
`define LHS_INPUT_CONST 2'd2
`define LHS_INPUT_NOP   2'd3

// ALU right-hand-side input type
`define RHS_INPUT_RS2   2'd0
`define RHS_INPUT_IMM   2'd1
`define RHS_INPUT_CONST 2'd2
`define RHS_INPUT_NOP   2'd3
