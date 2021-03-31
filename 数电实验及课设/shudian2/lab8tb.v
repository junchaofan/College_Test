`timescale 1ns/1ps

module lab8tb();

reg [2:0]A,B;
wire F1,F2,F3;
wire [5:0]LED;
lab8 test(A,B,F1,F2,F3,LED);

integer countA=12;
integer countB=5;
integer i;
initial begin
A=3'b000;
B=3'b000;
end

always begin
for (i=0; i<4; i=i+1) begin
#20 A=countA&7;
    B=countB&7;
    countA=countA>>1;
	countB=countB>>1;
end
end

endmodule