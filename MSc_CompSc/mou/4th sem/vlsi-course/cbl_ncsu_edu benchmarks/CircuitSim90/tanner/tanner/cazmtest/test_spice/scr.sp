* SCR circuit
.model nbjt npn 
.model pbjt pnp 

.subckt scr 3 4
r0 5 3 1e3
q1 4 5 3 pbjt
q2 5 4 0 nbjt
.ends scr

xcr1 6 7 scr
rload 6 1 10
rtrig 7 2 100

.tran 1.0e-4 1.0e-2
.print tran v(1) v(2)
*transient 1.0e-2
*wave 1 0 sin amp=170 freq=60
vpow 1 0 sin (0 170 60 0 0)
vwave 2 0 pwl(0,0, 4e-3,0, 4.1e-3,1, 4.323e-3,1, 4.333e-3,0, 8.333,0)
***** ACTUALLY want amp=170, but even untriggered case bombs *****
*wave trig gnd pie {0,0, 4e-3,0, 4.1e-3,1, 4.323e-3,1, 4.333e-3,0, 8.333,0}
***** ACTUALLY want to use wave ... bit{...}, but delay=4e-3 doesn't work *****
*plot {v(power), v(trig), i(rload, power)}
*options numnt=300 numnd=1500
.options itl3=300 itl4=1500

.end
