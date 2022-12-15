`timescale 1ns / 1ps

module distributed_rom #(
    parameter CAPACITY = 32'h1000
) (
    input wire clk,
    input wire [31:0] addr,
    output wire [31:0] data
);
    reg [31:0] mem [0:CAPACITY - 1];

    assign data = mem[addr];
endmodule

module block_rom #(
    parameter CAPACITY = 32'h1000
) (
    input wire clk,
    input wire en_read,
    input wire [31:0] addr,
    output reg [31:0] data
);
    reg [31:0] mem [0:CAPACITY - 1];

    always @(posedge clk) begin
        if (en_read) begin
            data <= mem[addr];
        end
    end
endmodule
