//gcd
#include<stdio.h>
#include<conio.h>


void main()
{       int x,y;
	int gcd(int,int);
	clrscr();
	printf("\nEnter numbers to find their GCD : ");
	printf("\nEnter x: ");
	scanf("%d",&x);
	printf("\nEnter y: ");
	scanf("%d",&y);
	while(x!=y)
	{	if(x>y)
			x=x-y;
		else if(y>x)
			y=y-x;
	}
	printf("\nGCD=%d",x);
	printf("\nGCD using recursion =%d",gcd(x,y));
	getch();
}

int gcd(int m,int n)
{	if(n==0)
		return(m);
	else
		return(gcd(n,(m%n)));
}