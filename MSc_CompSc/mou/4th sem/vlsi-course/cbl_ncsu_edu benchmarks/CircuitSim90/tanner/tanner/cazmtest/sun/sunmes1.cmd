wave 1 99 bit {01} on=0.6 off=0.0 rt=.1n ft=.1n pw=1n
*plot { V(1) V(2) V(3) V(4) V(5) V(6) V(7) }
plot { V(1) V(2) }
plot sunmes1.out { V(1) V(2) }
transient 5N 20P
