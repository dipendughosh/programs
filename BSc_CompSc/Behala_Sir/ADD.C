#include<stdio.h>
#include<conio.h>

void main()
{       int add(int,int);
	int x,y,z;
	clrscr();
	printf("Enter x ");
	scanf("%d",&x);
	printf("Enter y ");
	scanf("%d",&y);
	z=add(x,y);
	printf("\nx+y=%d",z);
	getch();
}
int add(int a,int b)
{	int c;
	c=a+b;
	return c;
}

