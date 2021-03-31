`timescale 1ns/1ps

module lab4(sin,cp,m,ld,clr,qout,qcc,led);
parameter min=4'b0000;
parameter max=4'b1111;
input [3:0]sin;
input cp,clr,ld,m;
output reg [3:0] qout;
output reg qcc;
output [6:0]led;
initial begin
qout<=min;
qcc<=1'b1;
end
assign led[3:0]=sin[3:0];
assign led[4]=m;
assign led[5]=ld;
assign led[6]=clr;
always@(posedge cp) begin
if(~clr) begin
    qout<=min;
    qcc<=1'b1;
    end
else if(~ld) begin
	qout<=sin;
	qcc<=1'b1;
	end
else if(m) begin
    if(qout==max) begin
	qout<=min;
	qcc<=1'b0;
	end
	else begin
	qout<=qout+1;
	qcc<=1'b1;
    end
	end
else begin
    if(qout==min) begin
	qout<=max;
	qcc<=1'b0;
	end
	else begin
	qout<=qout-1;
	qcc<=1'b1;
	end
	end
end
endmodule