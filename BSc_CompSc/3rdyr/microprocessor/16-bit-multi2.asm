	LHLD 0060H
	MVI A,00H
	STA 0064H
	STA 0065H
	MOV B,A
	MOV C,A
	MOV D,A
	MOV E,A
LOOP:	MVI C,00H
	LDA 0064H
	MOV B,A
	LDA 0062H
	ADD B
	STA 0064H
	JNC LBL1
	INR C
LBL1:	LDA 0065H
	MOV B,A
	LDA 0063H
	ADD B
	STA 0065H
	JNC LBL2
	MOV A,E
	ADI 01H
	MOV E,A
	JNC LBL2
	INR D
LBL2:	LDA 0065H
	ADD C
	STA 0065H
	JNC LBL3
	MOV A,E
	ADI 01H
	MOV E,A
	JNC LBL3
	INR D
LBL3:	DCX H
	MOV A,H
	ORA L
	JNZ LOOP
	MOV A,E
	STA 0066H
	MOV A,D
	STA 0067H
	HLT




