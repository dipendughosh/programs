BEGIN {
	VDD = 6.0
	VLT = VDD/2.0
	START = 0
	TLH = 1
	printf("VDD = %g\n", VDD)
	time = 0
	x1 = 0
	y1 = 0
}

START == 1 {
	if (TLH == 1 && time == 0 && $3 <= VLT) {
		x2 = $1*1.0e+12
		y2 = $3
		dx = x2 - x1
		dy = y2 - y1
		b = y1 - x1 * (dy/dx)
		time = (VLT - b)*(dx/dy)
	}
	if (TLH == 1 && time != 0 && $4 >= VLT) {
		x2 = $1*1.0e+12
		y2 = $4
		dx = x2 - x1
		dy = y2 - y1
		b = y1 - x1 * (dy/dx)
		time = (VLT - b)*(dx/dy) - time
		printf("\tLow to High: %g psec\n",time)
		TLH = 0
		time = 0
	}
	if (TLH == 0 && time == 0 && $3 >= VLT) {
		x2 = $1*1.0e+12
		y2 = $3
		dx = x2 - x1
		dy = y2 - y1
		b = y1 - x1 * (dy/dx)
		time = (VLT - b)*(dx/dy)
	}
	if (TLH == 0 && time != 0 && $4 <= VLT) {
		x2 = $1*1.0e+12
		y2 = $4
		dx = x2 - x1
		dy = y2 - y1
		b = y1 - x1 * (dy/dx)
		time = (VLT - b)*(dx/dy) - time
		printf("\tHigh to Low: %g psec\n",time)
		TLH = 2
		time = 0
	}
	x1 = $1*1.0e+12
	if (time == 0)
		y1 = $3
	else
		y1 = $4
}

$1 == "Time" {
	START=1
}
