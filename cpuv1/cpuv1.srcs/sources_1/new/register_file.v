`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/08 03:30:58
// Design Name: 
// Module Name: register_file
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


module register_file(
    input wire clk,
    input wire write,
    input wire [5:0] rs1_addr,
    input wire [5:0] rs2_addr,
    input wire [31:0] write_data,
    output wire [31:0] read_rs1_data,
    output wire [31:0] read_rs2_data
);
    reg [31:0] mem [0:5];

    assign read_rs1_data = mem[rs1_addr];
    assign read_rs2_data = mem[rs2_addr];

    always @(posedge clk) begin
        if (write) begin
            mem[rs1_addr] <= write_data;
        end
    end
endmodule
