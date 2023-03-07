#include<stdio.h>
#include<conio.h>

void main()
{       int bin1(int);
	int n,b;
	clrscr();
	printf("Enter number - ");
	scanf("%d",&n);
	b=bin1(n);
	printf("%d",b);

	getch();
}
int bin1(int n)
{	int s=0,a;
	while(n>0)
	{	a=n%2;
		s=s+a;
		s=s*10;
		n=n/2;
	}
	printf("%d\n",s);
	return s;
}

