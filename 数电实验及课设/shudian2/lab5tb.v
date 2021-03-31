module lab5tb();
integer i;
reg [3:0] sin;
reg cp,m,ld,clr;
wire [3:0] qout;
wire qcc;
wire [6:0]led;
initial begin
	sin=4'b0100;
	m=1'b1;
	ld=1'b1;
	clr=1'b1;
	cp=1'b0;	
end	
lab5 test(.sin(sin),.cp(cp),.m(m),.ld(ld),.clr(clr),.qout(qout),.qcc(qcc),.led(led));
always begin
for (i=0; i<60;i=i+1) begin
    #20 cp=~cp;
    if (i==30)
    m=~m;
end	
end

endmodule
