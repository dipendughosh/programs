#include<stdio.h>
#include<conio.h>


void main()
{       int x,y;
	clrscr();
	printf("\nEnter x:- ");
	scanf("%d",&x);
	printf("\nEnter y:- ");
	scanf("%d",&y);
	printf("\nGCD of %d,%d is ",x,y);
	while(x!=y)
	{	if(x>y)
			x=x-y;
		else if(y>x)
			y=y-x;
	}
	printf("%d",x);

	getch();
}

