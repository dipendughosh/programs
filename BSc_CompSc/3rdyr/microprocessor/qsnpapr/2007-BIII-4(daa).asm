	lxi h,0050h
	mvi b,04h
	xra a
	mov c,a
loop:	add m
	daa
	jnc lbl
	inr c
lbl:	inx h
	dcr b
	jnz loop
	mvi d,00h
	mov b,a
	add b
	daa
	jnc lbl1
	inr d
lbl1:	add b
	daa
	jnc lbl2
	inr d
lbl2:	sta 0060h
	mov a,c
	add c
	daa
	add c
	daa
	add d
	daa
	sta 0061h
	hlt
