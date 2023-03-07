#include<stdio.h>
#include<conio.h>

void main()
{	float km,m,f,i,c;
	clrscr();
	printf("Enter Distance between 2 cities in km=");
	scanf("%f",&km);
	m=km*1000;
	c=m*100;
	f=c/30.48;
	i=f*12;
	printf("\nKm = %f\nM = %f\nF= %f\nI = %f\nC = %f",km,m,f,i,c);
	getch();
}