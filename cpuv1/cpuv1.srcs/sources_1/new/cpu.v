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
    
    wire [31:0] instruction, data_rs1, data_rs2, data_rd, imm;
    wire [5:0] instruction_code;
    wire [4:0] addr_rs1, addr_rs2, addr_rd;
    wire [1:0] lhs_type, rhs_type, _update_pc_type, update_pc_type;
    wire update_rd;
    wire en_update_pc, en_write, en_store;
    
    assign en_update_pc = (ctr == `CPU_STEP_WRITEBACK);
    assign en_write = (ctr == `CPU_STEP_REGUPD) & update_rd;

    fetcher_v3 fetcher0(
        .clk(clk),
        .instruction(instruction),
        .en_update_pc(en_update_pc),
        .update_pc_type(update_pc_type),
        .data_rs1(data_rs1),
        .imm(imm)
    );

    decoder decoder0(
        .clk(clk),
        .instruction(instruction),
        .instruction_code(instruction_code),
        .addr_rs1(addr_rs1),
        .addr_rs2(addr_rs2),
        .addr_rd(addr_rd),
        .imm(imm),
        .lhs_input_type(lhs_type),
        .rhs_input_type(rhs_type),
        .update_pc_type(_update_pc_type),
        .update_rd(update_rd)
    );

    register_file_v2 register_file0(
        .clk(clk),
        .addr_rs1(addr_rs1),
        .addr_rs2(addr_rs2),
        .data_rs1(data_rs1),
        .data_rs2(data_rs2),
        .en_write(en_write),
        .addr_write(addr_rd),
        .data_write(data_rd)
    );

    execution exec0 (
        .clk(clk),
        .data_rs1(data_rs1),
        .data_rs2(data_rs2),
        .imm(imm),
        .pc(fetcher0.pc),
        .lhs_type(lhs_type),
        .rhs_type(rhs_type),
        .instruction_code(instruction_code),
        .default_update_pc_type(_update_pc_type),
        .update_pc_type(update_pc_type),
        .dst(data_rd)
    );
    
    always @(negedge clk) begin
        ctr <= (ctr + 1) % `CPU_STEPSIZE;
    end
endmodule
