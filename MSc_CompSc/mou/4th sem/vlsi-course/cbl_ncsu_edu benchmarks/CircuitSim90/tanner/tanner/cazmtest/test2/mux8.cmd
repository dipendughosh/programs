wave f0 bit {1000000010}  ph=2u off=0.0 on=5.0 
wave f1   bit {0100000001} ph=2u off=0.0 on=5.0
wave f2   bit {0010000000} ph=2u off=0.0 on=5.0
wave f3   bit {0001000000} ph=2u off=0.0 on=5.0
wave f4   bit {0000100000} ph=2u off=0.0 on=5.0
wave f5   bit {0000010000} ph=2u off=0.0 on=5.0
wave f6   bit {0000001000} ph=2u off=0.0 on=5.0
wave f7   bit {0000000100} ph=2u off=0.0 on=5.0

wave ctla bit   {01} ph=250n on=5.0 off=0.0
wave ctlb bit  {01} ph=500n on=5.0 off=0.0
wave ctlc bit  {01} ph=1000n on=5.0 off=0.0


plot { f0 f1 f2 f3 f4 f5 f6 f7 out mux ctla ctlb ctlc }

transient 20000n 
