`timescale 1ns/1ps

module lab5(sin,cp,m,ld,clr,qout,qcc,led);
input [3:0]sin;
input cp,clr,ld,m;
output [3:0] qout;
output qcc;
output [6:0]led;
//wire clk_N;
//divider #(25_000_000) divider1(.clk(cp),.clk_N(clk_N));
//counter #(4'b0010,4'b1001) fun(sin,clk_N,m,ld,clr,qout,qcc,led);
counter #(4'b0010,4'b1001) fun(sin,cp,m,ld,clr,qout,qcc,led);

endmodule