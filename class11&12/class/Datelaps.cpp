#include<iostream.h>
#include<string.h>
#include<process.h>
#include<conio.h>
#include<stdio.h>
int daysinmon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct date
{	int dd,mm,yyyy;
};
class dayelapsed
{	date d1,d2,temp;
	unsigned long sday,flag;
	public:
	dayelapsed();
	void getdata();
	void showdata1();
	void showdata2();
	void calcdays();
	int checkleap(int);
	void datecheck();
	~dayelapsed();
};
dayelapsed :: dayelapsed()
{       sday=0;
	flag=1;
}
void dayelapsed::getdata()
{	cout<<"\nEnter First Date\n";
	cout<<"Day:- ";
	cin>>d1.dd;
	cout<<"Month:- ";
	cin>>d1.mm;
	cout<<"Year:- ";
	cin>>d1.yyyy;
	cout<<"Enter Second Date\n";
	cout<<"Day:- ";
	cin>>d2.dd;
	cout<<"Month:- ";
	cin>>d2.mm;
	cout<<"Year:- ";
	cin>>d2.yyyy;
}
int dayelapsed :: checkleap(int y)
{	if(y%4==0 && y%100!=0 || y%400==0)
		return 29;
	else return 28;
}
void dayelapsed :: datecheck()
{       int x1,x2;
	if(d1.mm==2)
		x1=checkleap(d1.yyyy);
	else
		x1=daysinmon[d1.mm];
	if(d2.mm==2)
		x2=checkleap(d2.yyyy);
	else
		x2=daysinmon[d2.mm];
	if(d1.dd>=1 && d1.dd<=x1 && d2.dd>=1 && d2.dd<=x2 && d1.mm>=1 && d1.mm<=12 && d2.mm>=1 && d2.mm<=12)
		flag=1;
	else
	{	cout<<"\nWrong date?Try again-";
		getche();
		exit(0);
	}
	if(d1.yyyy>d2.yyyy)
	{	temp=d1;
		d1=d2;
		d2=temp;
	}
	if(d1.yyyy==d2.yyyy)
	{	if(d1.mm>d2.mm)
		{	temp=d1;
			d1=d2;
			d2=temp;
		}
		if(d1.mm==d2.mm)
			if(d1.dd>d2.dd)
			{	temp=d1;
				d1=d2;
				d2=temp;
			}
	}
}
void dayelapsed :: calcdays()
{       int a,b=0,i,x1,x2,s1=0,s2=0,c;
	a=d2.yyyy-d1.yyyy-1;
	if(d1.yyyy<d2.yyyy)
	{	for(i=(d1.yyyy+1);i<d2.yyyy;i++)
		{	c=checkleap(i);
			if(c==29)
				b++;
		}
	}
	if(d1.mm==2)
		x1=checkleap(d1.yyyy);
	else
		x1=daysinmon[d1.mm];
	if(d2.mm==2)
		x2=checkleap(d2.yyyy);
	else
		x2=daysinmon[d2.mm];
	for(i=d1.mm+1;i<=12;i++)
	{	if(i==2)
			s1=s1+checkleap(d1.yyyy);
		else
			s1=s1+daysinmon[i];
	}
	s1=s1+x1-d1.dd;
	for(i=1;i<d2.mm;i++)
	{	if(i==2)
			s2=s2+checkleap(d2.yyyy);
		else
			s2=s2+daysinmon[i];
	}
	s2=s2+d2.dd;
	sday=b+(a*365)+s1+s2;
}
void dayelapsed :: showdata1()
{	cout<<"\nFirst Date:\tSecond Date:\t";
	cout<<"\nDay:-  \t"<<d1.dd<<"\tDay:-  \t"<<d2.dd;
	cout<<"\nMonth:-\t"<<d1.mm<<"\tMonth:-\t"<<d2.mm;
	cout<<"\nYear:- \t"<<d1.yyyy<<"\tYear:- \t"<<d2.yyyy;
}
void dayelapsed :: showdata2()
{	cout<<"\nNumber of days elapsed = "<<sday;
}
dayelapsed :: ~dayelapsed()
{}
void main()
{	clrscr();
	char y;
	dayelapsed obj;
	do
	{	clrscr();
		obj.getdata();
		obj.showdata1();
		obj.datecheck();
		obj.calcdays();
		obj.showdata2();
		cout<<"\nDo you want to continue? ";
		cin>>y;
	}while(y=='y' || y=='Y');
	getche();
}
