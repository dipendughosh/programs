//swap 2 nos using 3rd var, without 3rd var
#include<stdio.h>
#include<conio.h>

void main()
{	int a,b,c;
	clrscr();
	printf("Enter A = ");
	scanf("%d",&a);
	printf("Enter B = ");
	scanf("%d",&b);
	c=a;
	a=b;
	b=c;
	printf("\nA = %d\tB = %d",a,b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("\nA = %d\tB = %d",a,b);
	getch();
}

