//factorial of a number
#include<stdio.h>
#include<conio.h>


void main()
{       unsigned long int fact(int);
	int n;
	clrscr();
	printf("\nEnter number to find its factorial - ");
	scanf("%d",&n);
	if(n<=0)
		printf("\nFactorial is 1");
	else
		printf("\nFactorial is %lu",fact(n));
	getch();
}
unsigned long int fact(int n)
{	if(n<=0)
		return(1);
	else return(n*fact(n-1));
}

