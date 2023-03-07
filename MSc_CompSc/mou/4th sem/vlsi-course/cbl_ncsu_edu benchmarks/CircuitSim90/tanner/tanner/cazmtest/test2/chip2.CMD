


wave phi1   bit  {01} ph=50n on=5.0 off=0.0
wave phi1b  bit  {10} ph=50n on=5.0 off=0.0
wave phi2   bit  {10} ph=50n on=5.0 off=0.0
wave phi2b  bit  {01} ph=50n on=5.0 off=0.0

wave din1  bit  {01} ph=500n on=5.0 off=0.0
wave din2  bit  {01} ph=500n on=5.0 off=0.0
wave din3  bit  {01} ph=500n on=5.0 off=0.0
wave din4  bit  {01} ph=500n on=5.0 off=0.0
wave din5  bit  {01} ph=500n on=5.0 off=0.0
wave din6  bit  {01} ph=500n on=5.0 off=0.0
wave din7  bit  {01} ph=500n on=5.0 off=0.0
wave din8  bit  {01} ph=500n on=5.0 off=0.0

wave c1  bit  {10} ph=5000m on=5.0 off=0.0
wave c2  bit  {10} ph=5000m on=5.0 off=0.0
wave c3  bit  {10} ph=5000m on=5.0 off=0.0
wave c4  bit  {10} ph=5000m on=5.0 off=0.0
wave c5  bit  {01} ph=5000m on=5.0 off=0.0
wave c6  bit  {01} ph=5000m on=5.0 off=0.0
wave c7  bit  {01} ph=5000m on=5.0 off=0.0
wave c8  bit  {01} ph=5000m on=5.0 off=0.0

plot { phi2 din1 dout1 dout2 dout3 dout4 dout5 dout6 dout7 dout8 }

transient 5000n powerup


*cl aphi1   100n 01
*cl aphi1b  100n 10
*cl aphi2   100n 10
*cl aphi2b  100n 01

*cl adin    1000n   01

*cl ac1     10000m  10
*cl ac2     10000m  10
*cl ac3     10000m  10
*cl ac4     10000m  10
*cl ac5     10000m  01
*cl ac6     10000m  01
*cl ac7     10000m  01
*cl ac8     10000m  01

*as aphi1   phi1
*as aphi1b  phi1b
*as aphi2   phi2
*as aphi2b  phi2b

*as ac1  c1
*as ac2  c2
*as ac3  c3
*as ac4  c4
*as ac5  c5
*as ac6  c6
*as ac7  c7
*as ac8  c8

*as adin din1
*as adin din2
*as adin din3
*as adin din4
*as adin din5
*as adin din6
*as adin din7
*as adin din8

*pl phi2 din1 dout1 dout2 dout3 dout4 dout5 dout6 dout7 dout8

*sl 5000n
