
z
eCannot write hardware definition file as there are no IPI block design hardware handoff files present*	vivadotclh px
N
Command: %s
53*	vivadotcl2 
place_design2default:defaultZ4-113h px
?
@Attempting to get a license for feature '%s' and/or device '%s'
308*common2"
Implementation2default:default2
	xc7vx485t2default:defaultZ17-347h px
?
0Got license for feature '%s' and/or device '%s'
310*common2"
Implementation2default:default2
	xc7vx485t2default:defaultZ17-349h px
M
Running DRC with %s threads
24*drc2
22default:defaultZ23-27h px
S
DRC finished with %s
79*	vivadotcl2
0 Errors2default:defaultZ4-198h px
b
BPlease refer to the DRC report (report_drc) for more information.
80*	vivadotclZ4-199h px
m
,Running DRC as a precondition to command %s
22*	vivadotcl2 
place_design2default:defaultZ4-22h px
M
Running DRC with %s threads
24*drc2
22default:defaultZ23-27h px
S
DRC finished with %s
79*	vivadotcl2
0 Errors2default:defaultZ4-198h px
b
BPlease refer to the DRC report (report_drc) for more information.
80*	vivadotclZ4-199h px
R

Starting %s Task
103*constraints2
Placer2default:defaultZ18-103h px
z
BMultithreading enabled for place_design using a maximum of %s CPUs12*	placeflow2
22default:defaultZ30-611h px
v

Phase %s%s
101*constraints2
1 2default:default2,
Placer Runtime Estimator2default:defaultZ18-101h px
I
7Phase 1 Placer Runtime Estimator | Checksum: 14343499c
*commonh px
?

%s
*constraints2s
_Time (s): cpu = 00:00:00 ; elapsed = 00:00:00.094 . Memory (MB): peak = 1250.570 ; gain = 0.0002default:defaulth px
s

Phase %s%s
101*constraints2
2 2default:default2)
Placer Initialization2default:defaultZ18-101h px
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2
00:00:002default:default2
1250.5702default:default2
0.0002default:defaultZ17-268h px
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2
00:00:002default:default2
1250.5702default:default2
0.0002default:defaultZ17-268h px
?

Phase %s%s
101*constraints2
2.1 2default:default2F
2IO Placement/ Clock Placement/ Build Placer Device2default:defaultZ18-101h px
q

Phase %s%s
101*constraints2
2.1.1 2default:default2#
Pre-Place Cells2default:defaultZ18-101h px
C
1Phase 2.1.1 Pre-Place Cells | Checksum: ed285c1f
*commonh px
?

%s
*constraints2s
_Time (s): cpu = 00:00:00 ; elapsed = 00:00:00.172 . Memory (MB): peak = 1250.570 ; gain = 0.0002default:defaulth px
?
?This design has IO with an IOSTANDARD of %s but the target device has no %s banks that support this IO standard. Please review the 7 series FPGAs Packaging and Pinout guide for devices/packages that have %s banks or change the IO standard for the following IO: 
%s399*place2
LVCMOS332default:default2#
High Range (HR)2default:default2#
High Range (HR)2default:default2?
p	an[0]
	an[1]
	an[2]
	an[3]
	an[4]
	an[5]
	an[6]
	an[7]
	seg[0]
	seg[1]
	seg[2]
	seg[3]
	seg[4]
	seg[5]
	seg[6]
2default:defaultZ30-399h px
?
bAn IO Bus %s with more than one IO standard is found. Components associated with this bus are: %s
12*place2
seg2default:default2?
?
	<MSGMETA::BEGIN::BLOCK>seg[7]<MSGMETA::END> of IOStandard LVCMOS18
	<MSGMETA::BEGIN::BLOCK>seg[6]<MSGMETA::END> of IOStandard LVCMOS33
	<MSGMETA::BEGIN::BLOCK>seg[5]<MSGMETA::END> of IOStandard LVCMOS33
	<MSGMETA::BEGIN::BLOCK>seg[4]<MSGMETA::END> of IOStandard LVCMOS33
	<MSGMETA::BEGIN::BLOCK>seg[3]<MSGMETA::END> of IOStandard LVCMOS33
	<MSGMETA::BEGIN::BLOCK>seg[2]<MSGMETA::END> of IOStandard LVCMOS33
	<MSGMETA::BEGIN::BLOCK>seg[1]<MSGMETA::END> of IOStandard LVCMOS33
	<MSGMETA::BEGIN::BLOCK>seg[0]<MSGMETA::END> of IOStandard LVCMOS33")
seg[7]2
	: of IOStandard LVCMOS18
	"%
seg[6]: of IOStandard LVCMOS33
	"%
seg[5]: of IOStandard LVCMOS33
	"%
seg[4]: of IOStandard LVCMOS33
	"%
seg[3]: of IOStandard LVCMOS33
	"%
seg[2]: of IOStandard LVCMOS33
	"%
seg[1]: of IOStandard LVCMOS33
	"#
seg[0]: of IOStandard LVCMOS332default:default8Z30-12h px
e
SPhase 2.1 IO Placement/ Clock Placement/ Build Placer Device | Checksum: 1863dc044
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 1250.570 ; gain = 0.0002default:defaulth px
F
4Phase 2 Placer Initialization | Checksum: 1863dc044
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 1250.570 ; gain = 0.0002default:defaulth px
?
?Placer failed with error: '%s'
Please review all ERROR and WARNING messages during placement to understand the cause for failure.
1*	placeflow2?
?Implementation Feasibility check failed, Please see the previously displayed individual error or warning messages for more details.2default:defaultZ30-99h px
;
)Ending Placer Task | Checksum: 1863dc044
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 1250.570 ; gain = 0.0002default:defaulth px
W
Releasing license: %s
83*common2"
Implementation2default:defaultZ17-83h px
?
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
322default:default2
672default:default2
822default:default2
32default:defaultZ4-41h px
K

%s failed
30*	vivadotcl2 
place_design2default:defaultZ4-43h px
j
Command failed: %s
69*common28
$Placer could not place all instances2default:defaultZ17-69h px
}
Exiting %s at %s...
206*common2
Vivado2default:default2,
Thu May 24 11:32:47 20182default:defaultZ17-206h px