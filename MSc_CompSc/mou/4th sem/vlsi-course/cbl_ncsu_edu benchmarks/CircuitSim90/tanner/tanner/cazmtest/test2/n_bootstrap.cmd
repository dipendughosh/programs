volt 1 gnd 0
wave 24 bit {10} on=5.0v off=0 pw=200ns rt=1ns ft=1ns delay=0ns 
wave 14 bit {1000} on=5.0v off=0 pw=40ns rt=1ns ft=1ns delay=0ns 
wave 19 bit {01} on=5.0v off=0 pw=100ns rt=1ns ft=1ns
plot { v(24) v(38) v(14) v(19) }
transient  200ns 1ns {38 = 3.5}
