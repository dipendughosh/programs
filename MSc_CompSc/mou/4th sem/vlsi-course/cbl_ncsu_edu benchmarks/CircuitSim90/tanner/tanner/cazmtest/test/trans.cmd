wave phi1 bit {0011} pw=2n off=0.0 on=3.0 rt=.25n ft=.25n
wave phi2 bit {1100} pw=2n off=0.0 on=3.0 rt=.25n ft=.25n
wave data bit {1000} pw=4n off=0.0 on=3.0 rt=.25n ft=.25n

volt vdd vss 3
plot {phi1 phi2 data n1 }
transient 20n 0.20n
