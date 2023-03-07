#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
int daysinmon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
class date
{	int dd,mm,yyyy,s,flag;
	public:
	date();
	void getdate();
	int checkleap();
	void datevalid();
	void numdays();
	void displaydate();
	~date();
};

date :: date()
{	s=0;
	flag=1;
}
void date :: getdate()
{	cout<<"\nEnter date:--\n";
	cout<<"Month number-mm:-";
	cin>>mm;
	cout<<"Day-dd:- ";
	cin>>dd;
	cout<<"Year-yyyy:-";
	cin>>yyyy;
}
int date :: checkleap()
{	if(yyyy%4==0 && yyyy%100!=0 || yyyy%400==0)
		return 29;
	else return 28;
	return 28;
}
void date::datevalid()
{       int x;
	if(mm==2)
		x=checkleap();
	else
		x=daysinmon[mm];
	if(dd>=1 && dd<=x && mm>=1 && mm<=12)
		flag=1;
	else
	{	cout<<"\nWrong date?Try again-";
		getche();
		exit(0);
	}
}
void date :: numdays()
{       int x=checkleap(),i;
	if(flag==1)
	{
		for(i=1;i<mm;i++)
		{       if(i==2)
				s=s+x;
			else
				s=s+daysinmon[i];
		}
		s=s+dd;
	}
}
void date :: displaydate()
{	cout<<"\nDate:--\n";
	cout<<"\nMonth-:-"<<mm;
	cout<<"\nDay-:- "<<dd;
	cout<<"\nYear-:-"<<yyyy;
	cout<<"\nCorresponding day of the year is : "<<s;
}
date :: ~date()
{
}

void main()
{	clrscr();
	date obj;
	obj.getdate();
	obj.datevalid();
	obj.numdays();
	obj.displaydate();
	getche();
}
