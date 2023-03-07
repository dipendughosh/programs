wave 3 0 bit  {10} label=vwr rt=1n ft=1n ht=1.61e-07 lt=3.9e-08 on=0 off=5 delay=-1.21e-07 pw=200n
wave 41 0 bit  {10} label=vad rt=1n ft=1n ht=4.6e-08 lt=3.9e-08 on=0 off=5 delay=-4.1e-08 pw=85n
wave 9 0 bit  {10} label=vdi rt=1n ft=1n ht=1.81e-07 lt=1.9e-08 on=0 off=5 delay=-1.16e-07 pw=200n
wave 1 0 bit  {10} label=vclk rt=1n ft=1n ht=1.69e-07 lt=3.1e-08 on=5 off=0 delay=-4.9e-08 pw=200n
ic {  10 =5,  5 =0,  4 =5,  6 =0,  7 =5  1 =5}

plot { v(2) v(4) v(5) v(16) v(17)}
transient 16n .25n
