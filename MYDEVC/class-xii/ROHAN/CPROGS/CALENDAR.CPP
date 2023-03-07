//ACCEPT START DAY AND PRINT & GENERATE CALENDAR OF THE YEAR
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char week[8]={' ','S','M','T','W','T','F','S'};
void leap(int year)
{   if(((year % 4==0) && (year %100!=0))||(year %4)==0)
		month[2]=29;
	else
		month[2]=28;
}

void main()
{	clrscr();
	int c,dayno,year,m;
	void putweek();
	int putday(int,int,int);
	int putspace(int);
	cout<<"\n enter year : ";	cin>>year;
	cout<<"\n enter starting-day number :(i.e 1-sun,2-mon) ";
	do
	{
		cin>>dayno;
	 }while (dayno<1 ||dayno>7);

	 for(m=1;m<=12;m++)
	 {	putweek();
		c=putspace(dayno);
		dayno=putday(c,m,year);
		getche();
	 }
}
void putweek()
{   cout<<"\n\n";
	for (int i=1;i<8;i++)
		cout<<"  "<<week[i]<<" ";
	cout<<"\n";
}
int putspace(int d)
{	for(int i=1;i<d;i++)
		cout<<"    ";
	return d-1;
}
int putday(int c,int m,int y)
{	if(m==2)
		leap(y);
	for(int i=1;i<=month[m];i++)
	{	c++;
		cout<<setw(4)<<i;
		if (c==7)
		{	cout<<"\n"; getche();
			c=0;
		}
	}
	int dayno=c+1;
	return dayno;
}






