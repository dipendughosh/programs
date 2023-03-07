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

class quard
{	float a,b,c,x1,x2;
	public:
	quard(float,float,float);
	float discriminant();
	void root_equal();
	void root_imag();
	void root_real();
	void root();
};

quard::quard(float aa,float bb,float cc)
{	a=aa;
	b=bb;
	c=cc;
}

float quard::discriminant()
{	int z;
	z=(pow(b,2))-(4*a*c);
	return z;
}

void quard::root_equal()
{	x1=x2=(-1*b)/(2*a);
	cout<<"\nRoots are equal:\nx1="<<x1<<"\nx2="<<x2;
}

void quard::root_imag()
{	float d=discriminant();
	x1=x2=(-1*b)/(2*a);
	cout<<"\nRoots are imaginary:\nx1="<<x1<<"+("<<d<<"^(1/2))/"<<(2*a)<<"\nx2="<<x2<<"-("<<d<<"^(1/2))/"<<(2*a);
}

void quard::root_real()
{       float d=discriminant();
	x1=x2=(-1*b)/(2*a);
	x1=x1-((pow(d,(1/2)))/(2*a));
	x2=x2+((pow(d,(1/2)))/(2*a));
	cout<<"\nRoots are real:\nx1="<<x1<<"\nx2="<<x2;
}

void quard::root()
{	float d=discriminant();
	if(d==0)
		root_equal();
	if(d<0)
		root_imag();
	if(d>0)
		root_real();
}

void main()
{	clrscr();
	float a,b,c;
	cout<<"\nEnter the values :\n";
	cout<<"A=";
	cin>>a;
	cout<<"B=";
	cin>>b;
	cout<<"C=";
	cin>>c;
	quard q(a,b,c);
	q.root();
	getche();
}
