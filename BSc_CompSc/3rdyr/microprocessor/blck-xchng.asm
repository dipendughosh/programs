	lxi h,0050h
	mov b,m
	lxi d,0060h
loop:	inx h
	inx d
	mov a,m
	sta 0070h
	ldax d
	mov m,a
	lda 0070h
	stax d
	dcr b
	jnz loop
	hlt

