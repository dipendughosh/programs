#include<stdio.h>
#include<conio.h>

void main()
{	int x,y;
	clrscr();
	printf("Enter O(x,y) ");
	printf("\nEnter x ");
	scanf("%d",&x);
	printf("\nEnter y ");
	scanf("%d",&y);
	if(x==0 && y==0)
		printf("\nOn the origin");
	else if(x==0)
		printf("\nOn the y-axis");
	else if(y==0)
		printf("\nOn the x-axis");
	else
		printf("\nNot on any");
	getch();
}

