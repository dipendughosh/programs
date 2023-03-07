
	/* set input for first 32 bits */
vector num1 {a32 a31 a30 a29 a28 a27 a26 a25 a24 a23 a22 a21 a20 a19 a18 a17 a16 a15 a14 a13 a12 a11 a10 a9 a8 a7 a6 a5 a4 a3 a2 a1}
vector num2 { b32 b31 b30 b29 b28 b27 b26 b25 b24 b23 b22 b21 b20 b19 b18 b17 b16 b15 b14 b13 b12 b11 b10 b9 b8 b7 b6 b5 b4 b3 b2 b1}
wave num1 bus {ffffffffh} pw=500
	/* adding ff to 0 */

*gridsize mos 18 30 8

wave num2 bus { 00d32  1d32 00d32} pw=80n on=5 off=0

plot {out1 out8 out16 out24 out32 cout32 }

transient 250n 
