`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/07 16:55:36
// Design Name: 
// Module Name: cpu
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
`include "alu.vh"
`include "instruction.vh"

function [3:0] CONVERT_ALUOP (
    input [5:0] INSTCODE
); 
begin
    CONVERT_ALUOP = (INSTCODE == `INST_ADD) ? `ALU_ADD :
                    (INSTCODE == `INST_SUB) ? `ALU_SUB :
                    (INSTCODE == `INST_SLL) ? `ALU_SLL :
                    (INSTCODE == `INST_SLT) ? `ALU_SLT :
                    (INSTCODE == `INST_SLTU) ? `ALU_SLTU :
                    (INSTCODE == `INST_XOR) ? `ALU_XOR :
                    (INSTCODE == `INST_SRL) ? `ALU_SRL :
                    (INSTCODE == `INST_SRA) ? `ALU_SRA :
                    (INSTCODE == `INST_OR) ? `ALU_OR :
                    (INSTCODE == `INST_AND) ? `ALU_AND :
                    `ALU_NOP;
end
endfunction

module cpu(
    input wire clk
);
    reg ctr = 0;

    reg [31:0] inst;

    fetcher_v2 fetcher0(
        .clk(clk),
        .enable(ctr == 0),
        .instruction(inst)
    );

    reg [5:0] inst_code;
    reg [4:0] rs1_addr, rs2_addr, rd_addr;
    reg [31:0] imm;

    decoder decoder0(
        .inst(inst),
        .inst_code(inst_code),
        .rs1(rs1_addr),
        .rs2(rs2_addr),
        .rd(rd_addr),
        .imm(imm)
    );

    reg [31:0] rs1_data, rs2_data;

    register_file register_file0(
        .clk(clk),
        .rs1_addr(rs1_addr),
        .rs2_addr(rs2_addr),
        .read_rs1_data(rs1_data),
        .read_rs2_data(rs2_data)
    );

    reg [31:0] rd_data;
    reg cflag;

    alu alu0(
        .alu_op(CONVERT_ALUOP(inst_code)),
        .lhs(rs1_data),
        .rhs(rs2_data),
        .dst(rd_data),
        .cflag(cflag)
    );
    
    always @(posedge clk) begin
        ctr <= (ctr + 1) % `CPU_STEPSIZE;
    end
endmodule
