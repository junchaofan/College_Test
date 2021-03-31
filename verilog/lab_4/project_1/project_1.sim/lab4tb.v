`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2018/06/07 08:30:16
// Design Name: 
// Module Name: lab4tb
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

module lab4tb;
reg clk,rst,load,LD_SUM,LD_NEXT,A_SEL,SUM_SEL,NEXT_SEL,NEXT_ZERO;
reg [N-1] data=0;
    reg [N-1] Sum,Out1,Out2; 
initial
    begin
    clk<=1;
    rst<=1;
    NEXT_ZERO<=0;
    lab4 lab_a (clk,rst,load,LD_SUM,LD_NEXT,A_SEL,SUM_SEL,NEXT_SEL,NEXT_ZERO);
    end
endmodule
