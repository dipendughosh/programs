wave f0   bit {1000000010} ph=2u off=0.0 on=5.0
wave f1   bit {0100000001} ph=2u off=0.0 on=5.0
wave f2   bit {0010000000} ph=2u off=0.0 on=5.0
wave f3   bit {0000010000} ph=2u off=0.0 on=5.0

wave clta ff sin freq=10MEG amp=2 offset=.5 label=gg
wave cltb sini freq=10MEG amp=2u offset=.5u 
wave cltc pie { 0ns 0.0 2000ns 5.0 4000ns 5.0 8000ns 0.0}

wave cltx bit  {01} ph=250n on=5.0 off=0.0
wave clty bit  {01} ph=500n on=5.0 off=0.0
wave cltz biti {01} ph=1000n on=5.0u off=0.0

plot { f0 f1 f2 f3 cltx clty cltz }
plot { clta cltb cltc }

transient 80000n 100n


