	LDA 0050H
	MVI B,00H
	MVI C,64H
LOOP:	CMP C
	JC LBL
	INR B
	SUB C
	JNZ LOOP
	ANA A
	JZ LBL2
LBL:	MVI C,0AH
	MVI D,00H
LOOP2:	CMP C
	JC LBL2
	INR D
	SUB C
	JNZ LOOP2
LBL2:	MOV C,A
	MOV A,D
	RLC
	RLC
	RLC
	RLC
	ORA C
	STA 0052H
	MOV A,B
	STA 0051H
	HLT
