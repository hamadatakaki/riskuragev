`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/13 17:27:31
// Design Name: 
// Module Name: branch
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

`include "instruction.vh"
`include "fetcher.vh"

module branch (
    input wire [31:0] data_rs1, data_rs2,
    input wire [5:0] instruction_code,
    input wire [1:0] default_update_pc_type,
    output wire [1:0] update_pc_type
);
    wire overwrite;
    assign overwrite = (instruction_code == `INST_BEQ) ? (data_rs1 == data_rs2) :
                       (instruction_code == `INST_BNE) ? (data_rs1 != data_rs2) :
                       (instruction_code == `INST_BLT) ? ($signed(data_rs1) < $signed(data_rs2)) :
                       (instruction_code == `INST_BGE) ? ($signed(data_rs1) >= $signed(data_rs2)) :
                       (instruction_code == `INST_BLTU) ? (data_rs1 < data_rs2) :
                       (instruction_code == `INST_BGEU) ? (data_rs1 >= data_rs2) :
                       0;
                     
    assign update_pc_type = overwrite ? `UPD_PC_IMM : default_update_pc_type;
endmodule
