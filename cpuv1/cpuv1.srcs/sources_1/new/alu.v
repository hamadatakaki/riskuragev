`include "alu.vh"

module alu(
    input wire [3:0] alu_op,
    input wire [31:0] lhs,
    input wire [31:0] rhs,
    output wire [31:0] dst
);
    assign dst = (alu_op == `ALU_ADD)  ? lhs + rhs :
                 (alu_op == `ALU_SUB)  ? lhs - rhs :
                 (alu_op == `ALU_SLL)  ? lhs << rhs[4:0] :
                 (alu_op == `ALU_SLT)  ? $signed(lhs) < $signed(rhs) :
                 (alu_op == `ALU_SLTU) ? lhs < rhs :
                 (alu_op == `ALU_XOR)  ? lhs ^ rhs :
                 (alu_op == `ALU_SRL)  ? lhs >> rhs[4:0] :
                 (alu_op == `ALU_SRA)  ? (
                     (lhs[31] == 1'b0) ? lhs >> rhs[4:0] : (
                         (lhs >> rhs[4:0]) | ~(32'hFFFFFFFF >> rhs[4:0])
                     ) 
                 ) :
                 (alu_op == `ALU_OR)   ? lhs | rhs :
                 (alu_op == `ALU_AND)  ? lhs & rhs :
                 `NOT_REACHABLE_ALU_RESULT;
endmodule
