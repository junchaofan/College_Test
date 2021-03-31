`timescale 1ns / 1ps
//////////////////////////////////
// 模块功能：译码驱动7段数码管
//////////////////////////////////
module lab2_3(sw, seg, dp, an, led);
    input   [15:0] sw;                  //16位拨动开关
    output  [6:0] seg;             //7段数码管驱动,低电平有效
    output  [7:0] an;                  //7段数码管片选信号,低电平有效
    output  [15:0] led;                //16位led显示
    output  dp;
    main(sw, seg, dp, an, led);
endmodule    

module main(sw, seg, dp, an, led);
    input   [15:0] sw;                  //16位拨动开关
    output  reg [6:0] seg;             //7段数码管驱动,低电平有效
    output  reg [7:0] an;                  //7段数码管片选信号,低电平有效
    output  [15:0] led;                //16位led显示
    output  wire dp;
    wire [3:0] num;
    wire [2:0] tab;
    assign  led[15:0] = sw[15:0];
    assign  num[3:0] = sw[3:0];
    assign  tab[2:0] = sw[15:13];
    assign dp = 1'b1;
    always @(seg [6:0])
        case(num)
        4 'b0000:
            seg [6:0] = 7'b1000000;
        4 'b0001:
            seg [6:0] = 7'b1111001;
        4 'b0010:
            seg [6:0] = 7'b0100100;
        4 'b0011:
            seg [6:0] = 7'b0110000;
        4 'b0100:
            seg [6:0] = 7'b0011001;
        4 'b0101:
            seg [6:0] = 7'b0010010;
        4 'b0110:
            seg [6:0] = 7'b0000010;
        4 'b0111:
            seg [6:0] = 7'b1111000;
        4 'b1000:
            seg [6:0] = 7'b0000000;
        4 'b1001:
            seg [6:0] = 7'b0011000;
        4 'b1010:
            seg [6:0] = 7'b0001000;
        4 'b1011:
            seg [6:0] = 7'b0000011;
        4 'b1100:
            seg [6:0] = 7'b1000110;
        4 'b1101:
            seg [6:0] = 7'b0100001;
        4 'b1110:
            seg [6:0] = 7'b0000110;
        4 'b1111:
            seg [6:0] = 7'b0001110;
        endcase
            always @(an [7:0])
                case(tab)
                3 'b000:
                    an[7:0]=8'b11111110;
                3 'b001:
                    an[7:0]=8'b11111101;
                3 'b010:
                    an[7:0]=8'b11111011;                 
                3 'b011:
                    an[7:0]=8'b11110111;           
                3 'b100:
                    an[7:0]=8'b11101111;      
                3 'b101:
                    an[7:0]=8'b11011111;          
                3 'b110:
                    an[7:0]=8'b10111111;           
                3 'b111:
                    an[7:0]=8'b01111111;    
                endcase
endmodule

