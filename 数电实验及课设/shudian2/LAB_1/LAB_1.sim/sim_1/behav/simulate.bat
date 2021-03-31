@echo off
set xv_path=C:\\Xilinx\\Vivado\\2015.2\\bin
call %xv_path%/xsim lab1_b_tb_behav -key {Behavioral:sim_1:Functional:lab1_b_tb} -tclbatch lab1_b_tb.tcl -view E:/shudian2/LAB_1/lab1_b_tb_behav.wcfg -log simulate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
