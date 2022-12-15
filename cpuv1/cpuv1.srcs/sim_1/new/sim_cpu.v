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

`define CYCLE_NS  12.5
`define CYCLE_OPE 4
`define N_OPES    5
`define N_CYCLES  (`N_OPES * `CYCLE_OPE + 1)

module sim_cpu();

    reg clk = 0;
    
    cpu cpu0(.clk(clk));
    
    always #(`CYCLE_NS / 2) begin
        clk <= ~clk;
    end
    
    initial begin
        $readmemh("./sim_inst_load.hex", cpu0.fetcher0.rom0.mem, 32'h2000);
        // $readmemh("./sim_inst_blt_reg.hex", cpu0.register_file0.mem, 0);
        $readmemh("./sim_inst_load_mainmemory.hex", cpu0.main_memory0.ram0.mem);

        #(`CYCLE_NS * `N_CYCLES);
        
        // $writememh("../_dump_main_memory.hex", cpu0.main_memory0.ram0.mem);
        $finish;
    end
endmodule
