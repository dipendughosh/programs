// isc 2003 ouestion 2
#include<conio.h>
#include<complex.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	clrscr();
	int hr,min;
	void time(int,int);
	char ch;
	do
	{
		clrscr();
		cout<<"\nEnter time ......(hr/min)...->";cin>>hr>>min;
		if(hr>=0 && hr<13)
		{
			if(min>=0 && min<60)
			{
				time(hr,min);
			}
			else
				cout<<"\nWrong entry of minutes....";
		}
		else
			cout<<"\nWrong entry of hour's.............";
		cout<<"\n\n\nEnter want to continue or not...(Y/N)...";cin>>ch;
	}
	while(ch=='Y');
	getch();
}
void time(int hh,int mm)
{
	char unit[20][50]={"  ","one","two","three","four","five","six",
			"seven","eighi","nine","ten","eleven","twelve",
			"thirteen","fourteen","fifteen","sixteen","seventeen",
			"eight","nineteen"};
	if(mm==0)
	{
		cout<<unit[hh]<<" o'clock ";
		getch();
		exit(0);
	}
	if(mm==30)
	{
		cout<<"half past "<<unit[hh];
	}
	if(mm<30)
	{
		if(mm<20 && mm!=15)
			cout<<unit[mm];
		if(mm>19)
			cout<<"twenty "<<unit[(mm-20)];
		if(mm==15)
			cout<<" quater past "<<unit[hh];
		else
			cout<<" minutes past "<<unit[hh];
	}
	if(mm>30)
	{
		mm=60-mm;
		if(mm<20 && mm!=15)
			cout<<unit[mm];
		if(mm>19)
			cout<<"twenty "<<unit[(mm-20)];
		if(mm==15)
		{
			hh=hh>12 ? hh=0 : hh=hh;
			cout<<" quater to "<<unit[hh+1];
		}
		else
		{
			hh=hh>11 ? hh=0: hh=hh;
			cout<<" minutes to "<<unit[hh+1];
		}

	}
}

