#include<stdio.h>
#include<conio.h>

void main()
{       int n;
	clrscr();
	printf("Enter an integer ");
	scanf("%d",&n);
	if((n%2)==0)
		printf("\nEVEN");
	else
		printf("\nODD");

	getch();
}

