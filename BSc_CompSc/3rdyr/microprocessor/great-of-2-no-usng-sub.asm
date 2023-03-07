	lxi h,0050h
	mov b,m
	inx h
	mov c,m
	lxi sp,007fh
	call max
	mov a,d
	sta 0020h
	hlt
max:	push psw
	mov a,b
	cmp c
	jnc lbl
	mov a,c
lbl:	mov d,a
	pop psw
	ret