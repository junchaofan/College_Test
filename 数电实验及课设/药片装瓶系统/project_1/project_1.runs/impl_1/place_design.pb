
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
xc7a100t2default:defaultZ17-347h px
?
0Got license for feature '%s' and/or device '%s'
310*common2"
Implementation2default:default2
xc7a100t2default:defaultZ17-349h px
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
H
6Phase 1 Placer Runtime Estimator | Checksum: d68c7409
*commonh px
?

%s
*constraints2r
^Time (s): cpu = 00:00:00 ; elapsed = 00:00:00.031 . Memory (MB): peak = 970.660 ; gain = 0.0002default:defaulth px
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
00:00:002default:default2
970.6602default:default2
0.0002default:defaultZ17-268h px
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2
00:00:002default:default2
970.6602default:default2
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
1Phase 2.1.1 Pre-Place Cells | Checksum: 56c1b0a1
*commonh px
?

%s
*constraints2r
^Time (s): cpu = 00:00:00 ; elapsed = 00:00:00.062 . Memory (MB): peak = 970.660 ; gain = 0.0002default:defaulth px
B
%Done setting XDC timing constraints.
35*timingZ38-35h px
s

Phase %s%s
101*constraints2
2.1.2 2default:default2%
IO & Clk Clean Up2default:defaultZ18-101h px
?
9Poor placement for routing between an IO pin and BUFG. %s528*place2?
?This is normally an ERROR but the CLOCK_DEDICATED_ROUTE constraint is set to FALSE allowing your design to continue. The use of this override is highly discouraged as it may lead to very poor timing results. It is recommended that this error condition be corrected in the design.

	<MSGMETA::BEGIN::BLOCK>update_set_IBUF_inst<MSGMETA::END> (IBUF.O) is locked to IOB_X0Y79
	<MSGMETA::BEGIN::BLOCK>update_set_IBUF_BUFG_inst<MSGMETA::END> (BUFG.I) is provisionally placed by clockplacer on BUFGCTRL_X0Y2
"?
update_set_IBUF_inst2?This is normally an ERROR but the CLOCK_DEDICATED_ROUTE constraint is set to FALSE allowing your design to continue. The use of this override is highly discouraged as it may lead to very poor timing results. It is recommended that this error condition be corrected in the design.

	:" (IBUF.O) is locked to IOB_X0Y79
	"a
update_set_IBUF_BUFG_inst:B (BUFG.I) is provisionally placed by clockplacer on BUFGCTRL_X0Y2
2default:default8Z30-574h px
E
3Phase 2.1.2 IO & Clk Clean Up | Checksum: 56c1b0a1
*commonh px
?

%s
*constraints2s
_Time (s): cpu = 00:00:01 ; elapsed = 00:00:00.873 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
?

Phase %s%s
101*constraints2
2.1.3 2default:default2>
*Implementation Feasibility check On IDelay2default:defaultZ18-101h px
^
LPhase 2.1.3 Implementation Feasibility check On IDelay | Checksum: 56c1b0a1
*commonh px
?

%s
*constraints2s
_Time (s): cpu = 00:00:01 ; elapsed = 00:00:00.873 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
u

Phase %s%s
101*constraints2
2.1.4 2default:default2'
Commit IO Placement2default:defaultZ18-101h px
G
5Phase 2.1.4 Commit IO Placement | Checksum: d7488ad7
*commonh px
?

%s
*constraints2s
_Time (s): cpu = 00:00:01 ; elapsed = 00:00:00.889 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
d
RPhase 2.1 IO Placement/ Clock Placement/ Build Placer Device | Checksum: f73a81d8
*commonh px
?

%s
*constraints2s
_Time (s): cpu = 00:00:01 ; elapsed = 00:00:00.889 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
z

Phase %s%s
101*constraints2
2.2 2default:default2.
Build Placer Netlist Model2default:defaultZ18-101h px
s

