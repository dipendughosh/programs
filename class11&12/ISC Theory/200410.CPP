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

class D2point
{       protected:
	double x,y,d1;
	public:
	D2point();
	D2point(double,double);
	double distanced2(D2point);
};
D2point::D2point()
{	x=y=0;
}
D2point::D2point(double nx,double ny)
{	x=nx;
	y=ny;
}
double D2point::distanced2(D2point b)
{	double x1,y1,d=0;
	x1=x-b.x;
	cout<<"\nx1-x2 "<<x1;
	y1=y-b.y;
	cout<<"\ny1-y2 "<<y1;
	x1=(x1*x1);
	cout<<"\nx^2 "<<x1;
	y1=(y1*y1);
	cout<<"\ny^2 "<<y1;
	d1=x1+y1;
	cout<<"\nx+y "<<d1;
	d=d1;
	d=sqrt(d);
	cout<<"\nsqrtd1 "<<d;
	cout<<"\nDistance 1 "<</*between ("<<x<<","<<y<<") & ("<<b.x<<","<<b.y<<")="<<*/d;
	return d1;
}
class D3point:public D2point
{	double z;
	public:
	D3point();
	D3point(double);
	double distanced3(D3point);
}
D3point::D3point()
{	z=0;
}
D3point::D3point(double nz)
{	z=nz;
}
double D3point::distanced3(D3point b)
{       double z1,d2,d=0;
	d2=D2point::d1;
	cout<<"\nd2= "<<d2;
	z1=z-b.z;
	cout<<"\nz1-z2 "<<z1;
	z1=(z1*z1);
	cout<<"\nz^2 "<<z1;
	d2=d2+z1;
	cout<<"\nx+y+z "<<d2;
	d=sqrt(d2);
	cout<<"\nsqrtd1 "<<d;
	cout<<"\nDistance 2 "<</*between ("<<D2point::x<<","<<D2point::y<<","<<z<<") & ("<<D2point::b.x<<","<<D2point::b.y<<","<<b.z<<")="<<*/d;
	return d;
}
void main()
{	clrscr();
	double x,y,z;
	cout<<"\nPoint 1\n";
	cout<<"X=";
	cin>>x;
	cout<<"Y=";
	cin>>y;
	cout<<"Z=";
	cin>>z;
	D2point d1(x,y);
	D3point d3(z);
	cout<<"Point 2\n";
	cout<<"X=";
	cin>>x;
	cout<<"Y=";
	cin>>y;
	cout<<"Z=";
	cin>>z;
	D2point d2(x,y);
	d1.distanced2(d2);
	D3point d4(z);
	d3.distanced3(d4);
	getche();
}
