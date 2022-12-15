`include "alu.vh"

module alu(
    input wire [3:0] alu_op,
    input wire [31:0] lhs,
    input wire [31:0] rhs,
    output wire [31:0] dst,
    output wire [31:0] output_dummy
);

function [32:0] fooo;
input [3:0] ___alu_op;
input [31:0] ___lhs;
input [31:0] ___rhs;

if(___alu_op == `ALU_ADD)  fooo =  ___lhs + ___rhs;
                  else if(___alu_op == `ALU_SUB)  fooo =  ___lhs - ___rhs;
                  else if(___alu_op == `ALU_SLL)  fooo =  ___lhs << ___rhs[4:0];
                  else if(___alu_op == `ALU_SLT)  fooo =  $signed(___lhs) < $signed(___rhs);
                  else if(___alu_op == `ALU_SLTU) fooo =  ___lhs < ___rhs;
                  else if(___alu_op == `ALU_XOR)  fooo =  ___lhs ^ ___rhs;
                  else if(___alu_op == `ALU_SRL)  fooo =  ___lhs >> ___rhs[4:0];
                  else if(___alu_op == `ALU_SRA)  fooo =  ___lhs >>> ___rhs[4:0];
                  else if(___alu_op == `ALU_OR)   fooo =  ___lhs | ___rhs;
                  else if(___alu_op == `ALU_AND)  fooo =  ___lhs & ___rhs;
                  else  fooo = `NOT_REACHABLE_ALU_RESULT;
endfunction

    wire [32:0] _dst;

    assign _dst = fooo(alu_op, lhs, rhs);

    wire [32:0] dummy = _dst;
    assign dst = dummy[31:0];
    assign output_dummy = dummy[31:0];
endmodule
