	LXI D,0071H
	LXI H,0050H
	MOV B,M
loop1	INX H
	MOV A,M
	STAX D
	INX D
	DCR B
	JNZ LOOP1
	LXI H,0060H
	MOV B,M
LOOP2	INX H
	MOV A,M
	STAX D
	INX D
	DCR B
	JNZ LOOP2
	LXI H,0050H
	MOV A,M
	LXI H,0060H
	ADD M
	LXI H,0070H
	MOV M,A
	MOV B,A
LOOP4	INX H
	MOV C,b
	MOV D,H
	MOV E,L
LOOP3	LDAX D
	CMP M
	JNC LBL1
	STA 0100H
	MOV A,M
	STAX D
	LDA 0100H
	MOV M,A
LBL1	INX D
	DCR C
	JNZ LOOP3
	DCR B
	JNZ LOOP4
	HLT





