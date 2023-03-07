//x^n
#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{       float exp1(int,int);
	int x,n;
	clrscr();
	printf("\nEnter number - ");
	scanf("%d",&x);
	printf("\nEnter power - ");
	scanf("%d",&n);
	if(n>=0)
		printf("%d^%d = %f",x,n,exp1(x,n));
	else
		printf("%d^%d = %f",x,n,(1/exp1(x,fabs(n))));
	getch();

}

float exp1(int x,int n)
{	if(n==1)
		return(x);
	else
		return(x*exp1(x,n-1));
}

