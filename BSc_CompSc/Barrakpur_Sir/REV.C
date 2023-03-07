//reverse number
#include<stdio.h>
#include<conio.h>


void main()
{       int n,s=0,a;
	clrscr();
	printf("Enter number ");
	scanf("%ld",&n);
	while(n>0)
	{	a=n%10;
		s=s*10;
		s=s+a;
		n=n/10;
	}
	printf("\nReverse = %d",s);
	getch();
}

