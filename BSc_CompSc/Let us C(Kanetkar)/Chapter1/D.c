#include<stdio.h>
#include<conio.h>

void main()
{	float a,b;
	clrscr();
	printf("Enter temperature in fahrenheit ");
	scanf("%f",&a);
	b=(a*9/5)+32;
	printf("\nTemp in centigrade = %f",b);
	getch();
}