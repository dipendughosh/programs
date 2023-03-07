*Q2S
*
* Spice node 2 corresponds to sim node a.
* Spice node 5 corresponds to sim node ck.
* Spice node 6 corresponds to sim node q.
* Spice node 3 corresponds to sim node 3_265_992.
* Spice node 4 corresponds to sim node 3_127_1042.
* Spice node 13 corresponds to sim node u1.
* Spice node 12 corresponds to sim node u2.
* Spice node 11 corresponds to sim node u3.
* Spice node 10 corresponds to sim node u4.
* Spice node 9 corresponds to sim node u5.
* Spice node 8 corresponds to sim node u6.
* Spice node 7 corresponds to sim node u7.
*
volt 0 gnd 0
volt 1 gnd 2.7 
*wave 2 pie {0 0 52ns 0 54ns 2.7 112ns 2.7 114ns 0 174ns 0 176ns 2.7 232ns 2.7 234ns 0}
*wave 5 pie {0 0 37ns 0 39ns 2.7 65ns 2.7 67ns 0 97ns 0 99ns 2.7 125ns 2.7 127ns 0 157ns 0 159ns 2.7 185ns 2.7 187ns 0 217ns 0 219ns 2.7 245ns 2.7 247ns 0}

wave 2 bit {00 4(8(0) 8(1))}  on=2.7 rt=2n ft=2n pw=5n off=0.0
wave 5 bit {4(1) 4(0)}  on=2.7 rt=2n ft=2n pw=5n off=0.0

*temp 70
transient 260n 0.5ns
plot {v(2) v(5) v(6)}
