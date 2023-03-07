	lxi h,0050h
	mov a,m
	inx h
	cmp m
	jnc lbl1
	mov a,m
lbl1:	inx h
	cmp m
	jnc lbl2
	mov a,m
lbl2:	inx h
	mov m,a
	hlt
