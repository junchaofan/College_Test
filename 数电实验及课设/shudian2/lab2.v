`timescale 1ns / 1ps

module lab2(
	input x,
	output  z,q1,q2,q3,q4
    );
wire j1, k1, c1, j2, k2, c2, j3, k3, c3, j4, k4, c4;
assign j1=1'b1;
assign k1=1'b1;
assign c1=x;
assign j2=~q4;
assign k2=1'b1;
assign c2=q1;
assign j3=1'b1;
assign k3=1'b1;
assign c3=q2;
assign j4=q2 & q3;
assign k4=1'b1;
assign c4=q1;
assign z=q4 & q1 & x;
choose jk1(j1,k1,c1,q1);
choose jk2(j2,k2,c2,q2);
choose jk3(j3,k3,c3,q3);
choose jk4(j4,k4,c4,q4); 
endmodule

module choose(j,k,c,q);
input j,k,c;
output reg q;
initial
q=1'b0;
always @(negedge c) begin
    case ({j,k})
	2'b00: q<=q; 
	2'b01: q<=1'b0;
	2'b11: q<=~q;
	2'b10: q<=1'b1;
	default: q<=q;
	endcase
end
endmodule	