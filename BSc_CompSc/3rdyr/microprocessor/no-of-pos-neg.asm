	LXI H,0050H
	MOV B,M
	MVI D,00H
	MOV E,D
LOOP:	INX H
	MOV A,M
	RAL
	JNC LBL1
	INR D
	JMP LBL2
LBL1:	INR E
LBL2:	DCR B
	JNZ LOOP
	INX H
	MOV M,D
	INX H
	MOV M,E
	HLT
