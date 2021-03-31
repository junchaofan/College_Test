`timescale 1ns / 1ps

module decoder3_8(num, an);
input  [2:0] num;       // 数码管编号：0~7
output reg [7:0] an;       // 7段数码管片�?�信号，低电平有�?
    always @(an [7:0])
                case(num)
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
                     // 功能实现
endmodule

