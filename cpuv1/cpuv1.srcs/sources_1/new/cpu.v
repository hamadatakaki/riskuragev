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
    wire [1:0] lhs_type, rhs_type;
    
    wire _en_load_rs1, _en_load_rs2, _en_store_rd, _en_store_main, _en_load_main;
    wire en_fetch, en_update_pc, en_load_rs1, en_load_rs2, en_store_rd, en_store_main, en_load_main;

    wire [1:0] fetcher_option, _fetcher_option;
    wire [2:0] memory_option;

    assign en_fetch = (ctr == `CPU_STEP_FETCH);
    assign en_update_pc = (ctr == `CPU_STEP_WRITEBACK);

    assign en_load_rs1 = (ctr == `CPU_STEP_REGREAD) & _en_load_rs1;
    assign en_load_rs2 = (ctr == `CPU_STEP_REGREAD) & _en_load_rs2;
    assign en_store_rd = (ctr == `CPU_STEP_REGUPD) & _en_store_rd;
    assign en_store_main = (ctr == `CPU_STEP_WRITEBACK) & _en_store_main;
    assign en_load_main = (ctr == `CPU_STEP_WRITEBACK) & _en_load_main;

    fetcher_v3 fetcher0(
        .clk(clk),
        .fetcher_option(fetcher_option),
        .en_fetch(en_fetch),
        .instruction(instruction),
        .en_update_pc(en_update_pc),
        .data_rs1(data_rs1),
        .imm(imm)
    );

    decoder decoder0(
        .clk(clk),
        .instruction(instruction),
        
        .addr_rs1(addr_rs1),
        .addr_rs2(addr_rs2),
        .addr_rd(addr_rd),
        .imm(imm),
        
        .instruction_code(instruction_code),
        .lhs_input_type(lhs_type),
        .rhs_input_type(rhs_type),

        .fetcher_option(_fetcher_option),
        .memory_option(memory_option),

        .en_load_rs1(_en_load_rs1),
        .en_load_rs2(_en_load_rs2),
        .en_store_rd(_en_store_rd),
        .en_load_main(_en_load_main),
        .en_store_main(_en_store_main)
    );

    register_file_v2 register_file0(
        .clk(clk),
        .en_load_rs1(en_load_rs1),
        .addr_rs1(addr_rs1),
        .data_rs1(data_rs1),
        .en_load_rs2(en_load_rs2),
        .addr_rs2(addr_rs2),
        .data_rs2(data_rs2),
        .en_store_rd(en_store_rd),
        .addr_write(addr_rd),
        .data_write(data_rd)
    );

    execution exec0 (
        .clk(clk),
        // operation line
        .lhs_type(lhs_type),
        .rhs_type(rhs_type),
        .instruction_code(instruction_code),        
        // data instance
        .data_rs1(data_rs1),
        .data_rs2(data_rs2),
        .imm(imm),
        .pc(fetcher0.pc),
        // output
        .data_rd(data_rd),
        // pc operation line
        .default_update_pc_type(_fetcher_option),
        .update_pc_type(fetcher_option)
    );
    
    main_memory main_memory0 (
        .clk(clk),
        .memory_option(memory_option),
        .en_load(en_load_main),
        .addr_read(data_rs1 + imm),
        .data_read(data_rd),
        .en_store(en_store_main),
        .addr_write(data_rs1 + imm),
        .data_write(data_rd)
    );
    
    always @(negedge clk) begin
        ctr <= (ctr + 1) % `CPU_STEPSIZE;
    end
endmodule
