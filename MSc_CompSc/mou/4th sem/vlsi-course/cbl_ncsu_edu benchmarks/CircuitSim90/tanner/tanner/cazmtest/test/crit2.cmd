
*
*
*	Clock commands
*
wave 3 bit {10} pw=20n on=4.3 off=0.0
*Vphi1 3  0 pulse(4.3 0 20n 5n 5n 20n 40n)
*Vphi2 4  0 pulse(0 4.3 20n 5n 5n 20n 40n)
wave 4 bit {10} pw=20n on=0.0 off=4.3 rt=5n ft=5n
volt 1  0 4.3
volt vin 0.3
*
*
* ANALYSIS COMMANDS
*
plot {3 4 7 }
transient 200n 
