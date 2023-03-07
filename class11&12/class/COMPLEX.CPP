//complex number addition & multiplication
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

class complex
{       private:
	int a,b,c,d,sum1,sum2,mul1,mul2;
	public:
	complex()
	{
	}
	void getdata()
	{	cout<<"\nEnter real value for 1st expresion->";
		cin>>a;
		cout<<"\nEnter imaginary value for 1st expresion->";
		cin>>b;
		cout<<"\nEnter real value for 2nd expresion->";
		cin>>c;
		cout<<"\nEnter imaginary value for 2nd expresion->";
		cin>>d;
	}
	void addition()
	{	sum1=a+c;
		sum2=b+d;
	}
	void multiplication()
	{       mul1=(a*c)-(b*d);
		mul2=(a*d)+(c*b);
	}
	void display()
	{	cout<<"\n1st expression-->"<<a<<"+i"<<b;
		cout<<"\n2nd expression-->"<<c<<"+i"<<d;
		cout<<"\nSUM="<<sum1<<"+i"<<sum2;
		cout<<"\nPRODUCT="<<mul1<<"+i"<<mul2;
	}
};
void main()
{	clrscr();
	complex obj;
	obj.getdata();
	obj.addition();
	obj.multiplication();
	obj.display();
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}


