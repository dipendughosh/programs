#include<stdio.h>
#include<conio.h>

void main()
{       int y,x;
	int leap(int);
	clrscr();
	printf("Enter year -: ");
	scanf("%d",&y);
	x=leap(y);
	if(x==1)
		printf("\nLeap");
	if(x==0)
		printf("\nNot Leap");
	getch();
}
int leap(int y)
{       int x;
	if(y%100 == 0)
	{	if(y%400 == 0)
			x=1;
		else
			x=0;
	}
	else
	{	if(y%4 == 0)
			x=1;
		else
			x=0;
	}
	return x;
}

