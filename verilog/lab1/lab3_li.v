module divider #(parameter N = 1000)
(clk, clk_N);
input clk;                      // 系统时钟
output reg clk_N;                   // 分频后的时钟
//parameter N = 100_000_000;      // 1Hz的时钟,N=fclk/fclk_N
reg [31:0] counter;             /* 计数器变量，通过计数实现分频。
                                   当计数器从0计数到(N/2-1)时，
                                   输出时钟翻转，计数器清零 */
always @(posedge clk)  begin    // 时钟上升沿
                              // 功能实现
    if(counter>=N/2)
    begin
    	clk_N<=~clk_N;
    	counter<=0;
    end
    else
    	counter<=counter+1;
end                           
endmodule

module counter(clk, out);
input clk;                    // 计数时钟
output reg [2:0] out;             // 计数值

always @(posedge clk)  begin  // 在时钟上升沿计数器加1
                           // 功能实现
    out = out + 1;
end                           
endmodule

module rom8x4(addr, data);
input [2:0] addr;           // 地址
output reg [3:0] data;          // 地址addr处存储的数据 

reg [3: 0] mem [7: 0];      //  8个4位的存储器

initial   begin             // 初始化存储器
	mem[0]=4'b0000;
    mem[1]=4'b0010;
	mem[2]=4'b0100;
	mem[3]=4'b0110;
	mem[4]=4'b1000;
	mem[5]=4'b1010;
	mem[6]=4'b1100;
	mem[7]=4'b1110;        
end     
                    // 读取addr单元的值输出
                    
	always @(addr[2:0])
	begin
		case(addr[2:0])
			3'b000: data=mem[0];
			3'b001: data=mem[1];
			3'b010: data=mem[2];
			3'b011: data=mem[3];
			3'b100: data=mem[4];
			3'b101: data=mem[5];
			3'b110: data=mem[6];
			3'b111: data=mem[7];
		endcase
    end	     
endmodule

module _7Seg_Driver_Choice(SW,AN);
    input [2:0] SW;       // 16浣嶆嫧鍔ㄥ紑鍏?
    output reg [7:0] AN;       // 7娈垫暟鐮佺鐗囬?変俊鍙凤紝浣庣數骞虫湁鏁?
    always @(SW[2:0])
    begin
        case(SW[2:0])
            3'b000: AN[7:0] = 8'b00000001;
            3'b001: AN[7:0] = 8'b00000010;
            3'b010: AN[7:0] = 8'b00000100;
            3'b011: AN[7:0] = 8'b00001000;
            3'b100: AN[7:0] = 8'b00010000;
            3'b101: AN[7:0] = 8'b00100000;
            3'b110: AN[7:0] = 8'b01000000;
            3'b111: AN[7:0] = 8'b10000000;
        endcase
        AN = ~AN;
    end
endmodule

module _7Seg_Driver_Decode(SW, SEG);
    input [3:0] SW;       // 16浣嶆嫧鍔ㄥ紑鍏?
	output reg [7:0] SEG;      // 7娈垫暟鐮佺椹卞姩锛屼綆鐢靛钩鏈夋晥
    
    always @(SW[3:0])
    begin
        case(SW[3:0])
            4'b0000: SEG[7:0] = 8'b11000000;
            4'b0001: SEG[7:0] = 8'b11111001;
            4'b0010: SEG[7:0] = 8'b10100100;
            4'b0011: SEG[7:0] = 8'b10110000;
            4'b0100: SEG[7:0] = 8'b10011001;
            4'b0101: SEG[7:0] = 8'b10010010;
            4'b0110: SEG[7:0] = 8'b10000010;
            4'b0111: SEG[7:0] = 8'b11111000;
            4'b1000: SEG[7:0] = 8'b10000000;
            4'b1001: SEG[7:0] = 8'b10011000;
            4'b1010: SEG[7:0] = 8'b10001000;
            4'b1011: SEG[7:0] = 8'b10000011;
            4'b1100: SEG[7:0] = 8'b11000110;
            4'b1101: SEG[7:0] = 8'b10100001;
            4'b1110: SEG[7:0] = 8'b10000110;
            4'b1111: SEG[7:0] = 8'b10001110;
        endcase
    end
endmodule

module dynamic_scan(clk,  SEG, AN);
input clk;              // 系统时钟
output [7:0] SEG;  		// 分别对应CA、CB、CC、CD、CE、CF、CG和DP
output [7:0] AN;        // 8位数码管片选信号

                     // 功能实现
wire clk_N;
wire [2:0]num;
wire [3:0]code;
divider#(100_000_00)(.clk(clk),.clk_N(clk_N));
counter(.clk(clk_N),.out(num[2:0]));
_7Seg_Driver_Choice(.SW(num[2:0]),.AN(AN[7:0]));
rom8x4(.addr(num[2:0]), .data(code[3:0]));
_7Seg_Driver_Decode(.SW(code[3:0]),.SEG(SEG[7:0]));
endmodule

