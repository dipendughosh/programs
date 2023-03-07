analyze -format vhdl constant_lib.vhd
analyze -format vhdl IR.vhd

vhdlout_architecture_name = "SYN"
vhdlout_use_packages = {"IEEE.std_logic_1164", "IEEE.std_logic_arith.all", "LSI_10K.COMPONENTS.all"}

elaborate IR
compile
write -format vhdl -hierarchy -output IR_gate.vhd
write -format db -hierarchy -output IR_gate.db
report_area
report_timing

exit
