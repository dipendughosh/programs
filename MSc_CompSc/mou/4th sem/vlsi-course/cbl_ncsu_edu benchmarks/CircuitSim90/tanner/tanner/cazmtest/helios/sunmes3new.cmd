wave cin 0 bit  {10} label=vcin rt=200ps ft=200ps ht=1ps lt=4ns on=.6 off=.1 delay=200ps
*transient 4ns 10ps
transient 4ns 
plot { v(cin) v(s0) v(s1) v(s2) v(s3) v(s4) v(s5) v(s6) }
plot sunmes3new.out { v(cin) v(s0) v(s1) v(s2) v(s3) v(s4) v(s5) v(s6) } 
options chargetol=1.0e-16
*temp 25
*gridsize mes 100 100
*vrange mes 2.5
