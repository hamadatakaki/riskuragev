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

module register_file_v1(
    input wire clk,
    input wire write,
    input wire [4:0] rs1_addr,
    input wire [4:0] rs2_addr,
    input wire [4:0] write_addr,
    input wire [31:0] write_data,
    output wire [31:0] read_rs1_data,
    output wire [31:0] read_rs2_data
);
    reg [31:0] mem [0:4];

    assign read_rs1_data = mem[rs1_addr];
    assign read_rs2_data = mem[rs2_addr];

    always @(posedge clk) begin
        if (write) begin
            mem[write_addr] <= write_data;
        end
    end
endmodule

// v2: read syncronize.

module register_file_v2 (
    input wire clk,
    input wire en_load_rs1,
    input wire [4:0] addr_rs1,
    output reg [31:0] data_rs1,
    input wire en_load_rs2,
    input wire [4:0] addr_rs2, 
    output reg [31:0] data_rs2,
    input wire en_store_rd,
    input wire [4:0] addr_write,
    input wire [31:0] data_write
);
    reg [31:0] mem [0:31];
    
    initial begin
        mem[0] = 0;
    end
    
    always @(posedge clk) begin
        if (en_load_rs1) begin
            data_rs1 <= mem[addr_rs1];
        end
        
        if (en_load_rs2) begin
            data_rs2 <= mem[addr_rs2];
        end
        
        if (en_store_rd) begin
            mem[addr_write] <= data_write;
        end
    end
endmodule
