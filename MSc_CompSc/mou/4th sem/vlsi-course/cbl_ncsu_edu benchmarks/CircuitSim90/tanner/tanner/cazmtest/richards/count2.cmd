volt Vdd 5.5v
* Initially setting value of FF's to 1
* to observe carry delay

*ic{c1/int2=5.5v c2/int2=5.5v c3/int2=5.5v c4/int2=5.5v c5/int2=5.5v c6/int2=5.5v c7/int2=5.5v}
*ic{c8/int2=5.5v c9/int2=5.5v c10/int2=5.5v c11/int2=5.5v c12/int2=5.5v c13/int2=5.5v}
*ic{c14/int2=5.5v c15/int2=5.5v c16/int2=0v}
*ic{c1/int4=0v c2/int4=0v c3/int4=0v c4/int4=0v c5/int4=0v c6/int4=0v c7/int4=0v}
*ic{c8/int4=0v c9/int4=0v c10/int4=0v c11/int4=0v c12/int4=0v c13/int4=0v}
*ic{c14/int4=0v c15/int4=0v c16/int4=5.5v}

ic{c1/int1=5.5 c1/int2=5.5 c1/int3=0 c1/int4=0 c1/q=5.5 c1/qb=0}

wave clk1 bit  { 2(0) 5(1) 8(0)} pw=2n on=5.5v off=0.0 rt=2n ft=2n
wave clk1b bit { 2(1) 5(0) 8(1)} pw=2n on=5.5v off=0.0 rt=2n ft=2n
wave clk2 bit  { 8(0) 5(1) 2(0)} pw=2n on=5.5v off=0.0 rt=2n ft=2n
wave clk2b bit { 8(1) 5(0) 2(1)} pw=2n on=5.5v off=0.0 rt=2n ft=2n
wave C0 bit    { 2(0) 257(1) } pw=30n on=5.5v off=0.0 rt=2n ft=2n
wave C0b bit   { 2(1) 257(0) } pw=30n on=5.5v off=0.0 rt=2n ft=2n
wave reset bit { 2(0) 258(0) } pw=30n on=5.5v off=0.0 rt=2n ft=2n

plot {c1/int1 c1/int2 c1/int3 c1/int4 c1/qb S1}
plot {clk1 clk2 reset }
*plot { S1 S2 S15 S16 }
*plot { C0 C1 C2 }

temp 0
transient 180n 


