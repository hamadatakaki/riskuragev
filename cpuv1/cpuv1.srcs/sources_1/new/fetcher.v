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

`include "fetcher.vh"

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

// with Block ROM

module fetcher_v3(
    input wire clk,
    output wire [31:0] instruction,
    input wire en_update_pc,
    input wire [1:0] update_pc_type,
    input wire [31:0] data_rs1,
    input wire [31:0] imm
);
    reg [31:0] pc = `PC_INIT;

    wire [31:0] _pc;
    assign _pc = pc >> 2;

    block_rom #(
        .CAPACITY(`FETCHER_ROM_SIZE)
    ) rom0 (
        .clk(clk),
        .addr(_pc),
        .data(instruction)
    );

    always @(posedge clk) begin
        if (en_update_pc) begin
            pc <= (update_pc_type == `UPD_PC_IMM)    ? pc + imm : 
                  (update_pc_type == `UPD_PC_REGIMM) ? data_rs1 + imm :
                  (update_pc_type == `UPD_PC_INC)    ? pc + 32'd4 :
                  pc;
        end
    end

endmodule
