	LXI H,0050H
	MVI E,00H
	MVI D,00H
	MVI C,0AH
LOOP	MOV A,M
	RAR
	JC LBL1
	RAL
	ADD D
	JNC LBL2
	INR E
LBL2	MOV D,A
LBL1	INX H
	DCR C
	JNZ LOOP
	MOV A,D
	CMA
	STA 0061H
	MOV A,E
	CMA
	STA 0060H
	HLT
