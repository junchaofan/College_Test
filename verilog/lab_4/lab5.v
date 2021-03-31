'timescale 1ns/1ps

module lab5 #(parameter N=32) (clk,rst,start,
next_zero,LD_SUM,LD_NEXT,A_SEL,SUM_SEL,NEXT_SEL);
input clk,rst,start,next_zero;
output reg LD_SUM,LD_NEXT,A_SEL,SUM_SEL,NEXT_SEL,DONE;
reg [N-1] Data,Sum,Out1,Out2,Next,Addr;
reg next_zero=0;

initial
    mpy_state<=START;
always @(posedge clk) begin:process
	if(rst)
		mpy_state<=START;
		
    case(mpy_state)
	    START:
	        if(start)
			begin
			    mpy_state<=SUM;
			    Addr<=0;
			    Next<=0;
			end   
		    else
		    begin
			    mpy_state<=START;
			    LD_SUM<=0;
			    LD_NEXT<=0;
			    SUM_SEL<=0;
			    NEXT_SEL<=0;
	 		    A_SEL<=0;
	 		    DONE<=0;
		    end
	
	    SUM:
		    begin
			    LD_SUM<=1;
			    LD_NEXT<=0;
			    SUM_SEL<=1;
			    NEXT_SEL<=1;
			    A_SEL<=1;
			    DONE<=0;
			    memory mem_a(Addr,clk,Next);
			    add add_a(Sum,Next,clk,rst,Out1);
			    sl sl_sum(0,Out1,clk,SUM_SEL,Out2);
			    sum sum_a(Out2,clk,rst,LD_SUM,Sum);
			    start<=NEXT;
			end
			
	    NEXT:
		    begin
			    LD_SUM<=0;
			    LD_NEXT<=1;
			    SUM_SEL<=1;
			    NEXT_SEL<=1;
			    A_SEL<=0;
			    DONE<=0;
			    sl sl_next(0,Next,clk,NEXT_SEL,Out1);
			    next next_a(Out1,clk,ret,LD_NEXT,Next);
			    add add_b(Next,1,clk,rst,Out2);
			    sl sl_mem(Next,Out2,clk,A_SEL,Addr);
			    if (~next_zero)
			       mpy_state<=SUM;
			    else
				   mpy_state<=DONE;
				   
			end
			
		DONE:
            begin
                LD_SUM<=0;
				LD_NEXT<=0;
				SUM_SEL<=0;
				NEXT_SEL<=0;
				A_SEL<=0;
				DONE<=1;
				if (start)
				    mpy_state<=DONE;
				else
				    mpy_state<=START;
            end			
end
endmodule