table nlin x.ftx x.qtx
waveform input sin amp=1.0 freq=1.e8 
transient 1n
plot {input, output, i(zout, output) }

