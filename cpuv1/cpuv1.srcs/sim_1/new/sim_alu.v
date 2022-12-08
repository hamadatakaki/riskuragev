`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/08 14:13:23
// Design Name: 
// Module Name: sim_alu
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

`include "../../sources_1/new/alu.vh"

`define echo_alu(op, lhs, rhs, dst) \
    $display(op, "(", lhs, ",", rhs, "):", dst)

`define test_alu(_op, _lhs, _rhs) \
    op = _op; \
    lhs = _lhs; \
    rhs = _rhs; \
    #5; \
    `echo_alu(op, lhs, rhs, dst);


module sim_alu;
    reg [3:0] op;
    reg [31:0] lhs, rhs;
    wire [31:0] dst;
    
    alu alu0 (
        .alu_op(op),
        .lhs(lhs),
        .rhs(rhs),
        .dst(dst)
    );

    initial begin
        #5
        
        $display("testcase1:");
        
        `test_alu(`ALU_ADD, 32'd16, 32'd14);
        `test_alu(`ALU_SUB, 32'd16, 32'd10);
        `test_alu(`ALU_SLL, 32'd98, 32'd3);
        `test_alu(`ALU_SLT, 32'd33, 32'd4);
        `test_alu(`ALU_SLTU, 32'd70, 32'd5);
        `test_alu(`ALU_XOR, 32'd31, 32'd1);
        `test_alu(`ALU_SRL, 32'd4, 32'd1);
        `test_alu(`ALU_SRA, 32'd19, 32'd8);
        `test_alu(`ALU_OR, 32'd81, 32'd0);
        `test_alu(`ALU_AND, 32'd57, 32'd17);       
        
        $display("testcase2:");
        
        `test_alu(`ALU_ADD, 32'd48, 32'd1);
        `test_alu(`ALU_SUB, 32'd57, 32'd14);
        `test_alu(`ALU_SLL, 32'd56, 32'd14);
        `test_alu(`ALU_SLT, 32'd2, 32'd20);
        `test_alu(`ALU_SLTU, 32'd18, 32'd58);
        `test_alu(`ALU_XOR, 32'd57, 32'd13);
        `test_alu(`ALU_SRL, 32'd33, 32'd13);
        `test_alu(`ALU_SRA, 32'd54, 32'd9);
        `test_alu(`ALU_OR, 32'd37, 32'd10);
        `test_alu(`ALU_AND, 32'd54, 32'd12);
        
        #5;
        $finish;
    end
endmodule
