wave 8 0 bit  {10} label=vcp rt=1ns ft=1ns ht=5.4e-08 lt=4.6e-08 on=4.2v off=3.7v delay=-5.3e-08 pw=100ns
wave 9 0 bit  {10} label=vcin rt=1ns ft=1ns ht=5.4e-08 lt=4.6e-08 on=4.2v off=3.7v delay=-5.3e-08 pw=100ns
wave 18 0 bit  {10} label=vclk rt=2ns ft=2ns ht=5e-09 lt=5e-09 on=3.7v off=4.2v delay=-3e-09 pw=10ns
wave 15 0 bit  {10} label=vnclk rt=2ns ft=2ns ht=5e-09 lt=5e-09 on=4.2v off=3.7v delay=-3e-09 pw=10ns
wave 24 0 bit  {10} label=vclr rt=0.5ns ft=0.5ns ht=9.9e-08 lt=1e-09 on=2.9v off=3.4v delay=-9.85e-08 pw=100ns

dcoppt
transient 70ns 0.5ns
plot { v(8) v(18) v(3) v(12) v(20) v(2)}
