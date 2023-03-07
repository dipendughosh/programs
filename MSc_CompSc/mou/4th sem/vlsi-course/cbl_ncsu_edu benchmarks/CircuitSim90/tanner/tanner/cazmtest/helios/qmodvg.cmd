*.dc vg 0 0.7 0.07 vd 0 2 0.1
transfer {vg 0 0.7 0.07 vd 0 2 0.1}
*.print v(d) v(g) lx9(j1) lx11(j1)
plot {vtx(g) qtx(z1,d) qtx(z1,g) qtx(z1,s)}
*.print lx9(j1) lx11(j1)
*.options dccap ingold=2
*.end
