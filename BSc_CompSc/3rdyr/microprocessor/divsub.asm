	LXI H,0050H
	MOV B,M
	INX H
	MOV C,M
	LXI SP,007FH
	CALL DIV
	HLT
DIV:	PUSH PSW
	MVI E,00H
	MOV A,B
LOOP:	CMP C
	JC LBL
	INR E
	SUB C
	JNC LOOP
LBL:	MOV D,A
	POP PSW
	RET



