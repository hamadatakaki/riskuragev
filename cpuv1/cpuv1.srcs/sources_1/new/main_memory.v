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
    input wire [31:0] addr,
    output wire [31:0] data_read,
    input wire en_store,
    input wire [31:0] data_write
);
    wire [31:0] _addr, data_r, data_w;

    assign _addr = addr >> 2;

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

    function [31:0] MEMORY_COVER (
        input [31:0] ORIGIN,
        input [31:0] COVER,
        input [1:0] TYPE
    ); 
        begin
            MEMORY_COVER = (TYPE == `MEMORY_TYPE_BYTE) ? { ORIGIN[31:8], COVER[7:0] } :
                           (TYPE == `MEMORY_TYPE_HALF_WORD) ? { ORIGIN[31:16], COVER[15:0] } :
                           COVER;
        end
    endfunction

    assign data_read = MEMORY_RESHAPE(data_r, bhw_type, ~unsigned_load);
    assign data_w = MEMORY_COVER(data_r, data_write, bhw_type);

    block_ram ram0 (
        .clk(clk),
        .addr_read(_addr),
        .data_read(data_r),
        .en_store(en_store),
        .en_load(en_load),
        .addr_write(_addr),
        .data_write(data_w)
    );
endmodule
