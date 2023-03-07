	lxi h,0050h
	mov b,m
	lxi d,0060h
loop:	inx h
	inx d
	mov a,m
	stax d
	dcr b
	jnz loop
	hlt


