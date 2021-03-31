// Copyright 1986-2015 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2015.2 (win64) Build 1266856 Fri Jun 26 16:35:25 MDT 2015
// Date        : Thu Jun 14 20:16:28 2018
// Host        : 803-063 running 64-bit Service Pack 1  (build 7601)
// Command     : write_verilog -mode timesim -nolib -sdf_anno true -force -file
//               C:/Users/Administrator/Desktop/shudian2/LAB_3/LAB_3.sim/sim_1/synth/timing/lab3_tb_time_synth.v
// Design      : lab3
// Purpose     : This verilog netlist is a timing simulation representation of the design and should not be modified or
//               synthesized. Please ensure that this netlist is used with the corresponding SDF file.
// Device      : xc7a100tcsg324-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps
`define XIL_TIMING

(* NotValidForBitStream *)
module lab3
   (clk,
    sig_nsyn,
    q1,
    q2,
    sig_syn,
    out);
  input clk;
  input sig_nsyn;
  output q1;
  output q2;
  output sig_syn;
  output out;

  wire clk;
  wire clk_IBUF;
  wire clk_IBUF_BUFG;
  wire out;
  wire out_OBUF;
  wire q1;
  wire q1_OBUF;
  wire q2;
  wire q2_OBUF;
  wire sig_nsyn;
  wire sig_syn;
  wire sig_syn_OBUF;

initial begin
 $sdf_annotate("lab3_tb_time_synth.sdf",,,,"tool_control");
end
  BUFG clk_IBUF_BUFG_inst
       (.I(clk_IBUF),
        .O(clk_IBUF_BUFG));
  IBUF clk_IBUF_inst
       (.I(clk),
        .O(clk_IBUF));
  OBUF out_OBUF_inst
       (.I(out_OBUF),
        .O(out));
  OBUF q1_OBUF_inst
       (.I(q1_OBUF),
        .O(q1));
  OBUF q2_OBUF_inst
       (.I(q2_OBUF),
        .O(q2));
  IBUF sig_nsyn_IBUF_inst
       (.I(sig_nsyn),
        .O(out_OBUF));
  OBUF sig_syn_OBUF_inst
       (.I(sig_syn_OBUF),
        .O(sig_syn));
  pipe3b testb
       (.clk(clk_IBUF_BUFG),
        .q1(q1_OBUF),
        .q2(q2_OBUF),
        .sig_nsyn(out_OBUF),
        .sig_syn(sig_syn_OBUF));
endmodule

module pipe3b
   (q1,
    q2,
    sig_syn,
    sig_nsyn,
    clk);
  output q1;
  output q2;
  output sig_syn;
  input sig_nsyn;
  input clk;

  wire clk;
  wire q1;
  wire q2;
  wire sig_nsyn;
  wire sig_syn;

  FDRE #(
    .INIT(1'b0)) 
    q1_reg
       (.C(clk),
        .CE(1'b1),
        .D(sig_nsyn),
        .Q(q1),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    q2_reg
       (.C(clk),
        .CE(1'b1),
        .D(q1),
        .Q(q2),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    sig_syn_reg
       (.C(clk),
        .CE(1'b1),
        .D(q2),
        .Q(sig_syn),
        .R(1'b0));
endmodule
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (weak1, weak0) GSR = GSR_int;
    assign (weak1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule
`endif
