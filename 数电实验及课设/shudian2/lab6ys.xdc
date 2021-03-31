set_property -dict { PACKAGE_PIN U9   IOSTANDARD LVCMOS33 } [get_ports { x }]
## Clock signal
set_property -dict { PACKAGE_PIN U8    IOSTANDARD LVCMOS33 } [get_ports { clk }]
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets clk_IBUF]
set_property -dict { PACKAGE_PIN U7   IOSTANDARD LVCMOS33 } [get_ports { led[0] }]
set_property -dict { PACKAGE_PIN U6   IOSTANDARD LVCMOS33 } [get_ports { led[1] }]
set_property -dict { PACKAGE_PIN V4   IOSTANDARD LVCMOS33 } [get_ports { led[2] }]
set_property -dict { PACKAGE_PIN T8   IOSTANDARD LVCMOS33 } [get_ports { led[3] }]
set_property -dict { PACKAGE_PIN P2   IOSTANDARD LVCMOS33 } [get_ports { z }]
