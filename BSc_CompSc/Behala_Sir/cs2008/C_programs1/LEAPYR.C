/* Check a leap year or not */

#include<stdio.h>
#include<conio.h>

void main()
{
	int yr,r,cyr;
	clrscr();
	printf("\n\tEnter the year : ");
	scanf("%d",&yr);
	cyr=yr%100;   //centurial year
((cyr==0)?(r=yr%400):(r=yr%4));
((r==0)?printf("\n\tThe year entered by you is a leap year."):printf("\n\tThe year entered by you is not a leap year."));
	getch();
}