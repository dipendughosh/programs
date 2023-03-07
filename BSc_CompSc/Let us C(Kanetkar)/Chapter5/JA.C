#include<stdio.h>
#include<conio.h>

void main()
{       int sum(int);
	int n;
	clrscr();
	printf("Enter number - ");
	scanf("%d",&n);
	n=sum(n);
	printf("\nSum of digits = %d",n);
	getch();
}
int sum(int n)
{       int s=0,a;
	while(n!=0)
	{	a=n%10;
		n/=10;
		s=s+a;
	}
	return s;
}

