# 
# Synthesis run script generated by Vivado
# 

namespace eval rt {
    variable rc
}
set rt::rc [catch {
  uplevel #0 {
    set ::env(BUILTIN_SYNTH) true
    source $::env(HRT_TCL_PATH)/rtSynthPrep.tcl
    rt::HARTNDb_resetJobStats
    rt::HARTNDb_startJobStats
    set rt::cmdEcho 0
    rt::set_parameter writeXmsg true
    set ::env(RT_TMP) "./.Xil/Vivado-5128-803-016/realtime/tmp"
    if { [ info exists ::env(RT_TMP) ] } {
      file delete -force $::env(RT_TMP)
      file mkdir $::env(RT_TMP)
    }

    rt::delete_design

    set rt::partid xc7vx485tffg1157-1

    set rt::multiChipSynthesisFlow false
    source $::env(SYNTH_COMMON)/common.tcl
    set rt::defaultWorkLibName xil_defaultlib

    set rt::useElabCache false
    if {$rt::useElabCache == false} {
      rt::read_verilog {
      C:/Users/Administrator/Desktop/verilog/lab_3/rom8x4.v
      C:/Users/Administrator/Desktop/verilog/lab_3/decoder3_8.v
      C:/Users/Administrator/Desktop/verilog/lab_3/pattern.v
      C:/Users/Administrator/Desktop/verilog/lab_3/divider.v
      C:/Users/Administrator/Desktop/verilog/lab_3/counter.v
      C:/Users/Administrator/Desktop/verilog/lab_3/dynamic_scan.v
    }
      rt::filesetChecksum
    }
    rt::set_parameter usePostFindUniquification false
    set rt::top dynamic_scan
    set rt::reportTiming false
    rt::set_parameter elaborateOnly true
    rt::set_parameter elaborateRtl true
    rt::set_parameter eliminateRedundantBitOperator false
    rt::set_parameter writeBlackboxInterface true
    rt::set_parameter merge_flipflops true
    rt::set_parameter srlDepthThreshold 3
    rt::set_parameter rstSrlDepthThreshold 4
    rt::set_parameter webTalkPath {}
    rt::set_parameter enableSplitFlowPath "./.Xil/Vivado-5128-803-016/"
    if {$rt::useElabCache == false} {
      rt::run_rtlelab -module $rt::top
    }

    set rt::flowresult [ source $::env(SYNTH_COMMON)/flow.tcl ]
    rt::HARTNDb_stopJobStats
    if { $rt::flowresult == 1 } { return -code error }

    if { [ info exists ::env(RT_TMP) ] } {
      file delete -force $::env(RT_TMP)
    }


    source $::env(HRT_TCL_PATH)/rtSynthCleanup.tcl
  } ; #end uplevel
} rt::result]

if { $rt::rc } {
  $rt::db resetHdlParse
  source $::env(HRT_TCL_PATH)/rtSynthCleanup.tcl
  return -code "error" $rt::result
}
