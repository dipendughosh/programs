	lxi h,0050h
	mov b,m
	inx h
	mov a,m
loop:	inx h
	cmp m
	jnc lbl
	jz lbl
	mov a,m
lbl:	dcr b
	jnz loop
	mov m,a
	hlt
