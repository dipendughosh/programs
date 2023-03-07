#include<stdio.h>
#include<conio.h>

void main()
{       float *x,y=6;
	clrscr();
	x=&y;
	printf("\n*x=%f",*x);
	printf("\ny=%f",y);
	printf("\nx=%u",x);
	printf("\n&y=%u",&y);
	printf("\n&x=%u",&x);

	getch();
}

