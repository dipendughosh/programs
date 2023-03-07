#include<stdio.h>
#include<conio.h>

void main()
{	float da=0,fine=0,a=0,b=0;
	clrscr();
	printf("Enter the number of days U are late to return the book :- ");
	scanf("%f",&da);
	if(da<=5)
		fine=(.5*da);
	else if(da>5 && da<=10)
	{	fine=(da-5);
		a=.5*5;
		fine=fine+a;
	}
	else if(da>10 && da<=30)
	{	fine=(da-5);
		a=5*.5;
		b=da-10;
		b=b*5;
		fine=fine+a+b;
	}
	else if(da>30)
	{	printf("\nUR Membership has been cancelled");
		getch();
		exit(0);
	}
	printf("\nFine = Rs.%f",fine);
	getch();
}

