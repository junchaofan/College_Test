`timescale 1ns / 1ps

module show(clk,full_led,now_num,sum_num,an,seg);
input clk,full_led;
input [5:0] now_num;
input [9:0] sum_num;
output reg [7:0] an, seg;
reg [3:0] part [5:0];     
reg [2:0] count;
reg [3:0] sw;
initial begin
	an<=0;
	seg<=0;
	count<=0;
end
	
always @(posedge clk, posedge full_led) begin
    	part[0] <= now_num%10;
    	part[1] <= now_num/10;
        part[3] <= sum_num%10;
    	part[4] <= (sum_num/10)%10;
        part[5] <= sum_num/100;    
    	count <= count+1;
		if(~full_led) begin
    	case(count)
    	3 'b001: begin
    		an[7:0]=8'b11111101;
    		sw <= part[0];
    		end
        3 'b010: begin
            an[7:0]=8'b11111011;
    		sw <= part[1];
    		end
        3 'b100: begin
    		sw <= part[3];
            an[7:0]=8'b11101111; 
    		end
        3 'b101: begin
    		sw <= part[4];
            an[7:0]=8'b11011111; 
    		end
        3 'b110: begin
    		sw <= part[5];
            an[7:0]=8'b10111111;
    		end
        endcase
    	case(sw) 
    	4'b0000:
    	    seg[7:0] = 8'b11000000;
    	4'b0001:
    	    seg[7:0] = 8'b11111001;
        4'b0010:    
            seg[7:0] = 8'b10100100;    
        4'b0011:    
            seg[7:0] = 8'b10110000;    
        4'b0100:    
            seg[7:0] = 8'b10011001;    
        4'b0101:    
            seg[7:0] = 8'b10010010;    
        4'b0110:    
            seg[7:0] = 8'b10000010;    
        4'b0111:    
            seg[7:0] = 8'b11111000;    
        4'b1000:    
            seg[7:0] = 8'b10000000;    
        4'b1001:    
            seg[7:0] = 8'b10011000; 
        endcase 
    end
	else begin
    case(count)
    3'b000:
       an[7:0]=8'b01111111;
    3'b001:
       an[7:0]=8'b10111111;
    3'b010:
       an[7:0]=8'b11011111;                 
    3'b011:
       an[7:0]=8'b11101111;           
    3'b100:
       an[7:0]=8'b11110111;      
    3'b101:
       an[7:0]=8'b11111011;          
    3'b110:
       an[7:0]=8'b11111101;           
    3'b111:
        an[7:0]=8'b11111110;  
    endcase
    case(count) 
    3'b000:
        seg[7:0] = 8'b10001110;
    3'b001:
        seg[7:0] = 8'b11000001;
    3'b010:    
        seg[7:0] = 8'b11111001;    
    3'b011:    
        seg[7:0] = 8'b11111001;    
    3'b100:    
        seg[7:0] = 8'b10001110;    
    3'b101:    
        seg[7:0] = 8'b11000001;    
    3'b110:    
        seg[7:0] = 8'b11111001;    
    3'b111:    
        seg[7:0] = 8'b11111001;      
    default:    
    	seg[7:0] = 8'b11000000;    
    endcase
    end 
end
        
endmodule