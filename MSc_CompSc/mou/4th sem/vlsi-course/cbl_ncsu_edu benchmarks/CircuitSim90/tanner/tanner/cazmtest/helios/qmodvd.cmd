*volt d 0 0.0 label=vd
*volt g 0 0.0 label=vg
*volt s 0 0.0 label=vs
*volt b 0 0.6 label=vb
*
*.dc vd 0 2 0.02 vg 0 0.7 0.1
transfer {vd 0 2 0.02 vg 0 0.7 0.1}
*.print v(d) v(g) lx9(j1) lx11(j1)
plot {vtx(d) qtx(z1,d) qtx(z1,g) qtx(z1,s)}
*.print lx9(j1) lx11(j1)
*.options dccap ingold=2
*.end
