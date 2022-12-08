`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/07 21:37:21
// Design Name: 
// Module Name: sim_decoder
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

`define echo(code, rs1, rs2, rd, imm) \
    $display("instcode, rd, rs1, rs2, imm:", code, ",", rd, ",", rs1, ",", rs2, ",", imm)

`define test_decoder(_inst) \
    inst = _inst; \
    `echo(inst_code, rs1, rs2, rd, imm); \
    # 5

module sim_decoder();
    reg [31:0] inst;
    
    wire [5:0] inst_code;
    wire [4:0] rs1, rs2, rd;
    wire [31:0] imm;

    decoder dec0 (
        .inst(inst),
        .inst_code(inst_code),
        .rs1(rs1),
        .rs2(rs2),
        .rd(rd),
        .imm(imm)
    );
    
    initial begin 
        #5
        
        `test_decoder(32'h1440023);  // Sb, 9, 8, 20
        `test_decoder(32'h881023);  // Sh, 2, 16, 8
        `test_decoder(32'h18ba023);  // Sw, 14, 23, 24
        `test_decoder(32'h1b18063);  // Beq, 19, 3, 27
        `test_decoder(32'h1b69063);  // Bne, 30, 13, 27
        `test_decoder(32'h136c063);  // Blt, 29, 13, 19
        `test_decoder(32'h1d75063);  // Bge, 23, 14, 29
        `test_decoder(32'h1e56063);  // Bltu, 23, 10, 30
        `test_decoder(32'h1077063);  // Bgeu, 14, 14, 16
        `test_decoder(32'hf37);  // LUi, 30, 22, 15
        `test_decoder(32'h517);  // AUiPC, 10, 31, 1
        `test_decoder(32'h54393);  // XORi, 7, 10, 8
        `test_decoder(32'ha6013);  // ORi, 0, 20, 13
        `test_decoder(32'h4f793);  // ANDi, 15, 9, 0
        `test_decoder(32'h58493);  // ADDi, 9, 11, 16
        `test_decoder(32'hc2813);  // SLTi, 16, 24, 24
        `test_decoder(32'h83293);  // SLTiu, 5, 16, 9
        `test_decoder(32'h8ca93);  // XORi, 21, 17, 19
        `test_decoder(32'hc6993);  // ORi, 19, 24, 20
        `test_decoder(32'hf213);  // ANDi, 4, 1, 28
        `test_decoder(32'h78c03);  // Lb, 24, 15, 14
        `test_decoder(32'h51483);  // Lh, 9, 10, 25
        `test_decoder(32'h32683);  // Lw, 13, 6, 12
        `test_decoder(32'h9c683);  // Lbu, 13, 19, 2
        `test_decoder(32'h25503);  // Lhu, 10, 4, 12
        `test_decoder(32'he0767);  // JALR, 14, 28, 26
        `test_decoder(32'h648933);  // ADD, 18, 9, 6
        `test_decoder(32'h40a50833);  // SUB, 16, 10, 10
        `test_decoder(32'h1a41133);  // SLL, 2, 8, 26
        `test_decoder(32'h152a733);  // SLT, 14, 5, 21
        `test_decoder(32'hd6b7b3);  // SLTu, 15, 13, 13
        `test_decoder(32'hec3b3);  // XOR, 7, 29, 0
        `test_decoder(32'hd4d533);  // SRL, 10, 9, 13
        `test_decoder(32'h41955333);  // SRA, 6, 10, 25
        `test_decoder(32'h7e333);  // OR, 6, 15, 0
        `test_decoder(32'h98f933);  // AND, 18, 17, 9
        `test_decoder(32'h98f933);  // AND, 18, 17, 9

        $finish;
    end
endmodule
