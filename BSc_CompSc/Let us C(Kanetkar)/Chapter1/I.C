#include<stdio.h>
#include<conio.h>

void main()
{       long int a,n,s=0;
	clrscr();
	printf("Enter a number n = ");
	scanf("%ld",&n);
	a=n%10;
	s=a;
	n=n/10;
	while(n>0)
	{	a=n%10;
		n=n/10;
	}
	s=s+a;
	printf("\nThe sum of digits is = %ld",s);
	getch();
}

