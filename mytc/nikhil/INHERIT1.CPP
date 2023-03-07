#include<conio.h>
#include<iostream.h>

class input
{		int a1,a2;
	public:
		input()
		{	a1=a2=0;
		}
		void readnum()
		{	cout<<"Enter a1 and a2 : "; cin>>a1>>a2;
		}
		void shownum()
		{	cout<<"\na1 = "<<a1<<"\ta2 = "<<a2;
		}
		int conv()
		{	return a1+a2;
		}

};

class calc1:public input
{       int a3,sum;
	public:
		calc1()
		{   input::input();
			a3=0;
			sum=0;
		}
		void readnum()
		{   input::readnum();
			cout<<"Enter a3 : ";  cin>>a3;
			a3*=10;
		}
		int calc()
		{   sum=input::conv()+a3;
			cout<<sum;
			return sum;
		}
		void show()
		{   cout<<"\nTHE NUMBERS ARE : ";
			cout<<"\nIN THE BASE CLASS THE NUMBERS ARE : ";
			input::shownum();
			cout<<"\nIN THE DERIVED CLASS CALC1 THE NUMBER IS a3 = "<<a3;
			cout<<"\nTHEIR SUM IS : ";
		}
}x;

class calc2:public input
{		int a4;
	public:
		calc2()
		{	a4=0;
		}
		void readnum()
		{ 	cout<<"Enter a4 : ";  cin>>a4;
			a4*=8;
		}
		int calc()
		{   return a4;
		}
		void show()
		{
			cout<<"\nIN THE DERIVED CLASS CALC2 THE NUMBER IS a4 = "<<a4;
		}
}y;


void main()
{   clrscr();
	int n1,n2;
	x.readnum();
	y.readnum();
	y.show();
	x.show();
	n1=x.calc();
	n2=y.calc();
	cout<<"\n\nTHE SUM OF ALL THE NUMBERS IS : "<<n1+n2;
	getch();
}