#include<stdio.h>
#include<conio.h>


void main()
{       int x,y,z;
	clrscr();
	x=5;
	y=6;
	z=~x;
	printf("\n~x=%d",z);
	z=~y;
	printf("\n~y=%d",z);
	z=x>>1;
	printf("\nx>>1=%d",z);
	z=y>>1;
	printf("\ny>>1=%d",z);
	z=x&y;
	printf("\nx&y=%d",z);
	z=x|y;
	printf("\nx|y=%d",z);
	z=x^y;
	printf("\nx^y=%d",z);


	getch();
}

