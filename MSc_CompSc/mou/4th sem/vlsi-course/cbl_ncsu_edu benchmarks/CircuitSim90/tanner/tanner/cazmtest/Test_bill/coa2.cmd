options numnd=900 reltol=1e-12 abstol=1e-12
*
* transfer curve analysis
*
*gridsize mos 90 40 3
transfer { vss 0 0, inp 2.503 2.499 -.00005 }
*volt inp gnd 2.5005
plot{ inp, out }
current vdd bias 100u
volt inm 2.50
dcoppt
