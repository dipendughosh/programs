	lxi h,0050h
	mov b,m
	inx h
	mov a,m
	add b
	inx h
	mvi m,00h
	jnc lbl
	inr m
lbl:	inx h
	mov m,a
	hlt


