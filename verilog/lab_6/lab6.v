`timescale 1ns/1ps

module lab5 (clk,rst,start,next_zero);
parameter N=32;
input clk,rst,start,next_zero;
reg LD_SUM,LD_NEXT,A_SEL,SUM_SEL,NEXT_SEL,DONE;
reg [N-1:0] Data,Sum,Out1,Out2,Next,Addr;
reg [1:0] mpy_state;
parameter START=0,SUM=1,NEXT=2,END=3;

initial
    if(rst)
		mpy_state<=START;
always @(posedge clk) begin
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
			    memory(Addr,clk,Next);
			    add(Sum,Next,clk,rst,Out1);
			    sl(0,Out1,clk,SUM_SEL,Out2);
			    sum(Out2,clk,rst,LD_SUM,Sum);
			    mpy_state<=NEXT;
			end
			
	    NEXT:
		    begin
			    LD_SUM<=0;
			    LD_NEXT<=1;
			    SUM_SEL<=1;
			    NEXT_SEL<=1;
			    A_SEL<=0;
			    DONE<=0;
			    sl(0,Next,clk,NEXT_SEL,Out1);
			    next(Out1,clk,rst,LD_NEXT,Next);
			    add(Next,1,clk,rst,Out2);
			    sl(Next,Out2,clk,A_SEL,Addr);
			    if (~next_zero)
			       mpy_state<=SUM;
			    else
				   mpy_state<=END;
				   
			end
			
		END:
            begin
                LD_SUM<=0;
				LD_NEXT<=0;
				SUM_SEL<=0;
				NEXT_SEL<=0;
				A_SEL<=0;
				DONE<=1;
				if (start)
				    mpy_state<=END;
				else
				    mpy_state<=START;
            end			
endcase
end
endmodule