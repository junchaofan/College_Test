`timescale 1ns/1ps

module lab5 (clk,rst,start,next_zero,LD_SUM,LD_NEXT,A_SEL,SUM_SEL,NEXT_SEL,DONE);
parameter N=32;
input clk,rst,start,next_zero;
output reg LD_SUM,LD_NEXT,A_SEL,SUM_SEL,NEXT_SEL,DONE;
reg [1:0] mpy_state;
parameter START=0,SUM=1,NEXT=2,END=3;

initial
    if(rst)
		mpy_state<=START;
always @(posedge clk) begin
    case(mpy_state)
	    START:
	        if(start)
			    mpy_state<=SUM;
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
			end
			
	    NEXT:
		    begin
			    LD_SUM<=0;
			    LD_NEXT<=1;
			    SUM_SEL<=1;
			    NEXT_SEL<=1;
			    A_SEL<=0;
			    DONE<=0;
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