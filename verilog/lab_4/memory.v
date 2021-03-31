module memory #(parameter N=32,parameter LEN=16)(
input [N-1:0]read_addr,
input clk,
output reg [N-1:0]Q
);
reg [N-1:0]list[LEN-1:0];
integer count;
assign list[0]=8'h00000003 ;
assign list[1]=8'h00000002 ;
assign list[2]=8'h00000000 ;
assign list[3]=8'h00000007 ;
assign list[4]=8'h00000004 ;
assign list[5]=8'h00000000 ;
assign list[6]=8'h00000000 ;
assign list[7]=8'h0000000b ;
assign list[8]=8'h00000006 ;
assign list[9]=8'h00000000 ;
assign list[10]=8'h00000000 ;
assign list[11]=8'h00000000 ;
assign list[12]=8'h00000008 ;
assign list[13]=8'h00000000 ;
assign list[14]=8'h00000000 ;
assign list[15]=8'h00000000 ;
reg [LEN-1:0]addr;
assign addr=read_addr;
always @(posedge clk) begin
	    Q<=list[addr];
	end
endmodule