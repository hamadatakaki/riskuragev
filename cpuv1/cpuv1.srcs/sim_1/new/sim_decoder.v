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

`define test_decoder(_inst) \
    inst <= _inst; \
    $monitor(alucode, rs1, rs2, rd, imm); \
    # 5

module sim_decoder();
    reg [31:0] inst;
    
    wire [5:0] alucode;
    wire [4:0] rs1, rs2, rd;
    wire [31:0] imm;

    decoder dec0 (
        .inst(inst),
        .alucode(alucode),
        .rs1(rs1),
        .rs2(rs2),
        .rd(rd),
        .imm(imm)
    );
    
    initial begin 
        #5
        
        `test_decoder( 32'hf8a93 );
        `test_decoder( 32'hfaa93 );
        `test_decoder( 32'hfba93 );
        `test_decoder( 32'hfca93 );
        `test_decoder( 32'hfea93 );
        `test_decoder( 32'hffa93 );
        `test_decoder( 32'hf8a83 );
        `test_decoder( 32'hf9a83 );
        `test_decoder( 32'hfaa83 );
        `test_decoder( 32'hfca83 );
        `test_decoder( 32'hfda83 );
        `test_decoder( 32'hf8ae7 );
        `test_decoder( 32'haf8ab3 );
        `test_decoder( 32'h40af8ab3 );
        `test_decoder( 32'haf9ab3 );
        `test_decoder( 32'hafaab3 );
        `test_decoder( 32'hafbab3 );
        `test_decoder( 32'hafcab3 );
        `test_decoder( 32'hafdab3 );
        `test_decoder( 32'h40afdab3 );
        `test_decoder( 32'hafeab3 );
        `test_decoder( 32'haffab3 );
        `test_decoder( 32'haf8023 );
        `test_decoder( 32'haf9023 );
        `test_decoder( 32'hafa023 );
        `test_decoder( 32'haf8063 );
        `test_decoder( 32'haf9063 );
        `test_decoder( 32'hafc063 );
        `test_decoder( 32'hafd063 );
        `test_decoder( 32'hafe063 );
        `test_decoder( 32'haff063 );
        `test_decoder( 32'hab7 );
        `test_decoder( 32'ha97 );
        `test_decoder( 32'hfca93 );
        `test_decoder( 32'hfea93 );
        `test_decoder( 32'hffa93 );

        $finish;
    end
endmodule
