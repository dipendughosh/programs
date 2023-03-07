wave 113 0 bit  {10} label=v$d3 rt=5.0e-9 ft=5.0e-9 ht=3.5e-08 lt=2.5e-08 on=0.0 off=5.0 delay=-3.4e-08 pw=6.0e-8
wave 42 0 bit  {10} label=v$d2 rt=5.0e-9 ft=5.0e-9 ht=7.5e-08 lt=8.5e-08 on=0.0 off=5.0 delay=-3e-08 pw=1.6e-7

temp 27.0
plot { v(113) v(42) v(154) v(155) v(160) v(161) v(162) v(163)}
transient 1.2e-7 6.0e-10
