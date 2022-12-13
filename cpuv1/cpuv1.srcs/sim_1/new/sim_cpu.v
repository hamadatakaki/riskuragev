`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/08 11:02:32
// Design Name: 
// Module Name: sim_cpu
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
`define N_CYCLES 5

module sim_cpu();

    reg clk = 0;
    
    cpu cpu0(.clk(clk));
    
    always #(`CYCLE_NS / 2) begin
        clk <= ~clk;
    end
    
    initial begin
        $readmemh("./sim_inst_jalr.hex", cpu0.fetcher0.rom0.mem, 32'h2000);
    
        #(`CYCLE_NS * `N_CYCLES);
        
        $finish;
    end
endmodule
