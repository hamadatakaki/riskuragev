`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/11 22:18:05
// Design Name: 
// Module Name: sim_rom
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

`define CYCLE_NS 10

module sim_rom;

    reg clk = 0;
    reg [31:0] addr = 0;
    
    wire [31:0] instruction;
    
    block_rom rom0(
        .clk(clk),
        .addr(addr),
        .data(instruction)
    );
    
    always #(`CYCLE_NS / 2) begin
        clk <= ~clk;
    end
    
    always @(posedge clk) begin
        addr <= addr + 1;
    end

    initial begin
        $readmemh("./sim_rom_1.hex", rom0.mem, 0);
    end

    initial begin
        #(`CYCLE_NS * 10);
        $finish;
    end

endmodule
