#include<stdio.h>
#include<conio.h>

void main()
{	int l,b,ar,pr;
	clrscr();
	printf("Enter Lenght of Rectangle l = ");
	scanf("%dl",&l);
	printf("Enter Breadth of Rectangle b = ");
	scanf("%d",&b);
	ar=l*b;
	pr=2*(l+b);
	if(ar>pr)
		printf("\nArea is greater than Perimeter");
	else
		printf("\nArea is not greater than Perimeter");
	getch();
}

