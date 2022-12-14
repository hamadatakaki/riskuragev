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
    input wire clk,  // for DEBUG
    input wire [31:0] data_rs1, data_rs2, imm, pc,
    input wire [1:0] lhs_type, rhs_type,
    input wire [5:0] instruction_code,
    input wire [1:0] default_update_pc_type,
    output wire [1:0] update_pc_type,
    output wire [31:0] dst
);
    wire [31:0] rhs, lhs;
    
    mux_2bit muxL (
        .ope(lhs_type),
        .in1(data_rs1),
        .in2(pc),
        .in3(32'h0000_0000),
        .in4(`UNREACHABLE_VALUE_32),
        .out(lhs)
    );
    
    mux_2bit muxR (
        .ope(rhs_type),
        .in1(data_rs2),
        .in2(imm),
        .in3(32'h0000_0004),
        .in4(`UNREACHABLE_VALUE_32),
        .out(rhs)
    );
    
    branch branch0 (
        .data_rs1(data_rs1),
        .data_rs2(data_rs2),
        .instruction_code(instruction_code),
        .default_update_pc_type(default_update_pc_type),
        .update_pc_type(update_pc_type)
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
        .alu_op(ALUCODE(instruction_code)),
        .lhs(lhs),
        .rhs(rhs),
        .dst(dst)
    );
endmodule
