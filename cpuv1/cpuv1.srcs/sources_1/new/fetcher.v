`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/08 02:56:14
// Design Name: 
// Module Name: fetcher
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

// without Program-Counter

module fetcher_v1(
    input wire [31:0] pc,
    output wire [31:0] instruction
);
    reg [31:0] mem [0:31];

    assign instruction = mem[pc];
endmodule

// with Program-Counter increment, overwrite

module fetcher_v2(
    input wire clk,
    input wire enable,
    input wire write_pc,
    input wire [31:0] pc_new,
    output wire [31:0] instruction
);
    reg [31:0] mem [0:31];
    reg [31:0] pc = 0;

    assign instruction = mem[pc];

    always @(posedge clk) begin
        if (enable) begin
            pc <= pc + 1;
            
            if (write_pc) begin
                pc <= pc_new;
            end
        end
    end
endmodule
