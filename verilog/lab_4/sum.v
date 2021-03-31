module sum #(parameter N=32)(  
      input [N-1:0] D, 
	  input clk,
      input rst,
      input load,	  
      output reg [N-1:0] Q
);  

always @(posedge clk) begin
    if (~rst && load)
        Q<=D;
	else if (rst)
        Q<=0;	
end
endmodule 			 