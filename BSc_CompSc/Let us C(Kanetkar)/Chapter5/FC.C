#include<stdio.h>
#include<conio.h>
float s,av,sd;
void main()
{       void fun(int,int,int);
	int a,b,c;
	clrscr();
	printf("Enter numbers\n");
	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);
	printf("c=");
	scanf("%d",&c);
	fun(a,b,c);
	printf("\nSum=%f",s);
	printf("\nAverage=%f",av);

	getch();
}

void fun(int a,int b,int c)
{       s=a+b+c;
	av=s/3;
}

