	LXI H,0090H
	MOV B,M
	INX H
	XRA A
	MOV C,A
LOOP:	ADD M
	JNC LBL
	INR C
LBL:	DCR B
	JNZ LOOP
	INX H
	STA 00A0H
	STA 00B0H
	MOV A,C
	STA 00A1H
	STA 00B1H
	XRA A
	MOV D,A
	MOV B,A
LOOP1:	MVI C,00H
	LDA 00A1H
	CPI 00H
	JZ LBL1
	MOV A,B
	ADI 01H
	MOV B,A
	JNC LBL2
	INR D
LBL2:	LDA 00A0H
	SUB M
	STA 00A0H
	JNC LBL9
	INR C
	LDA 00A1H
	SUB C
	STA 00A1H
LBL9:	JMP LOOP1
LBL1:	LDA 00A0H
	CMP M
	JC LBL3
	MOV A,B
	ADI 01H
	MOV B,A
	JNC LBL4
	INR D
LBL4:	LDA 00A0H
	SUB M
	STA 00A0H
	JNZ LBL1
LBL3:	INX H
	MOV M,A
	INX H
	MOV M,B
	INX H
	MOV M,D
	HLT
