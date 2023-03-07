#include<stdio.h>
#include<conio.h>

void main()
{       long int a,n,s=0;
	clrscr();
	printf("Enter a number n = ");
	scanf("%ld",&n);
	while(n>0)
	{	a=n%10;
		s=s+a;
		n=n/10;
	}
	printf("\nThe sum of digits is = %ld",s);
	getch();
}

