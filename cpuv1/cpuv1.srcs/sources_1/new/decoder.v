`include "decoder.vh"
`include "instruction.vh"
`include "fetcher.vh"

`define UNREACHABLE_IMM 32'd0

module decoder(
    input wire clk,  // for DEBUG
    input wire [31:0] instruction,
    output wire [4:0] addr_rs1, addr_rs2, addr_rd,
    output wire [31:0] imm,
    // ALU operation
    output wire [5:0] instruction_code,
    output wire [1:0] lhs_input_type, rhs_input_type,
    // option lines
    output wire [1:0] fetcher_option,
    output wire [2:0] memory_option,
    // operation lines
    output wire en_load_rs1, en_load_rs2, en_store_rd, en_load_main, en_store_main
);
    wire [6:0] _opc;
    wire [2:0] _sub;
    
    assign _opc = instruction[6:0];
    assign _sub = instruction[14:12];

    // address rs1, rs2, rd
    assign addr_rs1 = instruction[19:15];
    assign addr_rs2 = instruction[24:20];
    assign addr_rd = instruction[11:7];

    // imm value
    assign imm = (_opc == `OP_LUI || _opc == `OP_AUIPC) ? { instruction[31:12], {12{1'd0}} } :
                 (_opc == `OP_JAL) ? { {11{1'd0}}, instruction[31], instruction[19:12], instruction[20], instruction[30:21], {1'b0} } :
                 (_opc == `OP_OPIMM) ?  (
                     (_sub == `SUB_SLL || _sub == `SUB_SRL) ? { {27{1'd0}}, instruction[24:20] } : { {20{instruction[31]}}, instruction[31:20] }
                 ) :
                 (_opc == `OP_JALR || _opc == `OP_LOAD) ? { {20{1'd0}}, instruction[31:20] } :
                 (_opc == `OP_STORE) ? { {20{1'd0}}, instruction[31:25], instruction[11:7] } :
                 (_opc == `OP_BRANCH) ? { {32{1'd0}}, instruction[31], instruction[7], instruction[30:25], instruction[11:8], { 1'b0 } } :
                 `UNREACHABLE_IMM;

    // en lines    
    assign en_load_rs1 = (_opc != `OP_LUI) && (_opc != `OP_AUIPC) && (_opc != `OP_JAL);
    assign en_load_rs2 = (_opc == `OP_OP) || (_opc == `OP_BRANCH) || (_opc == `OP_STORE);
    assign en_store_rd = ((_opc != `OP_BRANCH) && (_opc != `OP_STORE)) && (
        (~(_opc == `OP_JAL || _opc == `OP_JALR)) || (addr_rd != 0)
    );
    assign en_load_main = (_opc == `OP_LOAD);
    assign en_store_main = (_opc == `OP_STORE);

    // fetcher, memory options
    assign fetcher_option = (_opc == `OP_JAL) ? `UPD_PC_IMM :
                            (_opc == `OP_JALR) ? `UPD_PC_REGIMM :
                            `UPD_PC_INC;
    assign memory_option = _sub;

    // ALU operation
    
    assign lhs_input_type = (_opc == `OP_OP) ? `LHS_INPUT_RS1 :
                            (_opc == `OP_AUIPC || _opc == `OP_JAL || _opc == `OP_JALR) ? `LHS_INPUT_PC :
                            (_opc == `OP_LUI) ? `LHS_INPUT_CONST :
                            (_opc == `OP_OPIMM) ? (
                                (addr_rs1 == 0) ? `LHS_INPUT_CONST : `LHS_INPUT_RS1
                            ) :
                            `LHS_INPUT_NOP;
                            
    assign rhs_input_type = (_opc == `OP_OP) ? `RHS_INPUT_RS2 :
                            (_opc == `OP_OPIMM || _opc == `OP_AUIPC || _opc == `OP_LUI) ? `RHS_INPUT_IMM :
                            (_opc == `OP_JAL || _opc == `OP_JALR) ? `RHS_INPUT_CONST :
                            `RHS_INPUT_NOP;

    assign instruction_code = (_opc == `OP_LUI) ? `INST_LUI :
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
                              (_opc == `OP_OPIMM) ? (
                                  (_sub == `SUB_ADD) ? `INST_ADD :
                                  (_sub == `SUB_SLL) ? `INST_SLL :
                                  (_sub == `SUB_SLT) ? `INST_SLT :
                                  (_sub == `SUB_SLTU) ? `INST_SLTU :
                                  (_sub == `SUB_XOR) ? `INST_XOR :
                                  (_sub == `SUB_SRL) ? (
                                      (instruction[30] == 0) ? `INST_SRL : `INST_SRA
                                  ) :
                                  (_sub == `SUB_OR) ? `INST_OR :
                                  (_sub == `SUB_AND) ? `INST_AND :
                                  `INST_NOP
                              ) :
                              (_opc == `OP_OP) ? (
                                 (_sub == `SUB_ADD) ? (
                                     (instruction[30] == 0) ? `INST_ADD : `INST_SUB
                                 ) :
                                 (_sub == `SUB_SLL) ? `INST_SLL :
                                 (_sub == `SUB_SLT) ? `INST_SLT :
                                 (_sub == `SUB_SLTU) ? `INST_SLTU :
                                 (_sub == `SUB_XOR) ? `INST_XOR :
                                 (_sub == `SUB_SRL) ? (
                                     (instruction[30] == 0) ? `INST_SRL : `INST_SRA
                                 ) :
                                 (_sub == `SUB_OR) ? `INST_OR :
                                 (_sub == `SUB_AND) ? `INST_AND :
                              `INST_NOP
                          ) :
                          `INST_NOP;
endmodule
