volt Vdd gnd 3.0
volt GND gnd 0.0

*wave Lmclkg piec { 0n,3 12.5n,3 15.5n,0 22n,0 25n,3 37.5n,3 40.5n,0 47n,0 50n,3 60n,3 }
wave clk bit   { 1 0 1 0 1 0 } pw=12.5n on=3.0 off=0.0

temp 70
transient 75n powerup 
*plot { clk Lclk Hclk Lmclkg Lsclkn sclk3 Lsclkg sclkpe sclki Lsclkpe }
plot { clk Lclk Hclk Lsclkn sclkg sclkpe Lsclkpe }
