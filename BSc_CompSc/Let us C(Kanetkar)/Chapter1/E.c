#include<stdio.h>
#include<conio.h>

void main()
{	int l,b,ar,pr;
	float ac,pc,r;
	clrscr();
	printf("Enter Lenght of Rectangle l = ");
	scanf("%dl",&l);
	printf("Enter Breadth of Rectangle b = ");
	scanf("%d",&b);
	printf("Enter Radius of Circle r = ");
	scanf("%f",&r);
	ar=l*b;
	pr=2*(l+b);
	ac=r*r*22/7;
	pc=r*2*22/7;
	printf("\nArea of Rectangle = %d \nPerimeter of Rectangle = %d \nArea of Circle = %f \nPerimeter of Circle = %f ",ar,pr,ac,pc);
	getch();
}

