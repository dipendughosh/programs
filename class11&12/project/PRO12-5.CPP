//4
//complex number addition & multiplication(done)
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

class complex				  //complex class
{       private:                          //private data variables
	int a,b,c,d,sum1,sum2,mul1,mul2;
	public:                           //public data variables
	complex()                         //constructor
	{
	}
	void getdata1()                    //function for data input
	{	cout<<"\nEnter real value for 1st expresion->";
		cin>>a;
		cout<<"\nEnter imaginary value for 1st expresion->";
		cin>>b;
	}
	void getdata2()                    //function for data input
	{	cout<<"\nEnter real value for 2nd expresion->";
		cin>>c;
		cout<<"\nEnter imaginary value for 2nd expresion->";
		cin>>d;
	}
	void addition(complex obj1,complex obj2)                   //addition function
	{	sum1=obj1.a+obj2.c;
		sum2=obj1.b+obj2.d;
	}
	void multiplication(complex obj1,complex obj2)            //multiplication function
	{       mul1=(obj1.a*obj2.c)-(obj1.b*obj2.d);
		mul2=(obj1.a*obj2.d)+(obj2.c*obj1.b);
	}
	void display(complex obj1,complex obj2)                   //display function
	{	cout<<"\n1st expression-->"<<obj1.a<<"+i"<<obj1.b;
		cout<<"\n2nd expression-->"<<obj2.c<<"+i"<<obj2.d;
		cout<<"\nSUM="<<sum1<<"+i"<<sum2;
		cout<<"\nPRODUCT="<<mul1<<"+i"<<mul2;
	}
	~complex()                       //destructor
	{
	}
};
void main()
{	clrscr();
	complex obj1,obj2,obj3;                     //object of complex class
	obj1.getdata1();
	obj2.getdata2();
	obj3.addition(obj1,obj2);
	obj3.multiplication(obj1,obj2);
	obj3.display(obj1,obj2);
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}


