
volt Vdd 3.0
volt in 0.0 label=VIN
*wave in pie {0n 0 100n 0 101n 3 200n 3 201n 0 300n 0 301n 3 400n 3 401n 0}
plot {in out itx(md1,out) itx(md2,out) qtx(md1,out)}
transfer { VIN 0 3 0.1 }
