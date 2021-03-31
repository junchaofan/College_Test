`timescale 1ns / 1ps

module counter(clk, out);
input clk;                    // 计数时钟
output reg [2:0] out;             // 计数�?

always @(posedge clk)  begin  // 在时钟上升沿计数器加1
    if (out == 3'b111) begin
       out = 3'b000;
       end
    else
       out <= out+1;	
end                           
endmodule

