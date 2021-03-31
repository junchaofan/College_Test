module add #(parameter N=32)(  
      input [N-1:0] a,
      input [N-1:0] b, 
      input clk, rst,
	  output reg [N-1:0] Q
);  
always @(posedge clk) begin
    if (~rst)
	    begin
            Q = a + b; 
		end
	else
        Q<=0;
end
endmodule	    