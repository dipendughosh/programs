	MVI E,00H
	mvi d,00h
	LHLD 0070H
	MOV A,H
	STA 0080H
	MOV A,L
	STA 0081H
	LDA 0072H
	MOV B,A
LOOP 	MVI C,00H
	LDA 0080H
	CPI 00H
	JZ LBL1
	LDA 0081H
	SUB B
	JC LBL2
	mov a,e
	adi 01h
	mov e,a
	jnc lbl5
	inr d
lbl5:	STA 0081H
	JMP loop
LBL2	INR C
	mov a,e
	adi 01h
	mov e,a
	jnc lbl6
	inr d
lbl6:	STA 0081H
	LDA 0080H
	SUB C
	sta 0080h
	Jmp LOOP
LBL1	lda 0081h
loop2	CMP B
	JC LBL4
	jz lbl4
	inr e
	SUB B
	Jmp LOOP2
LBL4	STA 0074H
	mov a,e
	STA 0073H
	mov a,d
	sta 0075h
	HLT



