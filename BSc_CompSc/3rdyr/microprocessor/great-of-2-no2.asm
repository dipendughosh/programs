	lxi h,0050h
	mov a,m
	inx h
	cmp m
	jnc lbl
	mov a,m
lbl:	inx h
	mov m,a
	hlt
