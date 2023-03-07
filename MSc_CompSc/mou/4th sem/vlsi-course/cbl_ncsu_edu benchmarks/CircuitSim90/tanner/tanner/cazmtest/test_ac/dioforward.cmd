
options abstol=1.0e-20
volt vin GND 0.25 acmag=0.25 acphase=0.0 label=V1
ac dec 10 100MEG 10000MEG
plot { ir(D1,out) ii(D1,out) ir(R1,out) ii(R1,out) i(V1,vin)}

acmodel{ D1 }


