//area peri of rectangle
#include<stdio.h>
#include<conio.h>

void main()
{       int l,b,a,p;
	clrscr();
	printf("Enter Length - ");
	scanf("%d",&l);
	printf("Enter Breath - ");
	scanf("%d",&b);
	a=(l*b);
	p=2*(l+b);
	if(p>a)
		printf("\nPerimeter is greater");
	if(a>p)
		printf("\nArea is greater");

	getch();
}

