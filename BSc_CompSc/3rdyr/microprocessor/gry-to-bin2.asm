	MVI E,80H
	MVI B,00H
	LDA 0050H
	MOV D,A
	MVI C,00H
LOOP:	MOV A,D
	XRA C
	ANA E
	ORA B
	MOV B,A
	RRC
	MOV C,A
	ANA A
	MOV A,E
	RAR
	MOV E,A
	ANA A
	JNZ LOOP
	MOV A,B
	STA 0051H
	HLT
