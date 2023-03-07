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

class sumseries
{	int x,n;
	double sum;
	public:
	sumseries();
	int factorial(int);
	double term(int,int);
	void accept();
	void displaysum();
	double calcsum();
};

sumseries::sumseries()
{	x=n=0;
	sum=1;
}

void sumseries::accept()
{	cout<<"\nEnter value of x : ";
	cin>>x;
	cout<<"Enter limit n: ";
	cin>>n;
}

int sumseries::factorial(int n)
{	int i,f=1;
	for(i=1;i<=n;i++)
		f*=i;
	return f;
}

double sumseries::term(int p,int q)
{       p=pow(p,((2*q)-1));
	q=factorial(q);
	int d=p/q;
	return d;
}

void sumseries::displaysum()
{	cout<<"\nSum = "<<sum;
}

double sumseries::calcsum()
{       int i;
	for(i=1;i<=n;i++)
		sum=sum+term(x,i);
	return sum;
}

void main()
{	clrscr();
	sumseries s;
	s.accept();
	s.calcsum();
	s.displaysum();
	getche();
}
