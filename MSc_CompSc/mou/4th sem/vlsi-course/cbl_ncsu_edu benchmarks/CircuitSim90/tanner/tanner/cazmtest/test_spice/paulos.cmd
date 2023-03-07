
*volt 99 0 2.5
wave 34 99 bit  {10} label=VAP rt=1E-9 ft=1E-9 ht=4.9e-08 lt=5.1e-08 on=0.0 off=0.5 delay=-4.9e-08 pw=100E-9
dcoppt
options numnd=400
transient 100N 1N
plot { V(34) V(12)}
*dcg { 1=5 3=1.0108 4=1.210 5=2.3765 6=3.6096
* 7=3.880 9=1.213 11=1.0108 12=2.5001 32=3.7752
* 36=1.0108                
* }
