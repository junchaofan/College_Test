`timescale 1ns / 1ps

module lab1_b(x,clk,q0,q1,y,led);
input x,clk;
output q0,q1,y,led;
wire t0,t1;
assign t0=1;
assign t1=q0^x;
assign y=(~x) | q1;
assign led=x;
T test1(clk,t0,q0);
T test2(clk,t1,q1);
	
endmodule

module T(
	input clk,t,
	output q
);
reg q;
initial
q=1'b0;
always @(negedge clk) begin
if(t) 
   q<=~q;
else 
   q<=q;
end

endmodule


