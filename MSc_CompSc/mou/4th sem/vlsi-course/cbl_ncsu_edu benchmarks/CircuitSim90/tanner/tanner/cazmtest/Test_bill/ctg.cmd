*********************************************
**   ECE546 Project - Silicon Retina       **
**   Simple Transconductance Amplifier     **
**   p. 70 Mead                            **
*********************************************

volt vdd 5
volt v1 3 
volt vb 0.7 
volt out GND 2.5 label=OUT

options abstol=1.0e-14
transfer  {v2 1 5} 
plot {vtx(v2) itx(OUT,GND) }

