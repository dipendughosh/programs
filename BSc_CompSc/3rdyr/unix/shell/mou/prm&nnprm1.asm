	LXI H,0090H
	LXI B,00A0H
	LXI D,00B0H
	LXI SP,00FFH
	MVI A,00H
	STAX B
	STAX D
	MOV A,M
	STA 0080H
	INX H
	INX B
	INX D
LOOP	CALL PRIME
	INX H
	LDA 0040H
	DCR A
	STA 0040H
	JNZ LOOP
	HLT
PRIME	PUSH PSW
	PUSH B
	PUSH D
	MOV B,M
	MVI E,00H
LOOP1	MOV A,M
LOOP2	CMP B
	JC LBL1
	SUB B
	JNZ LOOP2
LBL1	CPI 00H
	JNZ LBL2
	INR E
LBL2	DCR B
	JNZ LOOP1
	MVI D,00H
	MVI A,02H
	CMP E
	JNZ LBL3
	MVI D,01H
LBL3	MOV A,D
	ANA A
	JZ LBL4
	INR B
	MOV A,M
	STAX B
	INX B
	JMP LBL5
LBL4	INR D
	MOV A,M
	STAX D
	INX D
LBL5	POP D
	POP B
	POP PSW
	RET



