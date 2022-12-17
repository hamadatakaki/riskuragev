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

module main_memory #(
    parameter ADDRESS_LENGTH = 32,
    parameter DATA_LENGTH = 32
) (
    input wire clk,
    input wire [2:0] memory_option,
    input wire en_load,
    input wire [ADDRESS_LENGTH - 1:0] addr,
    output wire [DATA_LENGTH - 1:0] data_read,
    input wire en_store,
    input wire [DATA_LENGTH - 1:0] data_write
);
    wire [DATA_LENGTH - 1:0] data_r, data_w;

    wire [ADDRESS_LENGTH - 1:0] _addr;
    wire [1:0] memdiff;
    
    assign _addr = addr >> 2;
    assign memdiff = addr[1:0];

    wire [1:0] bhw_type;
    wire unsigned_load;
    wire [3:0] store_mask;

    assign bhw_type = memory_option[1:0];
    assign unsigned_load = memory_option[2];
    assign store_mask = ((bhw_type == `MEMORY_TYPE_HALF_WORD) ? 4'b0011 :
                         (bhw_type == `MEMORY_TYPE_BYTE) ? 4'b0001 :
                         4'b1111) << memdiff;
                            
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

    wire [DATA_LENGTH - 1:0] data_r_;

    assign data_r_ = data_r >> (memdiff * 8);
    assign data_read = MEMORY_RESHAPE(data_r_, bhw_type, ~unsigned_load);
    assign data_w = data_write << (memdiff * 8);

    block_ram_v2 ram0 (
        .clk(clk),
        .en_store(en_store),
        .en_load(en_load),
        .store_mask(store_mask),
        .addr(_addr),
        .data_read(data_r),
        .data_write(data_w)
    );

//    block_ram ram0 (
//        .clk(clk),
//        .addr_read(_addr),
//        .data_read(data_r),
//        .en_store(en_store),
//        .en_load(en_load),
//        .addr_write(_addr),
//        .data_write(data_w)
//    );
endmodule
