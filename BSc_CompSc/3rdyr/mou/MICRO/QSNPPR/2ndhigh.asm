	LXI H,0050H
	MOV B,M
	INX H
	MOV A,M
	DCR B
LOOP	INX H
	MOV C,M
	CMP C
	JZ LBL
	JNC LBL
	MOV A,C
LBL	DCR B
	JNZ LOOP
	MOV B,A
	LXI H,0050H
	MOV E,M
	INX H
	MOV C,M
	DCR E
	mov a,c
	cmp b
	jnz loop2
	mov a,m
	inx h
	dcr e
LOOP2	INX H
	MOV A,M
	CMP B
	JZ LBL1
	CMP C
	JZ LBL1
	JC LBL1
	MOV C,A
LBL1	DCR E
	JNZ LOOP2
	INX H
	MOV M,C
	HLT
