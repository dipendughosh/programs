	MVI B,23H
	MVI A,35H
	ANA B
	STA 0100H
	MVI A,4BH
	MOV B,A
	LDA 0100H
	ORA B
	STA 0105H
	MOV B,A
	LDA 0100H
	XRA B
	STA 0200H
	HLT

