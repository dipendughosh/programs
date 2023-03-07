#include<stdio.h>
#include<conio.h>

void main()
{       int n=20,u;
	clrscr();
	printf("Pick sticks not more than 4");
	do
	{	printf("\nPick sticks - ");
		scanf("%d",&u);
		n-=u-1;
		printf("Computer picked - %d\nSticks left - %d",5-u,n);
	}while(n!=0);
	printf("You loose!!!");
	getch();
}

