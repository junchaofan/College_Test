
y
Command: %s
53*	vivadotcl2K
7synth_design -top dynamic_scan -part xc7vx485tffg1157-12default:defaultZ4-113h px
7
Starting synth_design
149*	vivadotclZ4-321h px
?
@Attempting to get a license for feature '%s' and/or device '%s'
308*common2
	Synthesis2default:default2
	xc7vx485t2default:defaultZ17-347h px
?
0Got license for feature '%s' and/or device '%s'
310*common2
	Synthesis2default:default2
	xc7vx485t2default:defaultZ17-349h px
?
%s*synth2?
wStarting RTL Elaboration : Time (s): cpu = 00:00:03 ; elapsed = 00:00:07 . Memory (MB): peak = 263.984 ; gain = 91.137
2default:defaulth px
?
synthesizing module '%s'638*oasys2 
dynamic_scan2default:default2Q
;C:/Users/Administrator/Desktop/verilog/lab_3/dynamic_scan.v2default:default2
32default:default8@Z8-638h px
?
!label required on module instance387*oasys2Q
;C:/Users/Administrator/Desktop/verilog/lab_3/dynamic_scan.v2default:default2
102default:default8@Z8-387h px
?
synthesizing module '%s'638*oasys2
divider2default:default2L
6C:/Users/Administrator/Desktop/verilog/lab_3/divider.v2default:default2
32default:default8@Z8-638h px
[
%s*synth2F
2	Parameter N bound to: 100000000 - type: integer 
2default:defaulth px
?
%done synthesizing module '%s' (%s#%s)256*oasys2
divider2default:default2
12default:default2
12default:default2L
6C:/Users/Administrator/Desktop/verilog/lab_3/divider.v2default:default2
32default:default8@Z8-256h px
?
!label required on module instance387*oasys2Q
;C:/Users/Administrator/Desktop/verilog/lab_3/dynamic_scan.v2default:default2
112default:default8@Z8-387h px
?
synthesizing module '%s'638*oasys2
counter2default:default2L
6C:/Users/Administrator/Desktop/verilog/lab_3/counter.v2default:default2
32default:default8@Z8-638h px
?
%done synthesizing module '%s' (%s#%s)256*oasys2
counter2default:default2
22default:default2
12default:default2L
6C:/Users/Administrator/Desktop/verilog/lab_3/counter.v2default:default2
32default:default8@Z8-256h px
?
!label required on module instance387*oasys2Q
;C:/Users/Administrator/Desktop/verilog/lab_3/dynamic_scan.v2default:default2
122default:default8@Z8-387h px
?
synthesizing module '%s'638*oasys2

decoder3_82default:default2O
9C:/Users/Administrator/Desktop/verilog/lab_3/decoder3_8.v2default:default2
32default:default8@Z8-638h px
?
8referenced signal '%s' should be on the sensitivity list567*oasys2
num2default:default2O
9C:/Users/Administrator/Desktop/verilog/lab_3/decoder3_8.v2default:default2
62default:default8@Z8-567h px
?
%done synthesizing module '%s' (%s#%s)256*oasys2

decoder3_82default:default2
32default:default2
12default:default2O
9C:/Users/Administrator/Desktop/verilog/lab_3/decoder3_8.v2default:default2
32default:default8@Z8-256h px
?
!label required on module instance387*oasys2Q
;C:/Users/Administrator/Desktop/verilog/lab_3/dynamic_scan.v2default:default2
132default:default8@Z8-387h px
?
synthesizing module '%s'638*oasys2
rom8x42default:default2K
5C:/Users/Administrator/Desktop/verilog/lab_3/rom8x4.v2default:default2
32default:default8@Z8-638h px
?
%done synthesizing module '%s' (%s#%s)256*oasys2
rom8x42default:default2
42default:default2
12default:default2K
5C:/Users/Administrator/Desktop/verilog/lab_3/rom8x4.v2default:default2
32default:default8@Z8-256h px
?
!label required on module instance387*oasys2Q
;C:/Users/Administrator/Desktop/verilog/lab_3/dynamic_scan.v2default:default2
142default:default8@Z8-387h px
?
synthesizing module '%s'638*oasys2
pattern2default:default2L
6C:/Users/Administrator/Desktop/verilog/lab_3/pattern.v2default:default2
32default:default8@Z8-638h px
?
8referenced signal '%s' should be on the sensitivity list567*oasys2
sw2default:default2L
6C:/Users/Administrator/Desktop/verilog/lab_3/pattern.v2default:default2
62default:default8@Z8-567h px
?
%done synthesizing module '%s' (%s#%s)256*oasys2
pattern2default:default2
52default:default2
12default:default2L
6C:/Users/Administrator/Desktop/verilog/lab_3/pattern.v2default:default2
32default:default8@Z8-256h px
?
%done synthesizing module '%s' (%s#%s)256*oasys2 
dynamic_scan2default:default2
62default:default2
12default:default2Q
;C:/Users/Administrator/Desktop/verilog/lab_3/dynamic_scan.v2default:default2
32default:default8@Z8-256h px
?
%s*synth2?
xFinished RTL Elaboration : Time (s): cpu = 00:00:04 ; elapsed = 00:00:07 . Memory (MB): peak = 299.141 ; gain = 126.293
2default:defaulth px
A
%s*synth2,

Report Check Netlist: 
2default:defaulth px
r
%s*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth px
r
%s*synth2]
I|      |Item              |Errors |Warnings |Status |Description       |
2default:defaulth px
r
%s*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth px
r
%s*synth2]
I|1     |multi_driven_nets |      0|        0|Passed |Multi driven nets |
2default:defaulth px
r
%s*synth2]
I+------+------------------+-------+---------+-------+------------------+
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
?
%s*synth2?
?Finished RTL Optimization Phase 1 : Time (s): cpu = 00:00:04 ; elapsed = 00:00:07 . Memory (MB): peak = 299.141 ; gain = 126.293
2default:defaulth px
{
%s*synth2f
R---------------------------------------------------------------------------------
2default:defaulth px
V
Loading part %s157*device2&
xc7vx485tffg1157-12default:defaultZ21-403h px
H
)Preparing netlist for logic optimization
349*projectZ1-570h px
;

Processing XDC Constraints
244*projectZ1-262h px
:
Initializing timing engine
348*projectZ1-569h px
?
Parsing XDC File [%s]
179*designutils2P
<C:/Users/Administrator/Desktop/verilog/lab_3/lab3_nexys4.xdc2default:defaultZ20-179h px