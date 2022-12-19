// 命令コード
`define INST_ADD    6'h00
`define INST_SUB    6'h01
`define INST_SLL    6'h02
`define INST_SLT    6'h03
`define INST_SLTU   6'h04
`define INST_XOR    6'h05
`define INST_SRL    6'h06
`define INST_SRA    6'h07
`define INST_OR     6'h08
`define INST_AND    6'h09
`define INST_LUI    6'h0a
`define INST_AUIPC  6'h0b
`define INST_JAL    6'h0c
`define INST_JALR   6'h0d
`define INST_BEQ    6'h0e
`define INST_BNE    6'h0f
`define INST_BLT    6'h10
`define INST_BGE    6'h11
`define INST_BLTU   6'h12
`define INST_BGEU   6'h13
`define INST_LB     6'h14
`define INST_LH     6'h15
`define INST_LW     6'h16
`define INST_LBU    6'h17
`define INST_LHU    6'h18
`define INST_SB     6'h19
`define INST_SH     6'h1a
`define INST_SW     6'h1b
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
