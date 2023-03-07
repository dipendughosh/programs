analyze -format vhdl constant_lib.vhd
analyze -format vhdl smallmux.vhd

vhdlout_architecture_name = "SYN"
vhdlout_use_packages = {"IEEE.std_logic_1164", "IEEE.std_logic_arith.all", "LSI_10K.COMPONENTS.all"}

elaborate smallmux
compile
write -format vhdl -hierarchy -output smallmux_gate.vhd
write -format db -hierarchy -output smallmux_gate.db
report_area
report_timing

exit
