	LXI H,0050H
	LXI D,0090H
	MVI B,30H
	MVI C,39H
LOOP:	MOV A,M
	CPI 01H
	JZ BREAK
	CMP B
	JC LBL1
	CMP C
	JNC LBL1
	JZ LBL1
	STAX D
	INX D
LBL1:	XRA C
	JNZ LBL2
	MOV A,C
	STAX D
	INX D
LBL2:	INX H
	JMP LOOP
BREAK:	HLT


