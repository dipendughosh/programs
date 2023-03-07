volt vdd gnd 3.0
volt Wd1 gnd 0

waveform Pre piecewise {0 3.0 2n 0 10.5n 0 12.5n 3.0 25n 3.0}
waveform Wd0 piecewise {0 0 12.5n 0 14.5n 3.0 23n 3.0 25n 0}

waveform Wr0 piecewise {0 0 12.5n 0 14.5n 3.0 23n 3.0 25n 0 100n 0}
waveform Wr1 piecewise {0 0 62.5n 0 64.5n 3.0 73n 3.0 75n 0 100n 0}

transient 100n powerup
plot {Pre Wd0 Wr0 Wr1 St0H St0L BitHEP2 BitLEP2}
