wave 10 0 bit  {10} label=vdd rt=1n ft=1n ht=4e-09 lt=2.01e-07 on=0 off=5 delay=-4e-09 pw=205n
transient 120n 1n
wave 2 0 bit  {10} label=vwr rt=2n ft=2n ht=3e-08 lt=2e-08 on=0 off=5 delay=-2.1e-08 pw=50n
wave 3 0 bit  {10} label=vrd1 rt=2n ft=2n ht=4e-08 lt=2e-08 on=0 off=5 delay=-1.1e-08 pw=60n
wave 4 0 bit  {10} label=vrd2 rt=2n ft=2n ht=4e-08 lt=2e-08 on=0 off=5 delay=-1.1e-08 pw=60n
wave 18 0 bit  {10} label=vdi rt=2n ft=2n ht=7e-08 lt=1.3e-07 on=0 off=5 delay=-2.1e-08 pw=200n

plot { v(2) v(3) v(4) v(6) v(7)}
plot { v(8) v(13) v(14) v(17)}
plot { v(21) v(22)}
