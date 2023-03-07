*
*
*	Clock commands
*
wave 2 bit {01} pw=40n on=4.3 off=0.0 rt=5n ft=5n
*Vin   2  0 pulse(0 4.3 40n 5n 5n 40n 80n)
wave 3 bit {10} pw=20n on=4.3 off=0.0 rt=5n ft=5n
*Vphi1 3  0 pulse(4.3 0 20n 5n 5n 20n 40n)
wave 4 bit {10} pw=20n on=0.0 off=4.3 rt=5n ft=5n
*Vphi2 4  0 pulse(0 4.3 20n 5n 5n 20n 40n)
volt 0 gnd 0
volt 1  0 4.3
volt 50 4.3
volt 51 0
volt 60 0
volt 61 4.3
volt 70 0
volt 71 4.3
volt 80 0
volt 81 4.3
*
*
* ANALYSIS COMMANDS
*
plot {2 8 12 16 20 21 22}
transient 200n 
