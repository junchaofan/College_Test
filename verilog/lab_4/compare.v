module compare #(parameter N=32)(  
    input [N-1:0] a,   
    input [N-1:0] b,   
	input clk,
    output reg out 
);  
always @(posedge clk)
    begin
        if (a == b)
	        out = 1'b1;
        else
	        out = 1'b0;
	end
endmodule 	