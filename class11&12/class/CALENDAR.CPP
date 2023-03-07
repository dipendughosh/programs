#include<iostream.h>
#include<string.h>
#include<process.h>
#include<conio.h>
#include<stdio.h>
int daysinmon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char dday[7][10]={"Sunday\0","Monday\0","Tuesday\0","Wednesday\0",
		 "Thursday\0","Friday\0","Saturday\0"};
char month[13][10]={"\0","January\0","February\0","March\0","April\0",
		    "May\0","June\0","July\0","August\0","September\0",
		    "October\0","November\0","December\0"};
struct date
{	int dd,mm,yyyy;
};
class dayelapsed
{	date d1,d2,temp;
	unsigned long sday,flag,n,d;
	public:
	dayelapsed();
	void getdata();
	void showdata1();
	void calcdays();
	void day();
	void showcalendar();
	int checkleap(int);
	void datecheck();
	~dayelapsed();
};
dayelapsed :: dayelapsed()
{       sday=0;
	flag=1;
}
void dayelapsed::getdata()
{	cout<<"\nEnter Previous Date\n";
	cout<<"Day:- ";
	cin>>d1.dd;
	cout<<"Month:- ";
	cin>>d1.mm;
	cout<<"Year:- ";
	cin>>d1.yyyy;
	cout<<"Enter Present Date\n";
	cout<<"Day:- ";
	cin>>d2.dd;
	cout<<"Month:- ";
	cin>>d2.mm;
	cout<<"Year:- ";
	cin>>d2.yyyy;
	cout<<"Enter day (Sun=0,Mon=1,Tue=2,Wed=3,Thu=4,Fri=5,Sat=6) ";
	cin>>n;
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
	if(d1.dd>=1 && d1.dd<=x1 && d2.dd>=1 && d2.dd<=x2 && d1.mm>=1 && d1.mm<=12 && d2.mm>=1 && d2.mm<=12 && n>=0 && n<=6 && d1.yyyy<=d2.yyyy)
		flag=1;
	else
	{	cout<<"\nWrong date?Try again-";
		getche();
		exit(0);
	}
}
void dayelapsed :: calcdays()
{       int a,b=0,i,x1,x2,s1=0,s2=0,c;
	sday=0;
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
	sday=sday+b+(a*365)+s1+s2;
}
void dayelapsed::day()
{       int num,nnum;
	num=sday/7;
	nnum=sday-(num*7);
	if(nnum<=n)
		d=n-nnum;
	if(nnum>n)
		d=7-nnum+n;
}
void dayelapsed::showcalendar()
{       int x1,dd1=d,i,j,x=1,x2=d1.dd;
	if(d1.mm==2)
		x1=checkleap(d1.yyyy);
	else
		x1=daysinmon[d1.mm];
	if(x2>1)
		for(i=x2;i>1;i--)
		{	x2--;
			dd1--;
			if(dd1==-1)
				dd1=6;
			if(x2==1)
				break;
		}
	cout<<"\n\t\t\t"<<month[d1.mm];
	cout<<"\nSun\tMon\tTue\tWed\tThu\tFri\tSat\t\n";
	for(i=0;i<7;i++)
	{       for(j=0;j<7;j++)
		{       if(j==dd1 && x<=x1)
			{	cout<<x;
				x++;
				dd1++;
			}
			cout<<"\t";
		}
		dd1=0;
		cout<<"\n";
		if(x>x1)
			break;
	}
}
void dayelapsed :: showdata1()
{	cout<<"\nPrevious Date:\tPresent Date:\t";
	cout<<"\nDay:-  \t"<<d1.dd<<"\tDay:-  \t"<<d2.dd;
	cout<<"\nMonth:-\t"<<d1.mm<<"\tMonth:-\t"<<d2.mm;
	cout<<"\nYear:- \t"<<d1.yyyy<<"\tYear:- \t"<<d2.yyyy;
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
		obj.datecheck();
		obj.showdata1();
		obj.calcdays();
		obj.day();
		obj.showcalendar();
		cout<<"\nDo you want to continue? ";
		cin>>y;
	}while(y=='y' || y=='Y');
	getche();
}