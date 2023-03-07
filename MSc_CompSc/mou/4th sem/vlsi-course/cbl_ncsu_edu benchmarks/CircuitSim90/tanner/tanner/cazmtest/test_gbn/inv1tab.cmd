
volt Vdd 3.0
volt in 0.0 label=VIN
*wave in pie {0n 0 100n 0 101n 3 200n 3 201n 0 300n 0 301n 3 400n 3 401n 0}
table n125x2 nenh125x2.ftx nenh125x2.qtx
table p125x3 penh125x3.ftx penh125x3.qtx
plot {in out i(tran1, out) i(tran2, out) q(tran1, out)}
transfer { VIN 0 3 0.1  } 
