`timescale 1ns/1ps

module lab3(clk,sig_nsyn,q1,q2,sig_syn,out);
input clk,sig_nsyn;
output q1,q2,sig_syn,out;
	wire clk_N;
	divider #(75_000_000) testa(clk,clk_N);
	pipe3b testb(sig_nsyn,clk_N,q1,q2,sig_syn,out);
//    pipe3b testb(sig_nsyn,clk,q1,q2,sig_syn,out);
endmodule

module pipe3b(
    input sig_nsyn,clk,
    output reg q1,q2,sig_syn,
    output out
      );
initial begin
q1<=0;
q2<=0;
sig_syn<=0;
end
assign out=sig_nsyn;
always @(posedge clk) begin
q2<=q1;
sig_syn<=q2;
q1<=sig_nsyn;
end	
endmodule

module divider (clk, clk_N);
input clk;                      // 系统时钟
output reg clk_N;               // 分频后的时钟
parameter N = 1000_000_000;      // 1Hz的时�?,N=fclk/fclk_N
reg [31:0] counter;             /* 计数器变量，通过计数实现分频�?
                                   当计数器�?0计数�?(N/2-1)时，
                                   输出时钟翻转，计数器清零 */
always @(posedge clk)  begin    // 时钟上升�?
                              // 功能实现
    if(counter>=N)
    begin
    	clk_N<=~clk_N;
    	counter<=0;
    end
    else
    	counter<=counter+1;
end                           
endmodule