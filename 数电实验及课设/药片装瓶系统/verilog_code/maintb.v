`timescale 1ns / 1ps

module maintb();
reg [8:0]i;
reg x,cont_set,update_set;
reg [5:0] max_num;       
main main_test(.clk(x), .cont_set(cont_set),.update_set(update_set),.max_num( max_num));

initial begin
    max_num<=6'b000011;
    x<=0;
           
    update_set<=0;
    cont_set<=1;
    #10
    update_set<=1;
    for (i=0;i<1000;i=i+1) begin
            #2 x<=~x;
            if (i==20) begin
                update_set<=0;
                max_num<=6'b000100;
            end
            if (i==50)
                update_set<=1;
            if (i==60)
                update_set<=0;
    end 
end
endmodule
//`timescale 1ns / 1ps
//module maintb();
//reg [8:0]i;
//reg x,cont_set,update_set;
//reg [5:0] max_num;       
//main main_test(.clk(x), .cont_set(cont_set),.update_set(update_set),.max_num( max_num));

//initial begin
//    max_num<=6'b000011;
//    x<=0;
//    update_set<=0;
//    cont_set<=1;
//    #10
//    update_set<=1;
//    for (i=0;i<1000;i=i+1) begin
//            #2 x<=~x;
//    end
//end
//endmodule
