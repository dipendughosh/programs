wave 11 0 pie { 0 5 1e-9 5 1.1e-09 0 5.9e-09 0 6e-09 5  }
transient  20ns
*.print tran i(vseu) i(vamp)
plot { i(vseu,10) i(vamp,12) }
