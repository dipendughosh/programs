#include<stdio.h>
#include<conio.h>


void main()
{       int x,y;
	clrscr();
	printf("Enter x :- ");
	scanf("%d",&x);
	printf("Enter y :- ");
	scanf("%d",&y);
	x=x^y;
	y=x^y;
	x=x^y;
	printf("\nx = %d\ny = %d",x,y);

	getch();
}

