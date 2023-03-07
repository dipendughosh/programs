* file BIPOLE: Schottky TTL edge-triggered register
*
*
*
*
**********************************************************************
*
*      Power supplies
*
*vcc   100    0    dc    5.0
volt   100    0    5.0
*
*
**********************************************************************
*
*     Input wiggles  (piecewise linear waveforms)
*
wave   170  pie {  0ns 4.0   1ns 4.0   3ns 0.0     10ns 0.0 }
*
wave   171  pie {  0ns 4.0   1ns 4.0   3ns 0.06    10ns 0.0 }
*
*
*
*
options numnd=400
transient 15ns .1ns
plot   { v(170) v(171) v(250)   v(260)   v(350)   v(360) v(450)   v(460)   v(550)   v(560) }

*plot   { NG1/321 NG1/311 NG1/322 NG1/400 }
*dcg { 260=0.1
*          350=4.0
*          360=4.0
*          450=0.1
*          460=4.0
*          550=4.0
*          560=0.1 }
