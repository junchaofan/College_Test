`timescale 1ns / 1ps

module add(clk, judge, control, max_num, now_num, sum_num, flag);
parameter limit_num=6'b000100;
input clk,control,judge;
input [5:0] max_num;
output reg [5:0] now_num,flag;
output reg [9:0] sum_num;
initial begin
    flag<=0;
    now_num<=0;
    sum_num<=0;
end
always @(posedge clk) begin
	if (~control) begin
	    flag<=0;
		now_num<=0;
		sum_num<=0;
    end else begin
      if (~judge) begin
         flag<=0;
         now_num<=0;
      end else begin
             if ((now_num<max_num) && (flag<limit_num)) begin
                sum_num <= sum_num+1;
                now_num <= now_num+1;
             end else begin
                now_num <= 0;		
                flag <= flag + 1;
             end
       end
    end
end

endmodule