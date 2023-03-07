#include<iostream.h>
#include<string.h>
#include<process.h>
#include<conio.h>
#include<stdio.h>
int daysinmon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct product
{       char code[10],pname[20];
};
struct date
{	int dd,mm,yyyy;
};
class dayelapsed
{	date d1,d2,d3;
	product d4;
	unsigned long sday1,sday2,x,flag;
	public:
	dayelapsed();
	void getdata();
	void showdata();
	void calcdays();
	int checkleap(int);
	void datecheck();
	~dayelapsed();
};
dayelapsed :: dayelapsed()
{       x=0;
	sday1=0;
	sday2=0;
}
void dayelapsed::getdata()
{       cout<<"\nEnter Code Number:- ";
	gets(d4.code);
	cout<<"Enter Product Name:- ";
	gets(d4.pname);
	cout<<"Enter Manufacturing Date\n";
	cout<<"Day:- ";
	cin>>d1.dd;
	cout<<"Month:- ";
	cin>>d1.mm;
	cout<<"Year:- ";
	cin>>d1.yyyy;
	cout<<"Enter Expiry Date\n";
	cout<<"Day:- ";
	cin>>d2.dd;
	cout<<"Month:- ";
	cin>>d2.mm;
	cout<<"Year:- ";
	cin>>d2.yyyy;
	cout<<"Enter Present Date\n";
	cout<<"Day:- ";
	cin>>d3.dd;
	cout<<"Month:- ";
	cin>>d3.mm;
	cout<<"Year:- ";
	cin>>d3.yyyy;
}
int dayelapsed :: checkleap(int y)
{	if(y%4==0 && y%100!=0 || y%400==0)
		return 29;
	else return 28;
}
void dayelapsed :: datecheck()
{       int x1,x2,x3,i;
	if(d1.mm==2)
		x1=checkleap(d1.yyyy);
	else
		x1=daysinmon[d1.mm];
	if(d2.mm==2)
		x2=checkleap(d2.yyyy);
	else
		x2=daysinmon[d2.mm];
	if(d3.mm==2)
		x3=checkleap(d3.yyyy);
	else
		x3=daysinmon[d3.mm];
	if(d1.dd>=1 && d1.dd<=x1 && d2.dd>=1 && d2.dd<=x2 && d3.dd>=1 && d3.dd<=x3 && d1.mm>=1 && d1.mm<=12 && d2.mm>=1 && d2.mm<=12 && d3.mm>=1 && d3.mm<=12 )
		flag=1;
	else
	{	cout<<"\nWrong date?Try again-";
		getche();
		exit(0);
	}
}
void dayelapsed :: calcdays()
{       int a1,a2,b1,b2,x1,x2,x3,s1,s2,s3,c,j;
	s1=0;s2=0;s3=0;b1=0;b2=0;a1=0;a2=0;
	a1=d2.yyyy-d1.yyyy-1;
	a2=d3.yyyy-d1.yyyy-1;
	if(d1.yyyy<d2.yyyy)
	{	for(j=(d1.yyyy+1);j<d2.yyyy;j++)
		{	c=checkleap(j);
			if(c==29)
				b1++;
		}
	}
	if(d1.yyyy<d3.yyyy)
	{	for(j=(d1.yyyy+1);j<d3.yyyy;j++)
		{	c=checkleap(j);
			if(c==29)
				b2++;
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
	if(d3.mm==2)
		x3=checkleap(d3.yyyy);
	else
		x3=daysinmon[d2.mm];
	for(j=(d1.mm+1);j<=12;j++)
	{	if(j==2)
			s1=s1+checkleap(d1.yyyy);
		else
			s1=s1+daysinmon[j];
	}
	s1=s1+x1-d1.dd;
	for(j=1;j<d2.mm;j++)
	{	if(j==2)
			s2=s2+checkleap(d2.yyyy);
		else
			s2=s2+daysinmon[j];
	}
	s2=s2+d2.dd;
	for(j=1;j<d3.mm;j++)
	{	if(j==2)
			s3=s3+checkleap(d3.yyyy);
		else
			s3=s3+daysinmon[j];
	}
	s3=s3+d3.dd;
	sday1=b1+(a1*365)+s1+s2;
	sday2=b2+(a2*365)+s1+s3;
}
void dayelapsed :: showdata()
{       cout<<"\nCode Number\tProduct Name\tMfg Date:\tExp Date:\tsday1\tsday2";
	cout<<"\n"<<d4.code<<"\t"<<d4.pname<<"\t"<<d1.dd<<"/"<<d1.mm<<"/"<<d1.yyyy<<"\t"<<d2.dd<<"/"<<d2.mm<<"/"<<d2.yyyy<<"\t"<<sday1<<"\t"<<sday2;
	if(sday1<=sday2)
	{	cout<<"\nExpired\nCode Number\t"<<d4.code<<"\tProduct Name\t"<<d4.pname;
	}
	else if((sday2-sday1)<=30)
	{	cout<<"\n30 Days to Expiry\nCode Number\t"<<d4.code<<"\tProduct Name\t"<<d4.pname;
	}
}
dayelapsed :: ~dayelapsed()
{}
void main()
{	clrscr();
	char y;
	dayelapsed obj;
	do
	{       clrscr();
		obj.getdata();
		obj.datecheck();
		obj.calcdays();
		obj.showdata();
		cout<<"\nDo you want to continue?";
		cin>>y;
	}while(y=='y'|| y=='Y');
	getche();
}