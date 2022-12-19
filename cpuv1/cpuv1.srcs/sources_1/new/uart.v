`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/18 02:06:56
// Design Name: 
// Module Name: uart
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

`define UART_SYSTEM_CLOCK 100000000
`define UART_SERIAL_CLOCK 115200

module uart(
    // 配布されたファイルに合わせる
    input wire sys_clk_i,
    input wire sys_rstn_i,
    input wire uart_wr_i,
    input wire [7:0] uart_dat_i,
    output reg uart_tx
);
    reg [3:0] bitcount;
    reg [8:0] shifter;
    
    wire uart_busy = |bitcount[3:1];
    wire sending = |bitcount;
    
    // sys_clk_i is 100MHz. We want a 115200Hz clock.
    
    reg [28:0] d;
    wire [28:0] dInc = d[28] ? `UART_SERIAL_CLOCK : (`UART_SERIAL_CLOCK - `UART_SYSTEM_CLOCK);
    wire [28:0] dNxt = d + dInc;
    
    initial begin
        d = 0;
        uart_tx = 1;
        bitcount = 0;
        shifter = 0;
    end
    
    always @(posedge sys_clk_i or negedge sys_rstn_i) begin
        if (!sys_rstn_i) begin
            d <= 28'b0;
        end else begin
            d <= dNxt;
        end
    end
    
    wire ser_clk = ~d[28];
    
    always @(posedge sys_clk_i or negedge sys_rstn_i) begin
        if (!sys_rstn_i) begin
            uart_tx <= 1;
            bitcount <= 0;
            shifter <= 0;
        end else begin
            if (uart_wr_i & ~uart_busy) begin
                shifter <= { uart_dat_i[7:0], 1'h0 };
                bitcount <= (1 + 8 + 2);
            end
            
            if (sending & ser_clk) begin
                { shifter, uart_tx } <= {1'h1, shifter };
                bitcount <= bitcount - 1;
            end
        end
    end
endmodule
