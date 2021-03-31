`timescale 1ns/1ps

module lab7tb();

reg A,B;
wire F1,F2,F3;
lab7 test(A,B,F1,F2,F3);

integer countA=12;
integer countB=5;
integer i;
initial begin
A=1'b0;
B=1'b0;
end

always begin
for (i=0; i<4; i=i+1) begin
#20 A=countA&1;
    B=countB&1;
    countA=countA>>1;
	countB=countB>>1;
end
end

endmodule