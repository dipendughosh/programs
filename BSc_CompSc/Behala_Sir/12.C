#include<stdio.h>
#include<conio.h>

void main()
{       int j,i,n;
	double y,x,sum=1.0,f,z,t;
	clrscr();
	printf("Enter value of x :- ");
	scanf("%lf",&x);
	printf("Enter value of n :- ");
	scanf("%d",&n);
	i=0;
	sum=1.0;
	y=x;
	while(i<n)
	{	j=1;
		f=1;
		while(j<=i)
		{	f=f*j;
			j++;
		}
		sum=sum+(y/f);
		y=y*x;
		i++;
	}
	printf("\ne^x = %lf",sum);
	z=1.0;
	t=1;
	i=1;
	sum=1.0;
	while(i<=n+1)
	{	t=t*10;
		i++;
	}
	i=1;
	y=x;
	while(z>=1/t)
	{	j=1;
		f=1;
		while(j<=i)
		{	f=f*j;
			j++;
		}
		z=y/f;
		sum=sum+z;
		y=y*x;
		i++;
	}
	printf("\ne^x = %lf",sum);
	getch();
}

