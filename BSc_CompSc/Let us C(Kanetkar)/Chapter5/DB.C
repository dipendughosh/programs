#include<stdio.h>
#include<conio.h>

void main()
{       int a,b,c;
	int power(int,int);
	clrscr();
	printf("Enter a - ");
	scanf("%d",&a);
	printf("Enter b - ");
	scanf("%d",&b);
	c=power(a,b);
	printf("c = %d",c);
	getch();
}

int power(int a,int b)
{	int i,c=1;
	for(i=0;i<b;i++)
		c*=a;
	return c;
}

