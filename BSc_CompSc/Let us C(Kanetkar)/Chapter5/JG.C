#include<stdio.h>
#include<conio.h>

void main()
{       void circulate(int *,int *,int *);
	int x,y,z,*a,*b,*c;
	clrscr();
	printf("Enter x - ");
	scanf("%d",&x);
	printf("Enter y - ");
	scanf("%d",&y);
	printf("Enter z - ");
	scanf("%d",&z);
	a=&x;
	b=&y;
	c=&z;
	circulate(a,b,c);
	printf("x = %d \ny = %d \nz = %d",x,y,z);
	getch();
}
void circulate(int *a,int *b,int *c)
{	int t;
	t=*a;
	*a=*b;
	*b=*c;
	*c=t;
}

