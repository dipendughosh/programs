#include<stdio.h>
#include<conio.h>

void main()
{       void fibo(int);
	int n;
	clrscr();
	printf("Enter limit - ");
	scanf("%d",&n);
	fibo(n);
	getch();
}
void fibo(int n)
{	int i,a=1,b=1,c=0;
	printf("%d\t%d\t",a,b);
	for(i=0;i<n-2;i++)
	{	c=a+b;
		printf("%d\t",c);
		a=b;
		b=c;
	}
}


