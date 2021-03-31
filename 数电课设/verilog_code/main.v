`timescale 1ns / 1ps

module main(clk, cont_set, update_set, max_num, stop_led, open_led, update_led, an, seg, led);
input clk,cont_set,update_set;     
input [5:0] max_num;    
output stop_led, open_led, update_led;
output [7:0] an, seg;
output [10:0] led;
wire [5:0] now_num,flag;
wire [9:0] sum_num;
wire clk_N,clk_T,control_set;
reg warning_led,working_led,full_led,change_led,done_led,update,judge;
reg [1:0] mpy_state;
reg [5:0] input_num;
parameter CHANGE=0,WORKING=1,FULL=2,limit_one=6'b011110,limit_all=100,limit_num=6'b000100;
assign led[5:0]=max_num[5:0];
assign open_led=cont_set;
assign stop_led=~cont_set;
assign update_led=update;
assign led[6]=change_led;
assign led[7]=working_led;
assign led[8]=full_led;
assign led[9]=warning_led;
assign led[10]=done_led;
assign control_set=cont_set & (~full_led);

initial begin
    judge<=0;
    update<=0;
	mpy_state<=CHANGE;
	warning_led<=0;
	working_led<=0;
	change_led<=1;
	full_led<=0;
	input_num<=0;
end
divider testa(clk, clk_N);
//add  testb(clk_N, judge, control_set, input_num, now_num, sum_num, flag);
add  testb(clk, judge, control_set, input_num, now_num, sum_num, flag);
divider #(150_000)testc(clk,clk_T);
show testd(clk_T, full_led, now_num, sum_num, an, seg);

always @(posedge update_set) begin
    update<=~update;
end

always @(posedge clk) begin
//always @(posedge clk_N) begin
	if (cont_set & update & change_led) begin 
	    done_led<=0;
		if(max_num > limit_one || max_num==0) begin
		    input_num<=0;
            warning_led<=1;
        end else begin
            input_num<=max_num;
			warning_led<=0;
			judge<=1;
	    end
	end
    if(cont_set) begin
        case (mpy_state) 
		CHANGE: begin 
			change_led<=1;
			if (judge) begin
				change_led<=0;
				mpy_state<=WORKING;
			end else
				mpy_state<=CHANGE;
			if (sum_num==limit_all) begin
                change_led<=0;  
                mpy_state<=FULL;
            end
		end
        
        WORKING: begin  
			working_led<=1;
			if (sum_num==limit_all-1) begin
			    working_led<=0;  
			    mpy_state<=FULL;
			end else begin
			     if (flag==limit_num) begin
			         judge<=0;
                     done_led<=1;
                     working_led<=0;   
				     mpy_state<=CHANGE;
                 end else begin
                     done_led<=0;
                     judge<=1;
                     working_led<=~working_led;
				     mpy_state<=WORKING;
                 end
			end
        end
        
        FULL: begin
            judge<=0;
            full_led<=1;
        end     
        endcase
    end else begin
        warning_led<=0;
        change_led<=1;
        working_led<=0;
        full_led<=0;
        judge<=0;
        input_num<=0;
        mpy_state<=CHANGE;
    end
end

endmodule