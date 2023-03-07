#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

class input
{	public:
	int a,b;
	public:
	input()
	{
	}
	void getdata()
	{	cout<<"\nEnter A:->";
		cin>>a;
		cout<<"\nEnter B:->";
		cin>>b;
	}
};

class add : private input
{	public:
	int sum;
	public:
	add()
	{
	}
	void addition()
	{       input::getdata();
		sum = input::a + input::b ;
	}
	void display()
	{	cout<<"\nSum is "<<sum;
	}
	~add()
	{
	}
};

class sub : private input
{	public:
	int min;
	public:
	sub()
	{
	}
	void subtraction()
	{       input::getdata();
		if(input::a >= input::b)
			min = input::a - input::b ;
		if(input::a <= input::b)
			min = input::b - input::a ;
	}
	void display()
	{	cout<<"\nDfference is "<<min;
	}
	~sub()
	{
	}
};

class mul : private input
{	public:
	int mult;
	public:
	mul()
	{
	}
	void multiplication()
	{       input::getdata();
		mult = input::a * input::b ;
	}
	void display()
	{	cout<<"\nProduct is "<<mult;
	}
	~mul()
	{
	}
};

class div : private input
{	public:
	int divs;
	public:
	div()
	{
	}
	void division()
	{       input::getdata();
		if(input::a >= input::b)
		{	if(input::b==0)
			{	cout<<"\nDivision by 0 not possible!";
			}
			else
			{	divs = input::a / input::b ;
			}
		}
		if(input::a <= input::b)
		{	if(input::a==0)
			{	cout<<"\nDivision by 0 not possible!";
			}
			else
			{	divs = input::b / input::a ;
			}
		}
	}
	void display()
	{	cout<<"\nQuotient is "<<divs;
	}
	~div()
	{
	}
};
class common : private add,sub,mul,div
{       public:
	int cho;
	public:
	common()
	{
	}
	void getdata()
	{	cout<<"\nEnter choice:->";
		cin>>cho;
	}
	void calculation();
	~common()
	{
	}
};
void common::calculation()
{	switch(cho)
	{	case 1:
			add::addition();
			add::display();
			break;
		case 2:
			sub::subtraction();
			sub::display();
			break;
		case 3:
			mul::multiplication();
			mul::display();
			break;
		case 4:
			div::division();
			div::display();
			break;
		case 5:
			cout<<"\nEixting program..........";
			getche();
			exit(0);
			break;
		default:
			cout<<"\nWRONG CHOICE-->";
			break;
	}
}

class menu : private common
{       public:
	menu()
	{
	}
	void format()
	{       cout<<"\n  MENU";
		cout<<"\n1.ADDITION";
		cout<<"\n2.SUBTRACTION";
		cout<<"\n3.MULTIPLICATION";
		cout<<"\n4.DIVISION";
		cout<<"\n5.EIXT";
		common::getdata();
		common::calculation();
	}
	~menu()
	{
	}
};

void main()
{	clrscr();
	menu obj;
	obj.format();
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

