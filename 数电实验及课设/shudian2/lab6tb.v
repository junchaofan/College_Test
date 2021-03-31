`timescale 1ns/1ps

module lab6tb();

reg x,clk;
wire z,led;
integer count=109;
lab6 test(clk,x,z,led);
initial begin
x=1'b0;
clk=1'b0;
end

always begin
#20 clk=~clk;
#45 x=count&1;
count=count>>1;
#20 clk=~clk;
end

endmodule