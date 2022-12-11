`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/11 21:49:57
// Design Name: 
// Module Name: sim_fetcher
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

module sim_fetcher;

    reg clk = 0;
    reg [3:0] ctr = 0;
    
    reg write_pc = 0;
    reg [31:0] pc_new = 0;
    
    wire [31:0] instruction;

    fetcher_v3 fetcher0(
        .clk(clk),
        .enable(ctr == 0),
        .write_pc(write_pc),
        .pc_new(pc_new),
        .instruction(instruction)
    );
    
    always #(`CYCLE_NS / 2) begin
        clk <= ~clk;
    end

    always @(posedge clk) begin
        ctr <= (ctr + 1) % 4;
    end

    initial $readmemh("./sim_fetcher_1.hex", fetcher0.rom0.mem);

    initial begin
        #(`CYCLE_NS * 20);
        write_pc <= 1;
        pc_new <= 4;
        #(`CYCLE_NS);
        write_pc <= 0;
        #(`CYCLE_NS * 20);
        $finish;
    end

endmodule
