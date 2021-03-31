`timescale 1ns / 1ps 

module lab4 #(parameter N=32) (clk,rst,LD_SUM,LD_NEXT,A_SEL,SUM_SEL,NEXT_SEL,NEXT_ZERO);
input clk,rst,load,LD_SUM,LD_NEXT,A_SEL,SUM_SEL,NEXT_SEL;
output reg NEXT_ZERO;
assign NEXT_ZERO=0;
reg [N-1] data=0;
reg [N-1] Sum,Out1,Out2; 
memory mem_a (data,clk,Out1);
assign data = Out1;
add add_a (data,0,clk,rst,Sum);
sl sl_a (0,Sum,clk,SUM_SEL,Out1);
sl sl_b (0,Sum,clk,NEXT_SEL,Out2);
compare com_a (Out2,0,clk,NEXT_ZERO);
assign Sum = Out1;
sum sum_a (Sum,clk,rst,LD_SUM,Out1);
next next_a (Out2,clk,rst,LD_NEXT,data);
add add_b (data,1,clk,rst,Out2);
sl sl_c (data,Out2,A_SEL,Out1);

endmodule