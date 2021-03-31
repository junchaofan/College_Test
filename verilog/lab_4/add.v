module add #(parameter N=32)(  
      input [N-1:0] a,
      input [N-1:0] b, 
      input clk, rst,
	  output reg [N-1:0] Q
);  
reg cout;
wire cin=1'b0;
always @(posedge clk) begin
    if (~rst)
	    begin
            {cout,Q}= a + b + cin; 
		end
	else
        Q<=0;
end
endmodule	    