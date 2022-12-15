// OPコード
`define OP_LUI    7'b0110111
`define OP_AUIPC  7'b0010111
`define OP_JAL    7'b1101111
`define OP_JALR   7'b1100111
`define OP_BRANCH 7'b1100011
`define OP_STORE  7'b0100011
`define OP_LOAD   7'b0000011
`define OP_OPIMM  7'b0010011
`define OP_OP     7'b0110011

// SUB OPコード
`define SUB_ADD    3'b000
`define SUB_SLL    3'b001
`define SUB_SLT    3'b010
`define SUB_SLTU   3'b011
`define SUB_XOR    3'b100
`define SUB_SRL    3'b101
`define SUB_OR     3'b110
`define SUB_AND    3'b111

`define SUB_BEQ    3'b000
`define SUB_BNE    3'b001
`define SUB_BLT    3'b100
`define SUB_BGE    3'b101
`define SUB_BLTU   3'b110
`define SUB_BGEU   3'b111

`define SUB_SB     3'b000
`define SUB_SH     3'b001
`define SUB_SW     3'b010

`define SUB_LB     3'b000
`define SUB_LH     3'b001
`define SUB_LW     3'b010
`define SUB_LBU    3'b100
`define SUB_LHU    3'b101
