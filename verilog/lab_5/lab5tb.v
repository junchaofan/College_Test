module lab5tb();

wire next_zero=0;
reg clk,rst,start;

lab5  lab(.clk(clk),.rst(rst),.next(next),.next_zero(next_zero),
.(LD_SUM)LD_SUM,.(LD_NEXT)LD_NEXT,.(A_SEL)A_SEL,.(SUM_SEL)SUM_SEL,.(NEXT_SEL)NEXT_SEL,.(DONE)DONE);
initial begin
    #20;
    clk=1'b0;
    rst=1'b1;
    start=1'b0;
    #20;
    clk=1'b1;
    rst=1'b0;
    start=1'b1;
    end

always begin
    #20 clk=~clk;
    end 
endmodule