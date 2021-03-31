set_property -dict { PACKAGE_PIN E3   IOSTANDARD LVCMOS33 } [get_ports { cp }];

set_property -dict { PACKAGE_PIN U9   IOSTANDARD LVCMOS33 } [get_ports { sin[0] }]; 
set_property -dict { PACKAGE_PIN U8   IOSTANDARD LVCMOS33 } [get_ports { sin[1] }];
set_property -dict { PACKAGE_PIN R7   IOSTANDARD LVCMOS33 } [get_ports { sin[2] }]; 
set_property -dict { PACKAGE_PIN R6   IOSTANDARD LVCMOS33 } [get_ports { sin[3] }]; 
set_property -dict { PACKAGE_PIN R5   IOSTANDARD LVCMOS33 } [get_ports { m }];
set_property -dict { PACKAGE_PIN V7   IOSTANDARD LVCMOS33 } [get_ports { ld }]; 
set_property -dict { PACKAGE_PIN V6   IOSTANDARD LVCMOS33 } [get_ports { clr }];

set_property -dict { PACKAGE_PIN T8   IOSTANDARD LVCMOS33 } [get_ports { led[0] }];
set_property -dict { PACKAGE_PIN V9   IOSTANDARD LVCMOS33 } [get_ports { led[1] }];
set_property -dict { PACKAGE_PIN R8   IOSTANDARD LVCMOS33 } [get_ports { led[2] }];
set_property -dict { PACKAGE_PIN T6   IOSTANDARD LVCMOS33 } [get_ports { led[3] }];
set_property -dict { PACKAGE_PIN T5   IOSTANDARD LVCMOS33 } [get_ports { led[4] }];
set_property -dict { PACKAGE_PIN T4   IOSTANDARD LVCMOS33 } [get_ports { led[5] }];
set_property -dict { PACKAGE_PIN U7   IOSTANDARD LVCMOS33 } [get_ports { led[6] }];
set_property -dict { PACKAGE_PIN U6   IOSTANDARD LVCMOS33 } [get_ports { led[7] }];

set_property -dict { PACKAGE_PIN R1   IOSTANDARD LVCMOS33 } [get_ports { qout[0] }];
set_property -dict { PACKAGE_PIN P5   IOSTANDARD LVCMOS33 } [get_ports { qout[1] }]; 
set_property -dict { PACKAGE_PIN U1   IOSTANDARD LVCMOS33 } [get_ports { qout[2] }]; 
set_property -dict { PACKAGE_PIN R2   IOSTANDARD LVCMOS33 } [get_ports { qout[3] }]; 
set_property -dict { PACKAGE_PIN P2   IOSTANDARD LVCMOS33 } [get_ports { qcc }]; 