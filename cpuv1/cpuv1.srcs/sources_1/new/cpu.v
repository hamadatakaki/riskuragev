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

module cpu(
    input wire clk
);
    reg [2:0] ctr = -1;

    wire [31:0] inst;
    wire [1:0] update_pc_type;
    wire [31:0] imm;
    wire [31:0] rs1_data;

    fetcher_v3 fetcher0(
        .clk(clk),
        .instruction(inst),
        .en_update_pc(ctr == `CPU_STEP_WRITEBACK),
        .update_pc_type(update_pc_type),
        .rs1(rs1_data),
        .imm(imm)
    );

    wire [5:0] inst_code;
    wire [4:0] rs1_addr, rs2_addr, rd_addr;
    
    wire [1:0] lhs_type, rhs_type;

    decoder decoder0(
        .inst(inst),
        .inst_code(inst_code),
        .rs1(rs1_addr),
        .rs2(rs2_addr),
        .rd(rd_addr),
        .imm(imm),
        .lhs_input_type(lhs_type),
        .rhs_input_type(rhs_type),
        .update_pc_type(update_pc_type)
    );

    wire [31:0] rs2_data;
    wire [31:0] exec_dst;

    register_file_v2 register_file0(
        .clk(clk),
        .write(ctr == `CPU_STEP_REGUPD),
        .addr_rs1(rs1_addr),
        .addr_rs2(rs2_addr),
        .data_rs1(rs1_data),
        .data_rs2(rs2_data),
        .addr_write(rd_addr),
        .data_write(exec_dst)
    );

    execution exec0 (
        .rs1(rs1_data),
        .rs2(rs2_data),
        .imm(imm),
        .pc(fetcher0.pc),
        .rhs_ty(rhs_type),
        .lhs_ty(lhs_type),
        .instcode(inst_code),
        .dst(exec_dst)
    );
    
    always @(negedge clk) begin
        ctr <= (ctr + 1) % `CPU_STEPSIZE;
    end
endmodule
