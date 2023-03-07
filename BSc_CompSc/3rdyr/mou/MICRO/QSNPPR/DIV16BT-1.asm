	MVI E,00H
	LHLD 0070H
	MOV A,H
	STA 0080H
	MOV A,L
	STA 0081H
	LDA 0072H
	MOV B,A
	mvi d,00h
LOOP 	MVI C,00H
	LDA 0080H
	CPI 00H
	JZ LBL1
	LDA 0081H
	SUB B
	JC LBL2
	sta 0081h
	mov a,e
	adi 01h
	mov e,a
	jnc lbl7
	inr d
lbl7:	JMP Loop
LBL2	INR C
	STA 0081H
	mov a,e
	adi 01h
	mov e,a
	jnc lbl5
	inr d
lbl5:	LDA 0080H
	SUB C
	sta 0080h
	Jmp LOOP
LBL1	lda 0081h
	CMP B
	JC LBL4
	mov a,e
	adi 01h
	mov e,a
	jnc lbl8
	inr d
lbl8:	lda 0081h
	SUB B
	sta 0081h
	JNZ lbl1
LBL4	STA 0073H
	MOV A,E
	STA 0074H
	mov a,d
	sta 0075h
	HLT



