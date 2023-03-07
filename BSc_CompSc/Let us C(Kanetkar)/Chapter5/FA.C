#include<stdio.h>
#include<conio.h>

void main()
{       float pro(int,float);
	int a;
	float b,c;
	clrscr();
	printf("Enter number a - ");
	scanf("%d",&a);
	printf("Enter number b - ");
	scanf("%f",&b);
	c=pro(a,b);
	printf("c=%f",c);
	getch();
}
float pro(int a,float b)
{	float c;
	c=a*b;
	return c;
}

