`timescale 1ns / 1ps

module lab_3top(clk,out);
input clk;
wire clk_N;
output[2:0] out; 
divider(clk,clk_N);
counter(clk_N,out);
endmodule