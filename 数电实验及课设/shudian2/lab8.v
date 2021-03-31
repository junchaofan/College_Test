`timescale 1ns/1ps

module lab8(A,B,F1,F2,F3,LED);
input [2:0]A,B;
output F1,F2,F3;
output [5:0]LED;
wire [2:0]FA,FB,FC,TA,TB;
lab7 TEST1(A[2],B[2],FA[2],FB[2],FC[2]);
lab7 TEST2(A[1],B[1],FA[1],FB[1],FC[1]);
lab7 TEST3(A[0],B[0],FA[0],FB[0],FC[0]);
assign F1=FA[2] | (FA[1] & FB[2]) | (FB[2] & FB[1] & FA[0]);
assign F2=FB[2] & FB[1] & FB[0];
assign F3=FC[2] | (FB[2] & FC[1]) | (FB[2] & FB[1] & FC[0]);
assign LED[2:0]=A[2:0];
assign LED[5:3]=B[2:0];

endmodule