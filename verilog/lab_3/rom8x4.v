`timescale 1ns / 1ps

module rom8x4(addr, data);
input [2:0] addr;           // ��ַ
output [3:0] data;          // ��ַaddr���洢������ 
reg [3:0] mem [7: 0];      //  8��4λ�Ĵ洢��

initial   begin             // ��ʼ���洢��
    mem[0] = 4'b0000;
    mem[1] = 4'b0000;
    mem[2] = 4'b0000;
    mem[3] = 4'b0000;
    mem[4] = 4'b0000;
    mem[5] = 4'b0000;
    mem[6] = 4'b0000;
    mem[7] = 4'b0000;	
end     
    assign data = mem[addr];                   // ��ȡaddr��Ԫ��ֵ���                      
endmodule