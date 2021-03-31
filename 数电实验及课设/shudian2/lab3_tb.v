`timescale 1ns/1ps

module lab3_tb();

reg sig_nsyn,clk;
wire q1,q2,sig_syn,out;
lab3 test(clk,sig_nsyn,q1,q2,sig_syn,out);

initial begin
sig_nsyn<=1'b1;
clk<=1'b0;
end

always begin
#20 clk=~clk;
#60 sig_nsyn=~sig_nsyn;
end

endmodule