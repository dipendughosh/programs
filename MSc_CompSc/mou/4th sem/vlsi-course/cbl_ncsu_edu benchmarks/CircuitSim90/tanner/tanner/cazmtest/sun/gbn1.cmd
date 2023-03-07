*.trans 20p 5n
transient 5n
*.print tran v(x1) v(in1) v(out[0]) v(out1)
*.print tran I(vcc)
options chargetol=1e-17
plot xnor4.out {v(x1) v(in1) v(out[0]) v(out1)}
plot {v(x1) v(in1) v(out[0]) v(out1)}
