	mvi a,03h
	mvi c,01h
	lxi h,0050h
loop:	mov m,c
	inx h
	inr c
	call delay
	cmp c
	jnc loop
	hlt
delay:	mov d,a
	lda 0040h
	mov e,a
loop2:	dcr e
	jnz loop2
	mov a,d
	ret
