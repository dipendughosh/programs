	LXI H,0050H
	MVI B,08H
	MOV D,M
LOOP:	MOV A,D
	RAL
	MOV D,A
	MOV A,C
	RAR
	MOV C,A
	DCR B
	JNZ LOOP
	MOV D,M
	MOV A,C
	CMP D
	JNZ LBL
	INX H
	MOV M,C
LBL:	HLT
