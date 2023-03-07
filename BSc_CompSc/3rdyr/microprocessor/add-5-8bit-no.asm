	lxi h,0050h
	mov b,m
	mvi a,00h
loop:	inx h
	add m
	dcr b
	jnz loop
	inx h
	mov m,a
	hlt
