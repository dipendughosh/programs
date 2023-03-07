#include<stdio.h>
#include<conio.h>

void main()
{	long int a,n,n1,s=0;
	clrscr();
	printf("Enter a number n = ");
	scanf("%ld",&n1);
	n=n1;
	while(n>0)
	{	a=n%10;
		s=(s*10)+a;
		n=n/10;
	}
	if(s==n1)
		printf("\nYes");
	else
		printf("\nNo");
	getch();
}

