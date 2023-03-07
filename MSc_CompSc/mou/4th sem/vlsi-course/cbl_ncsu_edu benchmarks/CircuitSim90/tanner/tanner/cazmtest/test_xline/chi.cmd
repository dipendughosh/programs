
waveform src sin amp=1.0 freq=1.0e8
dcoppt
transient 1n
ic {i(Ls)=-0.10e-2 output=1 input=1}
plot {input, output idc(Ls, input) idc(Ls, output) }


