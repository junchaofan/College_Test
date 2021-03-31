module sl #(parameter N=32)(  
      input [N-1:0] a,   //n位数a
      input [N-1:0] b,   //n位数b
	  input clk,
      input c,           //选择数,为0选a，否则选b
      output reg [N-1:0] out        //输出
);  
always @(posedge clk)
    begin
      out= (c==1'b0) ? a : b; 
    end 
endmodule 			  