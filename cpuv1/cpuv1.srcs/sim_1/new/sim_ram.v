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
`define ADDLEN 4
`define DATALEN 16

`define read_test(adr) addr_r <= adr
`define write_test(adw, dataw) write <= 1; addr_w <= adw; addr_r <= adw - 1; data_w <= dataw

module sim_ram;
    
    reg clk = 0;
    reg [`ADDLEN - 1:0] addr_r = 0;

    reg write = 0;
    reg [`ADDLEN - 1:0] addr_w = 0;
    reg [`DATALEN - 1:0] data_w = 0;

    wire [`DATALEN - 1:0] data_r;

    block_ram #(
        .ADDRESS_LENGTH(`ADDLEN),
        .DATA_LENGTH(`DATALEN)
    ) ram0(
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
        $readmemh("./sim_ram_2.hex", ram0.mem, 0);
    end

    initial begin
        #(`CYCLE_NS)    `read_test(0);
        #(`CYCLE_NS)    `read_test(1);
        #(`CYCLE_NS)    `read_test(2);
        #(`CYCLE_NS)    `read_test(3);

        #(`CYCLE_NS)
        write <= 1;
        addr_w <= 1;
        addr_r <= 0;
        data_w <= 0123_4567;

        #(`CYCLE_NS)    `write_test(0, 32'h0000);
        #(`CYCLE_NS)    `write_test(1, 32'h1111);
        #(`CYCLE_NS)    `write_test(2, 32'h2222);
        
        #(`CYCLE_NS)    `read_test(2);
        
        #(`CYCLE_NS)
        $finish;
    end

endmodule
