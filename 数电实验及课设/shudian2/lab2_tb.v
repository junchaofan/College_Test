`timescale 1ns / 1ps

module lab2_tb;
reg x;
wire z,q1,q2,q3,q4;
lab2 test(.x(x),.z(z),.q1(q1),.q2(q2),.q3(q3),.q4(q4));

initial begin
x=1'b0;
end

always begin
#20 x=~x;
end

endmodule