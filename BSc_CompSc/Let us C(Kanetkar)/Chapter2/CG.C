#include<stdio.h>
#include<conio.h>

void main()
{       int a,b,c,s;
	clrscr();
	printf("Enter Angle A of Triangle ");
	scanf("%d",&a);
	printf("Enter Angle B of Triangle ");
	scanf("%d",&b);
	printf("Enter Angle C of Triangle ");
	scanf("%d",&c);
	s=a+b+c;
	if(s==180)
		printf("\nYes a Triangle");
	else
		printf("\nNo not a Valid Triangle");
	getch();
}

