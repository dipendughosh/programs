	/* set input for first seven bits */
vector num1 { a8 a7 a6 a5 a4 a3 a2 a1}
wave num1 bus {ffh efh f0h f1h f2h f3h f4h f5h f6h f7h} ph=50n on=5 off=0
	/* adding ff to 0 */
vector num2 { b8 b7 b6 b5 b4 b3 b2 b1}

wave num2 bus { 10d8 } ph=500 on=5 off=0
	/* adding 111 to 001 now */
/* wave b1 piece { 0, 0.0 2n, 0.0 3n, 5.0 40n, 5.0 }*/

plot { out1 out2 out3 out4 out5 out6 out7 out8 cout8}

transient 550n powerup
