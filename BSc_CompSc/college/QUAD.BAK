//roots of an quad eq
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{       float a,b,c,d,x1,x2;
	clrscr();
	printf("Ax^2+Bx+C\n");
	printf("Enter A = ");
	scanf("%f",&a);
	printf("Enter B = ");
	scanf("%f",&b);
	printf("Enter C = ");
	scanf("%f",&c);
	d=(b*b)-(4*a*c);
	if(d<0)
	{	d=(-1*d);
		x1=b/(2*a);
		x2=pow(d,(1/2))/(2*a);
		printf("\nRoots are Imaginary\nx1 = %f + i%f\tx2 = %f - i%f",(-1*x1),x2,(-1*x1),x2);
		d=(-1*d);
	}
	if(d>0)
	{	x1=(b-pow(d,(1/2)))/(2*a);
		x2=(b+pow(d,(1/2)))/(2*a);
		printf("\nRoots are Real\nx1 = %f\tx2 = %f",(-1*x1),(-1*x2));
	}
	if(d==0)
	{	x1=b/(2*a);
		printf("\nRoots are Real and Equal x1 = x2 = %f",(-1*x1));
	}
	getch();
}

