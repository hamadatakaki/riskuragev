`include "define.vh"

`define UNDEFINED_IMM { 32{1'dx} }

module decoder(
    input wire [31:0] inst,
    output wire [5:0] alucode,
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
    
    assign alucode = (_opc == `OP_LUI) ? `ALU_LUI :
                     (_opc == `OP_AUIPC) ? `ALU_AUIPC :
                     (_opc == `OP_JAL) ? `ALU_JAL :
                     (_opc == `OP_JALR) ? `ALU_JALR :
                     (_opc == `OP_BRANCH) ? (
                        (_sub == `SUB_BEQ) ? `ALU_BEQ :
                        (_sub == `SUB_BNE) ? `ALU_BNE :
                        (_sub == `SUB_BLT) ? `ALU_BLT :
                        (_sub == `SUB_BGE) ? `ALU_BGE :
                        (_sub == `SUB_BLTU) ? `ALU_BLTU :
                        (_sub == `SUB_BGEU) ? `ALU_BGEU :
                        `ALU_NOP
                     ) :
                     (_opc == `OP_STORE) ? (
                        (_sub == `SUB_SB) ? `ALU_SB :
                        (_sub == `SUB_SH) ? `ALU_SH :
                        (_sub == `SUB_SW) ? `ALU_SW :
                        `ALU_NOP
                     ) :
                     (_opc == `OP_LOAD) ? (
                        (_sub == `SUB_LB) ? `ALU_LB :
                        (_sub == `SUB_LH) ? `ALU_LH :
                        (_sub == `SUB_LW) ? `ALU_LW :
                        (_sub == `SUB_LBU) ? `ALU_LBU :
                        (_sub == `SUB_LHU) ? `ALU_LHU :
                        `ALU_NOP
                     ) :
                     (_opc == `OP_OPIMM || _opc == `OP_OP) ? (
                        (_sub == `SUB_ADD) ? (
                            (inst[30] == 0) ? `ALU_ADD : `ALU_SUB
                        ) :
                        (_sub == `SUB_SLL) ? `ALU_SLL :
                        (_sub == `SUB_SLT) ? `ALU_SLT :
                        (_sub == `SUB_SLTU) ? `ALU_SLTU :
                        (_sub == `SUB_XOR) ? `ALU_XOR :
                        (_sub == `SUB_SRL) ? (
                            (inst[30] == 0) ? `ALU_SRL : `ALU_SRA
                        ) :
                        (_sub == `SUB_OR) ? `ALU_OR :
                        (_sub == `SUB_AND) ? `ALU_AND :
                        `ALU_NOP
                     ) :
                     `ALU_NOP;

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
