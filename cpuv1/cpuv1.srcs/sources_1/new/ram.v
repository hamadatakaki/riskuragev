`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/08 16:43:35
// Design Name: 
// Module Name: ram
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


module distributed_ram(
    input wire clk,
    input wire [31:0] addr_read,
    output wire [31:0] data_read,
    input wire write,
    input wire [31:0] addr_write,
    input wire [31:0] data_write
);
    reg [31:0] mem [0:31];

    assign data_read = mem[addr_read];
    
    always @(posedge clk) begin
        if (write) begin
            mem[addr_write] <= data_write;
        end
    end
endmodule

module block_ram(
    input wire clk,
    input wire [31:0] addr_read,
    output reg [31:0] data_read,
    input wire write,
    input wire [31:0] addr_write,
    input wire [31:0] data_write
);
    reg [31:0] mem [0:31];
    
    always @(posedge clk) begin
        data_read <= mem[addr_read];
        
        if (write) begin
            mem[addr_write] <= data_write;
        end
    end
endmodule
