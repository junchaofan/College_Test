# 
# Synthesis run script generated by Vivado
# 

debug::add_scope template.lib 1
set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
create_project -in_memory -part xc7a100tcsg324-1

set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir C:/Users/Administrator/Desktop/shudian2/LAB_4/LAB_4.cache/wt [current_project]
set_property parent.project_path C:/Users/Administrator/Desktop/shudian2/LAB_4/LAB_4.xpr [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
read_verilog -library xil_defaultlib {
  C:/Users/Administrator/Desktop/shudian2/counter.v
  C:/Users/Administrator/Desktop/shudian2/divider.v
  C:/Users/Administrator/Desktop/shudian2/lab4.v
}
read_xdc C:/Users/Administrator/Desktop/shudian2/lab4ys.xdc
set_property used_in_implementation false [get_files C:/Users/Administrator/Desktop/shudian2/lab4ys.xdc]

synth_design -top E4_1_TEST -part xc7a100tcsg324-1
write_checkpoint -noxdef E4_1_TEST.dcp
catch { report_utilization -file E4_1_TEST_utilization_synth.rpt -pb E4_1_TEST_utilization_synth.pb }
