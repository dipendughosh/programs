//sinx=x-x^3/3!+x^5/5!-x^7/7!+...........+x^n/n!(done)
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<process.h>

void main()
{       int b=2,i,j,n;
	double a=0,x,f,s,y;
	clrscr();
	printf("Enter value of x of sin x :- ");
	scanf("%lf",&x);
	printf("Enter value of n :- ");
	scanf("%d",&n);
	y=x;
	x=fabs(x);
	x=(x*3.141593)/180;
	s=x;
	for(i=3;i<=n;i+=2)
	{       f=1;
		for(j=1;j<=i;j++)
			f=f*j;
		a=pow(x,i);
		a=a/f;
		if(b%2==0)
			a=a*(-1);
		s=s+a;
		b++;
	}
	printf("\nSin %lf = %lf",y,s);

	getch();
}