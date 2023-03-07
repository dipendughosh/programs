	LXI H,00c0H
	LXI D,00d0H
	MVI A,05H
	STA 00f0H
LOOP1:	MOV A,M
	ANI 0F0H
	RRC
	RRC
	RRC
	RRC
	MOV B,A
	MVI C,01H
LOOP:	ADD B
	DCR C
	JNZ LOOP
	MOV B,A
	MOV A,M
	ANI 0FH
	ADD B
	STAX D
	INX D
	INX H
	LDA 00f0H
	DCR A
	STA 00f0H
	JNZ LOOP1
	LXI H,00d0H
	MVI B,05H
	XRA A
	MOV C,A
LOOP2:	ADD M
	JNC LBL
	INR C
LBL:	INX H
	DCR B
	JNZ LOOP2
	MOV H,C
	MOV L,A
	XRA A
	DAD H
	JNC LBL1
	INR A
LBL1:	STA 00e2H
	mvi b,64h
	mvi c,00h
	mov a,l
loop3:	cmp b
	jc lbl2
	inr c
	sub b
	jnz loop3
lbl2:	sta 0010h
	mov a,c
	sta 0011h
	mvi b,0ah
	mvi c,00h
	lda 0010h
loop4:	cmp b
	jc lbl3
	inr c
	sub b
	jnz loop4
lbl3:	mov b,a
	mov a,c
	rlc
	rlc
	rlc
	rlc
	ora b
	mov l,a
	mvi b,64h
	mvi c,00h
	mov a,h
loop5:	cmp b
	jc lbl4
	inr c
	sub b
	jnz loop5
lbl4:	sta 0012h
	mov a,c
	sta 0013h
	mvi b,0ah
	mvi c,00h
	lda 0012h
loopd:	cmp b
	jc lbl5
	inr c
	sub b
	jnz loopd
lbl5:	mov b,a
	mov a,c
	rlc
	rlc
	rlc
	rlc
	ora b
	mvi b,00h
	mov c,a
	lda 0011h
	add c
	jnc lbld
	inr b
lbld:	mov h,a
	lda 00e2h
	add b
	sta 00e2h
	shld 00e0h
	HLT
