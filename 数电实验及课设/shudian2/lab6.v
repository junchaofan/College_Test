`timescale 1ns/1ps

module lab6(clk,x,z,led);
input clk,x;
output reg z;
output [3:0]led;
reg [2:0]state;
assign led[2:0]=state[2:0];
assign led[3]=x;
parameter A=0,B=1,C=2,D=3,E=4,F=5; 
initial begin
    state<=A;
    z<=1'b0;
end
always @(posedge clk) begin

    case(state)
	A:begin
	z<=1'b0;
	if (x)
	state<=B;
	else
	state<=A;
	end
	
	B:begin
	z<=1'b0;
	if (x)
	state<=B;
	else
	state<=C;
	end
	
	C:begin
	z<=1'b0;
	if (x)
	state<=D;
	else
	state<=A;
	end
	
	D:begin
	z<=1'b0;
	if (x)
	state<=E;
	else
	state<=C;
	end
	
	E:begin
	z<=1'b1;
	if (x)
	state<=B;
	else
	state<=F;
	end
	
	F:begin
	z<=1'b0;
	if (x)
	state<=B;
	else
	state<=A;
	end
	
	default:begin
	state<=A;
	end

	endcase
end
    
endmodule