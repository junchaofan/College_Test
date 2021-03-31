`timescale 1ns / 1ps

module rom8x4(addr, data);
input [2:0] addr;           // 地址
output [3:0] data;          // 地址addr处存储的数据 
reg [3:0] mem [7: 0];      //  8个4位的存储器

initial   begin             // 初始化存储器
    mem[0] = 4'b0000;
    mem[1] = 4'b0000;
    mem[2] = 4'b0000;
    mem[3] = 4'b0000;
    mem[4] = 4'b0000;
    mem[5] = 4'b0000;
    mem[6] = 4'b0000;
    mem[7] = 4'b0000;	
end     
    assign data = mem[addr];                   // 读取addr单元的值输出                      
endmodule