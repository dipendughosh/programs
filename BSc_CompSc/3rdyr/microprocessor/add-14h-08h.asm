	lxi h,0050h
	mov a,m
	mov b,a
	add a
	mov c,a
	add a
	add c
	add b
	mov b,a
	mov a,m
	rrc
	add b
	mov b,a
	inx h
	mov a,m
	mov c,a
	add a
	add a
	add c
	mov c,a
	mov a,m
	rrc
	rrc
	add c
	add b
	inx h
	mov m,a
	hlt
