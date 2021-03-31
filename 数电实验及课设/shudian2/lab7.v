`timescale 1ns/1ps

module lab7(A,B,F1,F2,F3);
input A,B;
output F1,F2,F3;

assign F1=(A>B)? 1'b1:1'b0;
assign F2=(A==B)? 1'b1:1'b0;
assign F3=(A<B)? 1'b1:1'b0;
    
    
endmodule