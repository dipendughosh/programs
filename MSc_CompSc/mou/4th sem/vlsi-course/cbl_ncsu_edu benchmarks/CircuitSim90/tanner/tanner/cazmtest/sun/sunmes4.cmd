wave cin 0 pie {0 .6 0.2ns .1 1ns .1 1.2ns .6 2ns .6 2.2ns .1 3ns .1
 3.2ns .6 4.0ns .6 4.2ns .1 5.0ns .1
 5.2ns .6 6.0ns .6 6.2ns .1 7.0ns .1
 7.2ns .6 8.0ns .6 8.2ns .1 9.0ns .1
 9.2ns .6 10.0ns .6 10.2ns .1 11.0ns .1
 }
transient 15ns 100ps
plot { v(cin) v(s0) v(s1) v(s2) v(s3) v(s4) v(s5) v(s6) }
*temp 25
*gridsize mes 100 100
*vrange mes 2.5
