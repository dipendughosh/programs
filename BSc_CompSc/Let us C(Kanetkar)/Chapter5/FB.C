#include<stdio.h>
#include<conio.h>

int s,av,sd;
void main()
{       void fun(int,int,int,int,int);
	int a,b,c,d,e;
	clrscr();
	printf("Enter numbers\n");
	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);
	printf("c=");
	scanf("%d",&c);
	printf("d=");
	scanf("%d",&d);
	printf("e=");
	scanf("%d",&e);
	fun(a,b,c,d,e);
	printf("\nSum=%d",s);
	printf("\nAverage=%d",av);

	getch();
}

void fun(int a,int b,int c,int d,int e)
{       s=a+b+c+d+e;
	av=s/5;
}
