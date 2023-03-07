#include<stdio.h>
#include<conio.h>


void main()
{       int a,b,c;
	clrscr();
	printf("Enter a:-");
	scanf("%d",&a);
	printf("Enter b:-");
	scanf("%d",&b);
	printf("Enter c:-");
	scanf("%d",&c);
	if(a>b && a>c)
		printf("%d is Greatest",a);
	else if(b>a && b>c)
		printf("%d is Greatest",b);
	else if(c>b && c>a)
		printf("%d is Greatest",c);
	printf("\n");
	if(a<b && a<c)
		printf("%d is Smallest",a);
	else if(b<a && b<c)
		printf("%d is Smallest",b);
	else if(c<b && c<a)
		printf("%d is Smallest",c);
	getch();
}

