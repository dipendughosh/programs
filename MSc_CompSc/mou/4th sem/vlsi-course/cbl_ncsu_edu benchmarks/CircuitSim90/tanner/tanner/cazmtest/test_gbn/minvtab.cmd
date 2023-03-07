
volt Vdd 5.0
volt in 0.0 label=VIN
plot { out q(freda,out), q(freda,in), q(freda,gnd)}
table minv minv.ftx minv.qtx
transfer {VIN 0 5 0.1 }

