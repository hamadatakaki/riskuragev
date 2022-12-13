`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/12 15:24:39
// Design Name: 
// Module Name: execution
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

`include "cpu.vh"

`define RHS_CONSTANT 32'h0000_0001

module execution(
    input wire [31:0] rs1, rs2, imm, pc,
    input wire [1:0] rhs_ty, lhs_ty,
    input wire [5:0] instcode,
    output wire [31:0] dst
);
    wire [31:0] rhs, lhs;
    
    mux_2bit muxL (
        .ope(lhs_ty),
        .in1(rs1),
        .in2(pc),
        .in3(0),
        .in4(`UNREACHABLE_VALUE_32),
        .out(lhs)
    );
    
    mux_2bit muxR (
        .ope(rhs_ty),
        .in1(rs2),
        .in2(imm),
        .in3(4),
        .in4(`UNREACHABLE_VALUE_32),
        .out(rhs)
    );

    function [3:0] ALUCODE (
        input [5:0] INSTCODE
    );
        begin
            ALUCODE = (INSTCODE < `INST_LUI) ? INSTCODE[3:0] :
                      (INSTCODE < `INST_BEQ) ? `ALU_ADD :
                      `ALU_NOP;
        end
    endfunction

    alu alu0 (
        .alu_op(ALUCODE(instcode)),
        .lhs(lhs),
        .rhs(rhs),
        .dst(dst)
    );
endmodule
