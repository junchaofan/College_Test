`timescale 1ns / 1ps

module lab1_b_tb();
wire y,led;
reg  x,clk;

lab1_b test(x,clk,q0,q1,y,led);

initial begin
  x=1'b1;
  clk=1'b0;
end

always begin
  #50 x = ~x;
  #20 clk=~clk;
end
endmodule