* STRING OF OPERATIONAL AMPLIFIERS
*
***  INPUT VOLTAGE SOURCES
*VM   120     0    DC=2.5V  SIN (0 2.3V 20)
volt   120     0    2.5V  
*VM   120     0    PWL 0 .2 1 4.8 2 4.8
volt   101   103    2V acmag=1V    
volt   109   110    0V
*
**  SIMULATIONS
*  BODE PLOT
*.AC DEC 2 1HZ 100MEGHZ
dcoppt
ac dec 2 1 100MEG
vrange bjt 70
gridsize bjt 40 40
options numnd=1000 numnt=10  abstol=1.0e-12 reltol=1.0e-12
plot { vdb(36) vp(36) vm(36)}
plot { vdc(36) }
