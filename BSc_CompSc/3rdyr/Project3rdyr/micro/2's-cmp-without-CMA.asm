	LXI H,0050H
	MVI B,08H
	MOV C,M
LOOP:	MOV A,C
	RAL
	MOV C,A
	MOV A,D
	JNC LBL1
	ORA A
	RAL
	JMP LBL2
LBL1:	STC
	RAL
LBL2:	MOV D,A
	DCR B
	JNZ LOOP
	MOV A,D
	INR A
	INX H
	MOV M,A
	HLT

