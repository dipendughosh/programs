BEGIN {
	VDD = XXX
	VLT = VDD/2.0
	START = 0
	TLH = 1
	TIME = 0
	printf("VDD = %g\n", VDD)
}

START == 1 {
	if (TLH == 1 && TIME == 0 && $3 <= VLT) {
		TIME = $1
	}
	if (TLH == 1 && TIME != 0 && $4 >= VLT) {
		TLH = 0
		TIME = ($1 - TIME)*1.0e+12
		printf("\tLow to High: %g psec\n",TIME)
		TIME = 0
	}
	if (TLH == 0 && TIME == 0 && $3 >= VLT) {
		TIME = $1
	}
	if (TLH == 0 && TIME != 0 && $4 <= VLT) {
		TLH = 2
		TIME = ($1 - TIME)*1.0e+12
		printf("\tHigh to Low: %g psec\n",TIME)
		TIME = 0
	}
}

$1 == "Time" {
	START=1
}
