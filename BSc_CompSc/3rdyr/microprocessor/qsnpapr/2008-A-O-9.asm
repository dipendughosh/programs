	LXI H,0050H
	MOV B,M
	LXI D,0080H
	MOV C,B
	INR B
LOOP1:	MOV A,M
	STAX D
	INX H
	INX D
	DCR B
	JNZ LOOP1
	DCX H
	LXI D,00A0H
	MOV A,C
	STAX D
	INX D
LOOP2:	MOV A,M
	STAX D
	DCX H
	INX D
	DCR C
	JNZ LOOP2
	HLT
