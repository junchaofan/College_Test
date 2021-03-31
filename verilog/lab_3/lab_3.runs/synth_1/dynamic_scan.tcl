# 
# Synthesis run script generated by Vivado
# 

debug::add_scope template.lib 1
set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
set_msg_config -id {Synth 8-256} -limit 10000
set_msg_config -id {Synth 8-638} -limit 10000
create_project -in_memory -part xc7vx485tffg1157-1

set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir C:/Users/Administrator/Desktop/verilog/lab_3/lab_3.cache/wt [current_project]
set_property parent.project_path C:/Users/Administrator/Desktop/verilog/lab_3/lab_3.xpr [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
read_verilog -library xil_defaultlib {
  C:/Users/Administrator/Desktop/verilog/lab_3/rom8x4.v
  C:/Users/Administrator/Desktop/verilog/lab_3/decoder3_8.v
  C:/Users/Administrator/Desktop/verilog/lab_3/pattern.v
  C:/Users/Administrator/Desktop/verilog/lab_3/divider.v
  C:/Users/Administrator/Desktop/verilog/lab_3/counter.v
  C:/Users/Administrator/Desktop/verilog/lab_3/dynamic_scan.v
}
read_xdc C:/Users/Administrator/Desktop/verilog/lab_3/lab3_nexys4.xdc
set_property used_in_implementation false [get_files C:/Users/Administrator/Desktop/verilog/lab_3/lab3_nexys4.xdc]

synth_design -top dynamic_scan -part xc7vx485tffg1157-1
write_checkpoint -noxdef dynamic_scan.dcp
catch { report_utilization -file dynamic_scan_utilization_synth.rpt -pb dynamic_scan_utilization_synth.pb }