Phase %s%s
101*constraints2
2.2.1 2default:default2%
Place Init Design2default:defaultZ18-101h px
{

Phase %s%s
101*constraints2
2.2.1.1 2default:default2+
Init Lut Pin Assignment2default:defaultZ18-101h px
N
<Phase 2.2.1.1 Init Lut Pin Assignment | Checksum: 1ddc5d000
*commonh px
?

%s
*constraints2s
_Time (s): cpu = 00:00:01 ; elapsed = 00:00:00.951 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
F
4Phase 2.2.1 Place Init Design | Checksum: 12a2f9791
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:01 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
M
;Phase 2.2 Build Placer Netlist Model | Checksum: 12a2f9791
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:01 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
w

Phase %s%s
101*constraints2
2.3 2default:default2+
Constrain Clocks/Macros2default:defaultZ18-101h px
?

Phase %s%s
101*constraints2
2.3.1 2default:default24
 Constrain Global/Regional Clocks2default:defaultZ18-101h px
U
CPhase 2.3.1 Constrain Global/Regional Clocks | Checksum: 12a2f9791
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:01 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
J
8Phase 2.3 Constrain Clocks/Macros | Checksum: 12a2f9791
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:01 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
F
4Phase 2 Placer Initialization | Checksum: 12a2f9791
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:01 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
n

Phase %s%s
101*constraints2
3 2default:default2$
Global Placement2default:defaultZ18-101h px
A
/Phase 3 Global Placement | Checksum: 10880c1b0
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:01 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
n

Phase %s%s
101*constraints2
4 2default:default2$
Detail Placement2default:defaultZ18-101h px
z

Phase %s%s
101*constraints2
4.1 2default:default2.
Commit Multi Column Macros2default:defaultZ18-101h px
M
;Phase 4.1 Commit Multi Column Macros | Checksum: 10880c1b0
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:01 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
|

Phase %s%s
101*constraints2
4.2 2default:default20
Commit Most Macros & LUTRAMs2default:defaultZ18-101h px
O
=Phase 4.2 Commit Most Macros & LUTRAMs | Checksum: 1df409ddc
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:01 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
v

Phase %s%s
101*constraints2
4.3 2default:default2*
Area Swap Optimization2default:defaultZ18-101h px
I
7Phase 4.3 Area Swap Optimization | Checksum: 1289486f1
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:01 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
u

Phase %s%s
101*constraints2
4.4 2default:default2)
updateClock Trees: DP2default:defaultZ18-101h px
H
6Phase 4.4 updateClock Trees: DP | Checksum: 1289486f1
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:01 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
u

Phase %s%s
101*constraints2
4.5 2default:default2)
Timing Path Optimizer2default:defaultZ18-101h px
H
6Phase 4.5 Timing Path Optimizer | Checksum: 1e9d67920
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:01 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
|

Phase %s%s
101*constraints2
4.6 2default:default20
Small Shape Detail Placement2default:defaultZ18-101h px
?

Phase %s%s
101*constraints2
4.6.1 2default:default24
 Commit Small Macros & Core Logic2default:defaultZ18-101h px
n

Phase %s%s
101*constraints2
4.6.1.1 2default:default2

setBudgets2default:defaultZ18-101h px
A
/Phase 4.6.1.1 setBudgets | Checksum: 11767632b
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:01 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
y

Phase %s%s
101*constraints2
4.6.1.2 2default:default2)
Commit Slice Clusters2default:defaultZ18-101h px
K
9Phase 4.6.1.2 Commit Slice Clusters | Checksum: e9421835
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
T
BPhase 4.6.1 Commit Small Macros & Core Logic | Checksum: e9421835
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
?

Phase %s%s
101*constraints2
4.6.2 2default:default2C
/Clock Restriction Legalization for Leaf Columns2default:defaultZ18-101h px
c
QPhase 4.6.2 Clock Restriction Legalization for Leaf Columns | Checksum: e9421835
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
?

Phase %s%s
101*constraints2
4.6.3 2default:default2E
1Clock Restriction Legalization for Non-Clock Pins2default:defaultZ18-101h px
e
SPhase 4.6.3 Clock Restriction Legalization for Non-Clock Pins | Checksum: e9421835
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
N
<Phase 4.6 Small Shape Detail Placement | Checksum: e9421835
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
r

Phase %s%s
101*constraints2
4.7 2default:default2&
Re-assign LUT pins2default:defaultZ18-101h px
D
2Phase 4.7 Re-assign LUT pins | Checksum: e9421835
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
@
.Phase 4 Detail Placement | Checksum: e9421835
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
?

