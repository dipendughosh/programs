#include<stdio.h>
#include<conio.h>

void main()
{       int y;
	clrscr();
	printf("Enter year -: ");
	scanf("%d",&y);
	if( y%100 == 0 )
	{	if( y%400 == 0 )
			printf("\nLeap");
		else
			printf("\nNot Leap");
	}
	else
	{	if( y%4 == 0 )
			printf("\nLeap");
		else
			printf("\nNot Leap");
	}
	getch();
}

