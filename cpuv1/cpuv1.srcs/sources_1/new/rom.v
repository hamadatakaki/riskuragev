`timescale 1ns / 1ps

module distributed_rom(
    input wire clk,
    input wire [31:0] addr,
    output wire [31:0] data
);
    reg [31:0] mem [0:31];

    assign data = mem[addr];
endmodule

module block_rom(
    input wire clk,
    input wire [31:0] addr,
    output reg [31:0] data
);
    reg [31:0] mem [0:31];

    always @(posedge clk) begin
        data <= mem[addr];
    end
endmodule
