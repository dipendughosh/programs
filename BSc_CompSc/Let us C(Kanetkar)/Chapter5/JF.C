//sinx=x-x^3/3!+x^5/5!-x^7/7!+...........+x^n/n!
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<process.h>

void main()
{       int b=2,i,j,m;
	double a=0,x,f,s,y,z,n;
	clrscr();
	printf("Enter value of x of sin x :- ");
	scanf("%lf",&x);
	printf("Enter value of n (number of decimal places):- ");
	scanf("%lf",&n);
	y=x;
	x=fabs(x);
	x=(x*3.141593)/180;
	s=x;
	for(i=3;i<=20;i+=2)
	{       f=1;
		for(j=1;j<=i;j++)
			f=f*j;
		a=pow(x,i);
		a=a/f;
		if(b%2==0)
			a=a*(-1);
		m=a;
		z=a-m;
		if(z<(1/pow(10,n)))
		{       printf("\n1/10^%lf=%lf",n,(1/pow(10,n)));
			break;
		}
		s=s+a;
		b++;
	}
	printf("\nSin %lf = %lf",y,s);
	getch();
}