	lxi h,0050h
	xra a
	mvi b,05h
	mov c,a
loop:	add m
	daa
	jnc lbl
	inr c
lbl:	inx h
	dcr b
	jnz loop
	mvi b,00h
	add a
	daa
	jnc lbl2
	inr b
lbl2:	sta 0060h
	mov a,c
	add c
	add b
lbl3:	sta 0061h
	hlt

