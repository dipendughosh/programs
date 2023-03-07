analyze -format vhdl constant_lib.vhd
analyze -format vhdl PC.vhd

vhdlout_architecture_name = "SYN"
vhdlout_use_packages = {"IEEE.std_logic_1164", "IEEE.std_logic_arith.all", "LSI_10K.COMPONENTS.all"}

elaborate PC
compile
write -format vhdl -hierarchy -output PC_gate.vhd
write -format db -hierarchy -output PC_gate.db
report_area
report_timing

exit
