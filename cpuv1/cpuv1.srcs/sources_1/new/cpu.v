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
    input wire clk, rst_n,
    output wire uart_tx
);
    reg [3:0] ctr = -1;
    wire [31:0] pc, instruction;

    wire [5:0] instruction_code;
    wire [1:0] lhs_type, rhs_type;    
    wire [4:0] addr_rs1, addr_rs2, addr_rd;
    wire [31:0] data_rs1, data_rs2, data_rd_exec, data_rd_memory, data_rd, imm;

    wire _en_load_rs1, _en_load_rs2, _en_store_rd, _en_store_main, _en_load_main,
         en_fetch, en_update_pc, en_load_rs1, en_load_rs2, en_store_rd, en_store_main, en_load_main;

    wire [1:0] fetcher_option, _fetcher_option;
    wire [2:0] memory_option;

    assign en_fetch = (ctr == `CPU_STEP_FETCH);
    assign en_update_pc = (ctr == `CPU_STEP_REGWRITE);
    assign en_load_rs1 = (ctr == `CPU_STEP_REGREAD) & _en_load_rs1;
    assign en_load_rs2 = (ctr == `CPU_STEP_REGREAD) & _en_load_rs2;
    assign en_store_rd = (ctr == `CPU_STEP_REGWRITE) & _en_store_rd;
    assign en_store_main = (ctr == `CPU_STEP_MEMACCESS) & _en_store_main;
    assign en_load_main = (ctr == `CPU_STEP_MEMACCESS) & _en_load_main;
    
    assign data_rd = _en_load_main ? data_rd_memory : data_rd_exec;

    fetcher fetcher0(
        .clk(clk),
        .fetcher_option(fetcher_option),
        .en_fetch(en_fetch),
        .instruction(instruction),
        .en_update_pc(en_update_pc),
        .data_rs1(data_rs1),
        .imm(imm),
        .program_counter(pc),
        .rst_n(rst_n)
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

    register_file register_file0(
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
        .pc(pc),
        // output
        .data_rd(data_rd_exec),
        // pc operation line
        .default_update_pc_type(_fetcher_option),
        .update_pc_type(fetcher_option)
    );

    wire [31:0] _data_rd_memory;

    main_memory main_memory0 (
        .clk(clk),
        .memory_option(memory_option),
        .addr(data_rs1 + imm),
        .en_load(en_load_main),
        .data_read(_data_rd_memory),
        .en_store(en_store_main),
        .data_write(data_rs2)
    );
    
    // uart

    wire [7:0] uart_IN_data;
    wire uart_we;
    wire uart_OUT_data;

    assign uart_IN_data = data_rs2[7:0];
    assign uart_we = (((data_rs1 + imm) == `UART_ADDR) && _en_store_main) ? 1'b1 : 1'b0;
    assign uart_tx = uart_OUT_data;

    uart uart0 (
        .sys_clk_i(clk),
        .sys_rstn_i(rst_n),
        .uart_tx(uart_OUT_data),
        .uart_wr_i(uart_we),
        .uart_dat_i(uart_IN_data)
    );

    // hardware counter
    
    wire [31:0] hc_OUT_data;

    hardware_counter hardware_counter0(
        .CLK_IP(clk),
        .RSTN_IP(rst_n),
        .COUNTER_OP(hc_OUT_data)
    );
    
    // mux_1bit
    assign data_rd_memory = ((instruction_code == `INST_LW) && ((data_rs1 + imm) == `HARDWARE_COUNTER_ADDR)) ? hc_OUT_data : _data_rd_memory;

//    initial begin
//        ctr <= 0;
//    end
    
    always @(negedge clk) begin
        if (rst_n) begin
            ctr <= 0;
        end
    
        ctr <= (ctr + 1) % `CPU_STEPSIZE;
    end
endmodule
