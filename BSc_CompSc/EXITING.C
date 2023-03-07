#include<stdio.h>
#include<conio.h>


void main()
{       int i;
	clrscr();
	printf("Exiting Program");
	for(i=0;i<10;i++)
	{
		delay(600);
		printf(".");
	}
	for(i=0;i<10;i++)
	{
		delay(600);
		printf("%c",16);
	}
	for(i=0;i<10;i++)
	{
		delay(600);
		printf(".");
	}

	getch();
}

