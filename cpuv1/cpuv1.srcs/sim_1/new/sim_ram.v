`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/11 22:52:28
// Design Name: 
// Module Name: sim_ram
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

module sim_ram;

    reg clk = 0;
    reg [31:0] addr_r = 0;

    reg write = 0;
    reg [31:0] addr_w = 0;
    reg [31:0] data_w = 0;

    wire [31:0] data_r;

    block_ram ram0(
        .clk(clk),
        .addr_read(addr_r),
        .data_read(data_r),
        .write(write),
        .addr_write(addr_w),
        .data_write(data_w)
    );

    always #(`CYCLE_NS / 2) begin
        clk <= ~clk;
    end

//    always @(posedge clk) begin
//        addr <= addr + 1;
//    end

    initial begin
        $readmemh("./sim_ram_1.hex", ram0.mem, 0);
    end

    initial begin
        #(`CYCLE_NS)    addr_r <= 0;
        #(`CYCLE_NS)    addr_r <= 1;
        #(`CYCLE_NS)    addr_r <= 2;
        #(`CYCLE_NS)    addr_r <= 3;
        #(`CYCLE_NS)    addr_r <= 4;
        #(`CYCLE_NS)    addr_r <= 5;

        $finish;
    end

endmodule
