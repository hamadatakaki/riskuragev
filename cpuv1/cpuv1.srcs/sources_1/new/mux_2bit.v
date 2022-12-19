`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/12 13:04:59
// Design Name: 
// Module Name: mux
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


module mux_1bit #(
    parameter DATA_LENGTH = 32
) (
    input wire ope,
    input wire [DATA_LENGTH - 1:0] in1, in2,
    output wire [DATA_LENGTH - 1:0] out
);
    assign out = (ope == 0) ? in1 : in2;
endmodule

module mux_2bit #(
    parameter DATA_LENGTH = 32
) (
    input wire [1:0] ope,
    input wire [DATA_LENGTH - 1:0] in1, in2, in3, in4,
    output wire [DATA_LENGTH - 1:0] out
);
    assign out = (ope == 0) ? in1 :
                 (ope == 1) ? in2 :
                 (ope == 2) ? in3 :
                 in4;
endmodule
