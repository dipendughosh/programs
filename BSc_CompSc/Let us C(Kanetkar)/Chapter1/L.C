#include<stdio.h>
#include<conio.h>

void main()
{       float sp,tp,mp;
	clrscr();
	printf("Enter selling price of 15 items = ");
	scanf("%f",&sp);
	printf("Enter profit of 15 items = ");
	scanf("%f",&tp);
	mp=(sp-tp)/15;
	printf("\nCP of each is = %f",mp);
	getch();
}

