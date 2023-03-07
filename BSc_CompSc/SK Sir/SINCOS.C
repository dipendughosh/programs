//Program to find SIN and COS value of a given angle
//cos x=1-x^2/2!+x^4/4!-x^6/6!+...........+x^n/n!
//sinx=x-x^3/3!+x^5/5!-x^7/7!+...........+x^n/n!
#include<stdio.h>
#include<conio.h>


void main()
{       //Declaring variables and functions
	int n;
	double x;
	void sins(double,int);
	void coss(double,int);
	clrscr();
	printf("Enter Angle in degrees :- ");
	scanf("%lf",&x);
	printf("Enter number of iterations :- ");
	scanf("%d",&n);
	//Calling sin function
	sins(x,n);
	//Calling cos function
	coss(x,n);
	getch();
}

//sin x=x-x^3/3!+x^5/5!-x^7/7!+...........+x^n/n!
void sins(double x,int n)
{       //Declaring variables
	int b=2,i,j;
	double a=0,f,s,y;
	//Calculating the sin value using the above formula
	y=x;
	y=fabs(y);
	y=(y*3.141593)/180;
	s=y;
	for(i=3;i<=n;i+=2)
	{       f=1;
		for(j=1;j<=i;j++)
			f=f*j;
		a=pow(y,i);
		a=a/f;
		if(b%2==0)
			a=a*(-1);
		s=s+a;
		b++;
	}
	printf("\nSin %lf = %lf",x,s);
}

//cos x=1-x^2/2!+x^4/4!-x^6/6!+...........+x^n/n!
void coss(double x,int n)
{       //Declaring variables
	int b=2,i,j;
	double a=0,f,s=0,y;
	//Calculating the cos value using the above formula
	y=x;
	y=fabs(y);
	y=(y*3.141593)/180;
	s=1;
	for(i=2;i<=n;i+=2)
	{       f=1;
		for(j=1;j<=i;j++)
			f=f*j;
		a=pow(y,i);
		a=a/f;
		if(b%2==0)
			a=a*(-1);
		s=s+a;
		b++;
	}
	printf("\nCos %lf = %lf",x,s);
}