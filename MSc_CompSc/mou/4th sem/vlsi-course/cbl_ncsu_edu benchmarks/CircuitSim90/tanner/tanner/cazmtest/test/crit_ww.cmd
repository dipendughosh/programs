*
*
*	Clock commands
*
wave 2 bit {010} pw=40n on=4.3 off=0.0 
*Vin   2  0 pulse(0 4.3 40n 5n 5n 40n 80n)
wave 3 bit {101} pw=20n on=4.3 off=0.0
*Vphi1 3  0 pulse(4.3 0 20n 5n 5n 20n 40n)
wave 4 bit {101} pw=20n on=0.0 off=4.3
*Vphi2 4  0 pulse(0 4.3 20n 5n 5n 20n 40n)
volt 1  0 4.3
volt 50 0
volt 51 4.3
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
plot {2 8 12 16 20 v(21) v(22)}

transient 200n powerup
