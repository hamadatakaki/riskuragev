`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/14 15:01:51
// Design Name: 
// Module Name: main_memory
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

`include "main_memory.vh"

module main_memory (
    input wire clk,
    input wire [2:0] memory_option,
    input wire en_load,
    input wire [31:0] addr_read,
    output wire [31:0] data_read,
    input wire en_store,
    input wire [31:0] addr_write,
    input wire [31:0] data_write
);
    wire [31:0] r_addr, w_addr, r_data, w_data;

    assign r_addr = addr_read >> 2;
    assign w_addr = addr_write >> 2;

    wire [1:0] bhw_type;
    wire unsigned_load;

    assign bhw_type = memory_option[1:0];
    assign unsigned_load = memory_option[2];

    function [31:0] MEMORY_RESHAPE (
        input [31:0] MEMORY,
        input [1:0] TYPE,
        input IS_SIGNED
    );
        begin
            MEMORY_RESHAPE = (TYPE == `MEMORY_TYPE_HALF_WORD) ? (
                                 (IS_SIGNED) ? { {16{MEMORY[15]}}, MEMORY[15:0] } : { {16{1'd0}}, MEMORY[15:0] } 
                             ) :
                             (TYPE == `MEMORY_TYPE_BYTE) ? (
                                 (IS_SIGNED) ? { {24{MEMORY[7]}}, MEMORY[7:0] } : { {24{1'd0}}, MEMORY[7:0] } 
                             ) :
                             MEMORY;
        end 
    endfunction

    assign data_read = MEMORY_RESHAPE(r_data, bhw_type, ~unsigned_load);
    assign w_data = MEMORY_RESHAPE(data_write, bhw_type, 0);

    block_ram ram0 (
        .clk(clk),
        .addr_read(r_addr),
        .data_read(r_data),
        .en_store(en_store),
        .en_load(en_load),
        .addr_write(w_addr),
        .data_write(w_data)
    );
endmodule
