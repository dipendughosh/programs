#include<conio.h>
#include<iostream.h>

class date
{		int d,m,y;

		int chk(int p)
		{	int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
			return m[p];
		}
	public:
		date()
		{	d=m=y=0;
		}

		void get();

		long double datetodayno(date dd)
		{	long double dif=0;
			cout<<"\n"<<dd.d<<dd.m<<dd.y<<endl;
			dif+=dd.d;cout<<"\n\t"<<dif;
			dif+=(dd.m-1)*30;cout<<"\n\t"<<dif;
			dif+=(dd.y-1945-1)*365;cout<<"\n\t\t"<<dif;
			return dif;
		}

		void daynotodmy( long double diff)
		{	double dd,mm,yy;
			cout<<diff;
			if (diff<31) dd=diff;
			else if (diff<36)
				 {	mm=diff/30;
					dd=diff-(mm*30);
				 }
				 else
				 {	yy=diff/365;
					mm=diff-(yy*365)/30;
					dd=diff-((yy*365)+(mm*30));
				 }
			cout<<"\n\nDIFFERENCE : "<<dd<<" DAYS "<<mm<<" MONTHS "<<yy<<" YEARS ";
		}
};

void date::get()
{   do
	{	cout<<"\nEnter day : " ; cin>>d;
	}while(d<0 || d>31);
	do
	{	cout<<"Enter month : ";  cin>>m;
	}while(m>12 || m<0 || d>(chk(m)));
	do
	{	cout<<"Enter year : ";  cin>>y;
	}while(y<1945);

}

void main()
{	//clrscr();
	date d1,d2;
	long double difference;
	cout<<"Enter first date : ";
	d1.get();
	cout<<"Enter second date : ";
	d2.get();
	difference=d2.datetodayno(d2)-d2.datetodayno(d1);
	d1.daynotodmy(difference);
	getche();
}
