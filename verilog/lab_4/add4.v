//输入：被加数a，加数b，低进位cin
//输出:和so，高进位co
module add4(a,b,cin,so,co);  //四位二进制串行加法器
input [3:0] a,b;
input cin;
output [3:0] so;
output co;
wire  [3:0] c;
add (a[0],b[0],cin,so[0],c[0]);
add (a[1],b[1],c[0],so[1],c[1]);
add (a[2],b[2],c[1],so[2],c[2]);
add (a[3],b[3],c[2],so[3],c[3]);
assign co = c[3];
endmodule

module add(a,b,cin,so,co)  //一位二进制全加器
input a,b,cin;
output so,co;
assign so = a ^ b ^ cin;
assign co = (a & b) | (a & cin) | (b & cin);
endmodule

`timescale 1ns / 1ps

module sum(a,b,cin,so,co,n);
input [n:0] a,b;
input cin;
output [n:0] so;
output co;
reg  ci=cin;
reg  cout;
reg [3:0] i=n/4;
integer j,k;
for (j=0;j<i;j=j+1) 
    k = j*4+3;
	add4(a[k,j*4],b[k,j*4],ci,so[k,j*4],cout);
	ci=cout;