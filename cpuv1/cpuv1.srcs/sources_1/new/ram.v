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


module ram #(
    parameter ADDRESS_SIZE = 32'h8000
) (
    input wire clk,
    input wire en_load, en_store,
    input wire [3:0] mask_store,
    input wire [31:0] addr,
    output reg [31:0] data_read,
    input wire [31:0] data_write
);
    reg [31:0] mem [0:ADDRESS_SIZE - 1];

    always @(posedge clk) begin
        if (en_load) begin
            data_read <= mem[addr];
        end
        
        if (en_store) begin
            if (mask_store[0]) begin
                mem[addr][7:0] <= data_write[7:0];
            end
            
            if (mask_store[1]) begin
                mem[addr][15:8] <= data_write[15:8];
            end
            
            if (mask_store[2]) begin
                mem[addr][23:16] <= data_write[23:16];
            end
            
            if (mask_store[3]) begin
                mem[addr][31:24] <= data_write[31:24];
            end
        end
    end
endmodule

module block_ram_v2 #(
    parameter ADDRESS_SIZE = 32'h8000
) (
    input wire clk,
    input wire en_load, en_store,
    input wire [3:0] mask_store,
    input wire [31:0] addr,
    output reg [31:0] data_read,
    input wire [31:0] data_write
);
    reg [31:0] mem [0:ADDRESS_SIZE - 1];

    always @(posedge clk) begin
        if (en_load) begin
            data_read <= mem[addr];
        end
        
        if (en_store) begin
            if (mask_store[0]) begin
                mem[addr][7:0] <= data_write[7:0];
            end
            
            if (mask_store[1]) begin
                mem[addr][15:8] <= data_write[15:8];
            end
            
            if (mask_store[2]) begin
                mem[addr][23:16] <= data_write[23:16];
            end
            
            if (mask_store[3]) begin
                mem[addr][31:24] <= data_write[31:24];
            end
        end
    end
endmodule

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

module block_ram #(
    parameter ADDRESS_LENGTH = 32,
    parameter ADDRESS_SIZE = 32'h8000,
    parameter DATA_LENGTH = 32
) (
    input wire clk,
    input wire en_load,
    input wire [ADDRESS_LENGTH - 1:0] addr_read,
    output reg [DATA_LENGTH - 1:0] data_read,
    input wire en_store,
    input wire [ADDRESS_LENGTH - 1:0] addr_write,
    input wire [DATA_LENGTH - 1:0] data_write
);
    reg [DATA_LENGTH - 1:0] mem [0:ADDRESS_SIZE - 1];
    
    always @(posedge clk) begin
        if (en_load) begin
            data_read <= mem[addr_read];
        end
        
        if (en_store) begin
            mem[addr_write] <= data_write;
        end
    end
endmodule
