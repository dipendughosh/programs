#include<stdio.h>
#include<conio.h>

void main()
{	int m1,m2,m3,m4,m5;
	float per,agg;
	clrscr();
	printf("Enter marks of 1st subject ");
	scanf("%d",&m1);
	printf("Enter marks of 2nd subject ");
	scanf("%d",&m2);
	printf("Enter marks of 3rd subject ");
	scanf("%d",&m3);
	printf("Enter marks of 4th subject ");
	scanf("%d",&m4);
	printf("Enter marks of 5th subject ");
	scanf("%d",&m5);
	agg=m1+m2+m3+m4+m5;
	per=agg/5;
	printf("\nPercentage = %f \nTotal = %f ",per,agg);
	getch();
}