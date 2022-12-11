`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/12 02:10:23
// Design Name: 
// Module Name: sim_register_file
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
`define N_CYCLES 15

`define test_write_register(t_wait, a, d) \
    write_regfile <= 1; \
    addr_write <= a; \
    data_write <= d; \
    #(`CYCLE_NS * t_wait)

module sim_register_file;

    reg clk = 0;
    reg [3:0] ctr = 0;
    wire [31:0] inst;
    wire write = 0;

    fetcher_v3 fetcher0(
        .clk(clk),
        .enable(ctr == 0),
        .write_pc(write_pc),
        .instruction(inst)
    );

    wire [4:0] rs1, rs2, rd;
    wire [5:0] inst_code;

    decoder decoder0(
        .inst_code(inst_code),
        .inst(inst),
        .rs1(rs1),
        .rs2(rs2),
        .rd(rd)
    );
    
    reg write_regfile = 0;
    wire [31:0] data_rs1, data_rs2;

    reg [4:0] addr_write = 0;
    reg [31:0] data_write;

    register_file_v3 register_file0 (
        .clk(clk),
        .write(write_regfile),
        .addr_rs1(rs1),
        .addr_rs2(rs2),
        .data_rs1(data_rs1),
        .data_rs2(data_rs2),
        .addr_write(addr_write),
        .data_write(data_write)
    );

    always #(`CYCLE_NS / 2) begin
        clk <= ~clk;
    end

    always @(posedge clk) begin
        ctr <= (ctr + 1) % 4;
    end

    initial begin
        $readmemh("./sim_register_file_1.hex", register_file0.mem);
        $readmemh("./instructions.hex", fetcher0.rom0.mem);
        
        #(`CYCLE_NS * `N_CYCLES);
        
        `test_write_register(4, 1, 1);
        `test_write_register(4, 2, 2);
        `test_write_register(4, 3, 4);
        `test_write_register(4, 4, 8);
        
        $finish;
    end
endmodule
