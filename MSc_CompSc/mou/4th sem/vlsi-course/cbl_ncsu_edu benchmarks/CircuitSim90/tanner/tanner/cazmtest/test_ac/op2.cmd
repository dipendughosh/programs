* BJT OPAMP
*
*
* INPUTS
acmodel {*}
options numnd=5000 numnt=100
volt in gnd 0.0 acmag=1.0 acphase=0.0
ac dec 20 1000 100000
plot {vdb(OUT) vp(OUT) vdb(6) vdb(10) } 


