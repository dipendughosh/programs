#include<stdio.h>
#include<conio.h>

void main()
{	int c,d;
	clrscr();
	printf("Enter a number C = ");
	scanf("%d",&c);
	printf("Enter a number D = ");
	scanf("%d",&d);
	c=c+d;
	d=c-d;
	c=c-d;
	printf("C = %d\nD = %d",c,d);
	getch();
}
