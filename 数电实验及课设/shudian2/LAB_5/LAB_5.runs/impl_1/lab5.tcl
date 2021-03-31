proc start_step { step } {
  set stopFile ".stop.rst"
  if {[file isfile .stop.rst]} {
    puts ""
    puts "*** Halting run - EA reset detected ***"
    puts ""
    puts ""
    return -code error
  }
  set beginFile ".$step.begin.rst"
  set platform "$::tcl_platform(platform)"
  set user "$::tcl_platform(user)"
  set pid [pid]
  set host ""
  if { [string equal $platform unix] } {
    if { [info exist ::env(HOSTNAME)] } {
      set host $::env(HOSTNAME)
    }
  } else {
    if { [info exist ::env(COMPUTERNAME)] } {
      set host $::env(COMPUTERNAME)
    }
  }
  set ch [open $beginFile w]
  puts $ch "<?xml version=\"1.0\"?>"
  puts $ch "<ProcessHandle Version=\"1\" Minor=\"0\">"
  puts $ch "    <Process Command=\".planAhead.\" Owner=\"$user\" Host=\"$host\" Pid=\"$pid\">"
  puts $ch "    </Process>"
  puts $ch "</ProcessHandle>"
  close $ch
}

proc end_step { step } {
  set endFile ".$step.end.rst"
  set ch [open $endFile w]
  close $ch
}

proc step_failed { step } {
  set endFile ".$step.error.rst"
  set ch [open $endFile w]
  close $ch
}

set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000

start_step init_design
set rc [catch {
  create_msg_db init_design.pb
  debug::add_scope template.lib 1
  set_property design_mode GateLvl [current_fileset]
  set_property webtalk.parent_dir C:/Users/Administrator/Desktop/shudian2/LAB_5/LAB_5.cache/wt [current_project]
  set_property parent.project_path C:/Users/Administrator/Desktop/shudian2/LAB_5/LAB_5.xpr [current_project]
  set_property ip_repo_paths c:/Users/Administrator/Desktop/shudian2/LAB_5/LAB_5.cache/ip [current_project]
  set_property ip_output_repo c:/Users/Administrator/Desktop/shudian2/LAB_5/LAB_5.cache/ip [current_project]
  add_files -quiet C:/Users/Administrator/Desktop/shudian2/LAB_5/LAB_5.runs/synth_1/lab5.dcp
  read_xdc C:/Users/Administrator/Desktop/shudian2/lab5ys.xdc
  link_design -top lab5 -part xc7a100tcsg324-1
  close_msg_db -file init_design.pb
} RESULT]
if {$rc} {
  step_failed init_design
  return -code error $RESULT
} else {
  end_step init_design
}

start_step opt_design
set rc [catch {
  create_msg_db opt_design.pb
  catch {write_debug_probes -quiet -force debug_nets}
  opt_design 
  write_checkpoint -force lab5_opt.dcp
  catch {report_drc -file lab5_drc_opted.rpt}
  close_msg_db -file opt_design.pb
} RESULT]
if {$rc} {
  step_failed opt_design
  return -code error $RESULT
} else {
  end_step opt_design
}

start_step place_design
set rc [catch {
  create_msg_db place_design.pb
  catch {write_hwdef -file lab5.hwdef}
  place_design 
  write_checkpoint -force lab5_placed.dcp
  catch { report_io -file lab5_io_placed.rpt }
  catch { report_utilization -file lab5_utilization_placed.rpt -pb lab5_utilization_placed.pb }
  catch { report_control_sets -verbose -file lab5_control_sets_placed.rpt }
  close_msg_db -file place_design.pb
} RESULT]
if {$rc} {
  step_failed place_design
  return -code error $RESULT
} else {
  end_step place_design
}

start_step route_design
set rc [catch {
  create_msg_db route_design.pb
  route_design 
  write_checkpoint -force lab5_routed.dcp
  catch { report_drc -file lab5_drc_routed.rpt -pb lab5_drc_routed.pb }
  catch { report_timing_summary -warn_on_violation -max_paths 10 -file lab5_timing_summary_routed.rpt -rpx lab5_timing_summary_routed.rpx }
  catch { report_power -file lab5_power_routed.rpt -pb lab5_power_summary_routed.pb }
  catch { report_route_status -file lab5_route_status.rpt -pb lab5_route_status.pb }
  catch { report_clock_utilization -file lab5_clock_utilization_routed.rpt }
  close_msg_db -file route_design.pb
} RESULT]
if {$rc} {
  step_failed route_design
  return -code error $RESULT
} else {
  end_step route_design
}

start_step write_bitstream
set rc [catch {
  create_msg_db write_bitstream.pb
  write_bitstream -force lab5.bit 
  catch { write_sysdef -hwdef lab5.hwdef -bitfile lab5.bit -meminfo lab5.mmi -ltxfile debug_nets.ltx -file lab5.sysdef }
  close_msg_db -file write_bitstream.pb
} RESULT]
if {$rc} {
  step_failed write_bitstream
  return -code error $RESULT
} else {
  end_step write_bitstream
}

