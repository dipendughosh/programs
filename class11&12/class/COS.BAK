#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<iomanip.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<dos.h>
double factorial(double a)
{	double f=1,i;
	for(i=1;i<=a;i++)
		f=f*i;
	return f;
}
class trig
{	double x,sum;
	public:
	trig(double);
	double abs(double);
	double cose();
};
trig::trig(double nx)
{	x=nx;
}
double trig::abs(double y)
{	if(y<0)
		return (y*(-1));
	if(y>=0)
		return y;
}
double trig::cose()
{       x=(x*3.141593)/180;
	sum=1;
	int b=2,i;
	double y=0,a=0;
	if(x==3.141593/2)
		sum=0;
	else if(x>=0 && x<=(3.141593/2))
	{	for(i=2,b=2;i<=18;b++,i+=2)
		{       y=factorial(i);
			a=pow(x,i);
			a=a/y;
			if(b%2==0)
				a=a*(-1);
			sum=sum+a;
			sum=abs(sum);
		}
	}
	else
		sum=9999999.9;
	return sum;
}
void main()
{	clrscr();
	double y,a;
	cout<<"PI/2=90\nPI/5=36\nPI/6=30\nPI/36=5\n";
	cout<<"\nEnter the angle in degrees \n ";
	cin>>y;
	trig obj(y);
	a=obj.cose();
	cout<<"\ncos "<<y<<"="<<a;
	getche();
}
