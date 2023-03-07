analyze -format vhdl constant_lib.vhd
analyze -format vhdl ctrl_unit.vhd

vhdlout_architecture_name = "SYN"
vhdlout_use_packages = {"IEEE.std_logic_1164", "IEEE.std_logic_arith.all", "LSI_10K.COMPONENTS.all"}

elaborate ctrl_unit
uniquify
compile
write -format vhdl -hierarchy -output ctrl_unit_gate.vhd
write -format db -hierarchy -output ctrl_unit_gate.db
report_area
report_timing

exit
