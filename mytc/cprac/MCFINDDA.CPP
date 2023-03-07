#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int yr,day,month,d;
	cout<<"enter year ";
	cin>>yr;
	do
	{
		cout<<"enter day ";
		cin>>day;
	}while(day<1 || day>31);
	cout<<"enter month ";
	cin>>month;
	if(month!=8 &&  month%2 == 0 && day == 31)
	{
		cout<<"the date is invalid for the month ";
	}
	d = 1;
	int isleap(int);
	void leap(int,int,int),notleap(int,int,int);
	if(isleap(yr))
	{
		leap(day,month,d);
	}
	else
	{
		notleap(day,month,d);
	}
	getche();
}
int isleap(int y)
{
	if(y%4==0)
	{
		if(y%100!== 0)
		{
			return 1;
		}
		if(y%400 == 0)

		{
			return 1;
		}
	}
	return 0;
}
void leap(int d,int m,int i)
{
