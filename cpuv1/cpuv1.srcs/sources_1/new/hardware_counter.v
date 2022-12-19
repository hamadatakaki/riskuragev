`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/12/18 05:58:22
// Design Name: 
// Module Name: hardware_counter
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


module hardware_counter(
    input CLK_IP,
    input RSTN_IP,
    output [31:0] COUNTER_OP
);
    reg [31:0] cycles;

    assign COUNTER_OP = cycles;
    
    initial begin
        cycles <= 32'd0;
    end
 
    always @(posedge CLK_IP or negedge RSTN_IP) begin
        if(!RSTN_IP)begin
            cycles <= 32'd0;
        end else begin
            cycles <= cycles + 1;
        end
    end
endmodule
