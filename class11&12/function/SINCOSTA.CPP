//sin cos tan
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

int fact(int);

void main()
{	clrscr();
	double x,s,c;
	int sine(double);
	int cose(double);
	//void tane(double,double,double);
	cout<<"Enter degree between 0 & 360 ::";
	cin>>x;
	x/=180;
	s=sine(x);
	c=cose(x);
	//tane(x,s,c);
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

int sine(double s)
{       double sum=s,y;
	int i,a=3;
	for(i=0;i<4;i++)
	{       y=pow(s,a);
		y/=fact(a);
		if(i%2==0)
			y*=(-1);
		sum=sum+y;
		a+=2;
	}
	cout<<"\nsin ::"<<"\nCALCULATION :: "<<sum<<"\t FORMULA :: "<<sin(s);
	return sum;
}

int cose(double s)
{       double sum=s,y;
	int i,a=2;
	for(i=0;i<4;i++)
	{       y=pow(s,a);
		y/=fact(a);
		if(i%2==0)
			y*=(-1);
		sum=sum+y;
		a+=2;
	}
	cout<<"\ncos ::"<<"\nCALCULATION :: "<<sum<<"\t FORMULA :: "<<cos(s);
	return sum;
}

void tane(double s,double p,double q)
{       double t;
	t=p/q;
	cout<<"\ntan ::"<<"\nCALCULATION :: "<<t<<"\t FORMULA :: "<<tan(s);
}
int fact(int a)
{	int i,f=1;
	for(i=1;i<=a;i++)
		f=(f*i);
	return f;
}