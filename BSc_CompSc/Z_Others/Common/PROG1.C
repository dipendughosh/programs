#include<stdio.h>
#include<conio.h>

void main()
{	int x,y,sum,dif,mul;
	float div;
	clrscr();
	printf("Enter 1st number x = ");
	scanf("%d",&x);
	printf("Enter 2nd number y = ");
	scanf("%d",&y);
	sum=x+y;
	dif=x-y;
	mul=x*y;
	div=(float)x/y;
	printf("Sum = %d \nDif = %d \nMul = %d \nDiv = %f",sum,dif,mul,div);
	getch();
}

