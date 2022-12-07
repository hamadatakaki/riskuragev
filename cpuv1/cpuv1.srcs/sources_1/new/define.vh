`define ENABLE  1'b1
`define DISABLE 1'b0

// 命令形式
`define TYPE_NONE 3'd0
`define TYPE_U    3'd1
`define TYPE_J    3'd2
`define TYPE_I    3'd3
`define TYPE_B    3'd4
`define TYPE_S    3'd5
`define TYPE_R    3'd6

// DSTレジスタの有無
`define REG_NONE 1'd0
`define REG_RD   1'd1

// ALU入力タイプ
`define OP_TYPE_NONE 2'd0
`define OP_TYPE_REG  2'd1
`define OP_TYPE_IMM  2'd2
`define OP_TYPE_PC   2'd3

// パイプラインステージ
`define IF_STAGE 3'd0
`define RR_STAGE 3'd1
`define EX_STAGE 3'd2
`define MA_STAGE 3'd3
`define RW_STAGE 3'd4

// address for hardware counter
`define HARDWARE_COUNTER_ADDR 32'hffffff00

// address for UART
`define UART_ADDR 32'hf6fff070
