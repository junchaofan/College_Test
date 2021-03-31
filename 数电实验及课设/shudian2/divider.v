module divider (clk, clk_N);
input clk;                     
output reg clk_N;               
parameter N = 100_000_000;      
reg [31:0] counter;             
always @(posedge clk)  begin   
                              
    if(counter>=N/2)
    begin
    	clk_N<=~clk_N;
    	counter<=0;
    end
    else
    	counter<=counter+1;
end                           
endmodule
