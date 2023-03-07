volt a1 5.0
volt a2 0.0
wave c1 bit {4(000111)} pw=4n on=5 off=0
wave b1 bit {2(000111)} pw=8n on=5.0 off=00
wave b2 bit {000111} pw=16n on=5.0 off=0.0
plot {c1 b1 b2 q1}
transient 100n