Phase %s%s
101*constraints2
5 2default:default2<
(Post Placement Optimization and Clean-Up2default:defaultZ18-101h px
s

Phase %s%s
101*constraints2
5.1 2default:default2'
PCOPT Shape updates2default:defaultZ18-101h px
F
4Phase 5.1 PCOPT Shape updates | Checksum: 1bfc975bf
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
v

Phase %s%s
101*constraints2
6 2default:default2,
Post Commit Optimization2default:defaultZ18-101h px
x

Phase %s%s
101*constraints2
6.1 2default:default2,
updateClock Trees: PCOPT2default:defaultZ18-101h px
K
9Phase 6.1 updateClock Trees: PCOPT | Checksum: 1bfc975bf
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
{

Phase %s%s
101*constraints2
6.2 2default:default2/
Post Placement Optimization2default:defaultZ18-101h px
?

Phase %s%s
101*constraints2
6.2.1 2default:default26
"Post Placement Timing Optimization2default:defaultZ18-101h px
?
hPost Placement Timing Summary WNS=%s. For the most accurate timing information please run report_timing.610*place2
5.4552default:defaultZ30-746h px
W
EPhase 6.2.1 Post Placement Timing Optimization | Checksum: 16821dcd3
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:03 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
N
<Phase 6.2 Post Placement Optimization | Checksum: 16821dcd3
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:03 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
I
7Phase 6 Post Commit Optimization | Checksum: 16821dcd3
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:03 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
?

Phase %s%s
101*constraints2
5.2 2default:default25
!Sweep Clock Roots: Post-Placement2default:defaultZ18-101h px
T
BPhase 5.2 Sweep Clock Roots: Post-Placement | Checksum: 16821dcd3
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:03 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
v

Phase %s%s
101*constraints2
5.3 2default:default2*
Post Placement Cleanup2default:defaultZ18-101h px
I
7Phase 5.3 Post Placement Cleanup | Checksum: 16821dcd3
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:03 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
p

Phase %s%s
101*constraints2
5.4 2default:default2$
Placer Reporting2default:defaultZ18-101h px
m

Phase %s%s
101*constraints2
5.4.1 2default:default2
Restore STA2default:defaultZ18-101h px
@
.Phase 5.4.1 Restore STA | Checksum: 16821dcd3
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:03 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
C
1Phase 5.4 Placer Reporting | Checksum: 16821dcd3
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:03 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
w

Phase %s%s
101*constraints2
5.5 2default:default2+
Final Placement Cleanup2default:defaultZ18-101h px
I
7Phase 5.5 Final Placement Cleanup | Checksum: bd1954f3
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:03 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
X
FPhase 5 Post Placement Optimization and Clean-Up | Checksum: bd1954f3
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:03 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
:
(Ending Placer Task | Checksum: 4c55a21c
*commonh px
?

%s
*constraints2o
[Time (s): cpu = 00:00:03 ; elapsed = 00:00:02 . Memory (MB): peak = 993.219 ; gain = 22.5592default:defaulth px
W
Releasing license: %s
83*common2"
Implementation2default:defaultZ17-83h px
?
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
342default:default2
12default:default2
02default:default2
02default:defaultZ4-41h px
[
%s completed successfully
29*	vivadotcl2 
place_design2default:defaultZ4-42h px
A
Writing placer database...
1603*designutilsZ20-1893h px
:
Writing XDEF routing.
211*designutilsZ20-211h px
G
#Writing XDEF routing logical nets.
209*designutilsZ20-209h px
G
#Writing XDEF routing special nets.
210*designutilsZ20-210h px
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2)
Write XDEF Complete: 2default:default2
00:00:002default:default2 
00:00:00.0622default:default2
993.2192default:default2
0.0002default:defaultZ17-268h px
|
jreport_io: Time (s): cpu = 00:00:00 ; elapsed = 00:00:00.031 . Memory (MB): peak = 993.219 ; gain = 0.000
*commonh px
?
sreport_utilization: Time (s): cpu = 00:00:00 ; elapsed = 00:00:00.047 . Memory (MB): peak = 993.219 ; gain = 0.000
*commonh px
?
treport_control_sets: Time (s): cpu = 00:00:00 ; elapsed = 00:00:00.016 . Memory (MB): peak = 993.219 ; gain = 0.000
*commonh px


End Record