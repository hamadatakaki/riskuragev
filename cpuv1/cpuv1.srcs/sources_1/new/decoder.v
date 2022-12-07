`include "decoder.vh"
`include "instruction.vh"

`define UNDEFINED_IMM { 32{1'dx} }

module decoder(
    input wire [31:0] inst,
    output wire [5:0] inst_code,
    output wire [4:0] rs1,
    output wire [4:0] rs2,
    output wire [4:0] rd,
    output wire [31:0] imm
);
    wire [6:0] _opc;
    wire [2:0] _sub;
    
    assign _opc = inst[6:0];
    assign _sub = inst[14:12];
    assign y = 12'hxxx;
    
    assign inst_code = (_opc == `OP_LUI) ? `INST_LUI :
                     (_opc == `OP_AUIPC) ? `INST_AUIPC :
                     (_opc == `OP_JAL) ? `INST_JAL :
                     (_opc == `OP_JALR) ? `INST_JALR :
                     (_opc == `OP_BRANCH) ? (
                        (_sub == `SUB_BEQ) ? `INST_BEQ :
                        (_sub == `SUB_BNE) ? `INST_BNE :
                        (_sub == `SUB_BLT) ? `INST_BLT :
                        (_sub == `SUB_BGE) ? `INST_BGE :
                        (_sub == `SUB_BLTU) ? `INST_BLTU :
                        (_sub == `SUB_BGEU) ? `INST_BGEU :
                        `INST_NOP
                     ) :
                     (_opc == `OP_STORE) ? (
                        (_sub == `SUB_SB) ? `INST_SB :
                        (_sub == `SUB_SH) ? `INST_SH :
                        (_sub == `SUB_SW) ? `INST_SW :
                        `INST_NOP
                     ) :
                     (_opc == `OP_LOAD) ? (
                        (_sub == `SUB_LB) ? `INST_LB :
                        (_sub == `SUB_LH) ? `INST_LH :
                        (_sub == `SUB_LW) ? `INST_LW :
                        (_sub == `SUB_LBU) ? `INST_LBU :
                        (_sub == `SUB_LHU) ? `INST_LHU :
                        `INST_NOP
                     ) :
                     (_opc == `OP_OPIMM || _opc == `OP_OP) ? (
                        (_sub == `SUB_ADD) ? (
                            (inst[30] == 0) ? `INST_ADD : `INST_SUB
                        ) :
                        (_sub == `SUB_SLL) ? `INST_SLL :
                        (_sub == `SUB_SLT) ? `INST_SLT :
                        (_sub == `SUB_SLTU) ? `INST_SLTU :
                        (_sub == `SUB_XOR) ? `INST_XOR :
                        (_sub == `SUB_SRL) ? (
                            (inst[30] == 0) ? `INST_SRL : `INST_SRA
                        ) :
                        (_sub == `SUB_OR) ? `INST_OR :
                        (_sub == `SUB_AND) ? `INST_AND :
                        `INST_NOP
                     ) :
                     `INST_NOP;

    assign rs1 = inst[19:15];
    assign rs2 = inst[24:20];
    assign rd = inst[11:7];
    
    assign imm = (_opc == `OP_LUI || _opc == `OP_AUIPC) ? inst :
                 (_opc == `OP_JAL) ? { {32{1'dx}}, inst[31], inst[19:12], inst[20], inst[30:21], { 1'bx } } :
                 (_opc == `OP_OPIMM || _opc == `OP_JALR || _opc == `OP_LOAD) ? { {32{1'dx}}, inst[31:20] } :
                 (_opc == `OP_STORE) ? { {32{1'dx}}, inst[31:25], inst[11:7] } :
                 (_opc == `OP_BRANCH) ? { {32{1'dx}}, inst[31], inst[7], inst[30:25], inst[11:8], { 1'bx } } :
                 `UNDEFINED_IMM;
endmodule
