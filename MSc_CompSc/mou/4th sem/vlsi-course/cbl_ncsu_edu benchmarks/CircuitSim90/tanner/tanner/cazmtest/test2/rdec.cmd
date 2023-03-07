volt vdd 3.0
volt cs  3.0

wave a0 bit {8(000111)} pw=8n on=3.0 off=0.0
wave a1 bit {4(000111)} pw=16n on=3.0 off=0.0
wave a2 bit {2(000111)} pw=32n on=3.0 off=0.0


plot {a0 a1 a2 w1 w2 w3 w4}

transient 200n 
