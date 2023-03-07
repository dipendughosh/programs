#include<stdio.h>
#include<conio.h>


void main()
{       int fun(int);
	int n=11;
	clrscr();
	printf("%d",fun(n));
	getch();
}

int fun(int n)
{	if((n/2)!=0)
		return(fun(n/2)*10+n%2);
	else
		return(1);
}