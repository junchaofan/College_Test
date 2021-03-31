set_property -dict { PACKAGE_PIN U3   IOSTANDARD LVCMOS33 } [get_ports { z }];  
set_property -dict { PACKAGE_PIN U9   IOSTANDARD LVCMOS33 } [get_ports { x }]; 
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets x_IBUF]
set_property -dict { PACKAGE_PIN P5   IOSTANDARD LVCMOS33 } [get_ports { q1 }]; 
set_property -dict { PACKAGE_PIN U1   IOSTANDARD LVCMOS33 } [get_ports { q2 }]; 
set_property -dict { PACKAGE_PIN R2   IOSTANDARD LVCMOS33 } [get_ports { q3 }]; 
set_property -dict { PACKAGE_PIN P2   IOSTANDARD LVCMOS33 } [get_ports { q4 }];