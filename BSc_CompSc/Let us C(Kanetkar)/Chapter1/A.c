#include<conio.h>
#include<stdio.h>

void main()
{       float bas,da,hra,gs;
	clrscr();
	printf("Enter Basic Salary ");
	scanf("%f",&bas);
	da=bas*.4;
	hra=bas*.2;
	gs=bas+hra+da;
	printf("\nGross salary = Rs.%f",gs);
	getch();
}
