#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

struct date
{	char dat[10];
};
class person
{	char name[10];
	date dt;
	public:
	person()
	{	cout<<"\nEnter Name: ";
		gets(name);
		cout<<"\nEnter Date of Dirth: ";
		gets(dt.dat);
	}
	void prn()
	{	cout<<"\nName : "<<name<<"\nDate of Birth : "<<dt.dat;
	}
};

class student
{	float passpercent;
	int class1,year;
	public:
	student()
	{	cout<<"\nEnter Pass Percent : ";
		cin>>passpercent;
		cout<<"\nEnter Class : ";
		cin>>class1;
		cout<<"\nEnter Year of School Leaving : ";
		cin>>year;
	}
	void prn()
	{	cout<<"\nPass Percent : "<<passpercent<<"\nClass : "<<class1<<"\nYear of School Leaving : "<<year;
	}
};

class employee
{	int code;
	float basic;
	public:
	employee()
	{	cout<<"\nEnter Code : ";
		cin>>code;
		cout<<"\nEnter Basic : ";
		cin>>basic;
	}
	void prn()
	{	cout<<"\nCode : "<<code<<"\nBasic : "<<basic;
	}
};


void main()
{	clrscr();
	person obj1;
	student obj2;
	employee obj3;
	clrscr();
	obj1.prn();
	cout<<"\n\n\nSchool History\n";
	obj2.prn();
	cout<<"\n\n\nEmployee History\n";
	obj3.prn();
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

