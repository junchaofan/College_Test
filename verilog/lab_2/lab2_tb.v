module _7Seg_Driver_Direct(sw, seg, dp, an, led);
    input  [15:0] sw;                        //16位拨动开关
    output [6:0] seg;  //7段数码管驱动,低电平有效
    output dp;
    output [7:0] an;                        //7段数码管片选信号,低电平有效
    output [15:0] led;                      //16位led显示,高电平有效

    assign  led[15:0] = sw[15:0];           //将led赋值为相应的开关
    assign  an[0] = ~sw[15] & ~sw[14] & ~sw[13];
	assign  an[1] = ~sw[15] & ~sw[14] & sw[13];
	assign  an[2] = ~sw[15] & sw[14] & ~sw[13];
	assign  an[3] = ~sw[15] & sw[14] & sw[13];
	assign  an[4] = sw[15] & ~sw[14] & ~sw[13];
	assign  an[5] = sw[15] & ~sw[14] & sw[13];				
	assign  an[6] = sw[15] & sw[14] & ~sw[13];
	assign  an[7] = sw[15] & sw[14] & sw[13];
    assign  an[7:0] = ~sw[15:8];            //将sw[15:8]赋值给数码管片选信号AN[7:0]

endmodule
