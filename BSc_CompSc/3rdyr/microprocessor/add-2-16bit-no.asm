	LHLD 0050H
	XCHG
	LHLD 0052H
	DAD D
	SHLD 0054H
	MVI A,00H
	JNC LBL
	INR A
LBL:	STA 0056H
	HLT
