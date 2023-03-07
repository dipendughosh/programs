#include<stdio.h>
#include<conio.h>


void main()
{       int n;
	clrscr();
	printf("\nEnter n :- ");
	scanf("%d",&n);
	if((n&1)==0)
		printf("\nEven");
	else
		printf("\nOdd");
	getch();
}

