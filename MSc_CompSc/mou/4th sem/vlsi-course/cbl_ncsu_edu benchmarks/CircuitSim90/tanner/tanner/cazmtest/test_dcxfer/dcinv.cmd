volt Vdd GND 5v
volt gate GND 5v
dcg { out=2 }

plot { gate, out, i(out,GND) q(out,GND) i(m1p, drain) i(m1p, source) i(m1n, drain) } 
plot { q(m1n,drain) q(m1n,source) } 
dcoppt
*transient 100n .1n  
