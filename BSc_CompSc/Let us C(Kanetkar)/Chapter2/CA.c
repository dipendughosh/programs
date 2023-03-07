#include<stdio.h>
#include<conio.h>

void main()
{	int cp,sp,pro,los;
	clrscr();
	printf("Enter cost price of an item ");
	scanf("%d",&cp);
	printf("Enter selling price of an item ");
	scanf("%d",&sp);
	if(cp<sp)
		printf("\nMade Profit of Rs.%d",sp-cp);
	else
		printf("\nMade Loss of Rs.%d",cp-sp);
	getch();
}

