//trapizoidal rule
#include<stdio.h>
#include<conio.h>
#include<math.h>

float f(float x)
{	return((4*x)-(3*(pow(x,2))));
}

void main()
{       float a,b,x[50],y[50],s=0.0,h;
	int n,i;
	clrscr();
	printf("Lower Limit-");
	scanf("%f",&a);
	printf("\nUpper Limit-");
	scanf("%f",&b);
	printf("\nEnter no. of subintervals-");
	scanf("%d",&n);
	h=(b-a)/n;
	x[0]=a;
	x[n]=b;
	y[0]=f(x[0]);
	y[n]=f(x[n]);
	for(i=1;i<n;i++)
	{	x[i]=x[0]+(i*h);
		y[i]=f(x[i]);
		s=s+y[i];
	}
	s=(h/2)*(y[0]+y[n]+(2*s));
	printf("\nI=%f",s);
	getch();
}


