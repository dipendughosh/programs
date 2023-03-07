//12
//date         (done)
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

int daysInMon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};//days of mont array


int checkLeap(int y)                                                 //leap year check function
{
	if(y % 4)
	{   	if(y % 100)
		{   	if(y % 400) return 28;
			else return 29;
		}
		return 28;
	}
	else
		return 29;
}
int checkdate(int dd1,int mm1,int yy1,int dd2,int mm2,int yy2)       //validation of dates
{	int dinmon1,dinmon2 ,flag;
	dinmon1 = (mm1 == 2 ? checkLeap(yy1) : daysInMon[mm1]);
	dinmon2 = (mm2 == 2 ? checkLeap(yy2) : daysInMon[mm2]);
	if(dd1>=1 && dd1<=dinmon1 && dd2>=1 && dd2<=dinmon2 && yy1<=yy2)
	{	if(yy1==yy2 )
		{	if(mm1==mm2 )
			{	if(dd1<=dd2)
				{	flag=1;
				}
				else
				{	cout<<"\nTRY AGAIN\n";
					getche();
					exit(0);
					flag=0;
				}
			}
		}
	}

	else
	{	cout<<"\nTRY AGAIN\n";
		getche();
		exit(0);
		flag=0;
	}
	return flag;
}

class date
{	private:
	int day,month,year,dob,mob,yob,curday,curmon,curyear,agemonth,ageday,ageyear,ctr,dinmon;
	public:
	date()
	{	day=0;month=0;year=0;
		dob=0;mob=0;yob=0;
		curday=0;curmon=0;curyear=0;
		agemonth=0;ageday=0;ageyear=0;
		ctr=0;dinmon;
	}
	void getdata1()
	{       cout<<"Enter date of birth : \n";                   //entering date of birth
		cout<<"Day   : "; cin>>dob;                         //day
		cout<<"Month : "; cin>>mob;                         //month
		cout<<"Year  : "; cin>>yob;                         //year
	}
	void getdata2()
	{       cout<<"\nEnter current date : \n";                  //entering present date
		cout<<"Day   : "; cin>>curday;                      //day
		cout<<"Month : "; cin>>curmon;                      //month
		cout<<"Year  : "; cin>>curyear;                     //year
	}
	void checkdata(date obj1,date obj2)
	{	checkdate(obj1.dob,obj1.mob,obj1.yob,obj2.curday,obj2.curmon,obj2.curyear); //validating dates
	}
	void calculation(date,date);
	void display()
	{	cout<<"\nAge is : ";                                         //displaying age
		cout<<year<<" Years "<<month<<" Months "<<day<<" Days.";
	}
};

void date::calculation(date obj1,date obj2)
	{	ageday = obj1.dob;
		agemonth = obj1.mob;
		ageyear = obj1.yob;
		dinmon = (agemonth == 2 ? checkLeap(ageyear) : daysInMon[agemonth]);  //last date of each month
		do                                                           //loop for age in days
		{
			++ageday; ++ctr;
			if(ageday > dinmon )
			{
				++agemonth; ageday = 1;  			     // Month increases after dinmon
				if(agemonth > 12)
				{
					++ageyear; agemonth = 1;
				}
				dinmon = (agemonth == 2 ? checkLeap(ageyear) : daysInMon[agemonth]);
			}
		}
		while(ageday !=obj2.curday || agemonth !=obj2.curmon || ageyear != obj2.curyear);
		ageday = obj1.dob;
		agemonth = obj1.mob;
		ageyear = obj1.yob;
		dinmon = (agemonth == 2 ? checkLeap(ageyear) : daysInMon[agemonth]);
		int i = 0;
		do                                                           //loop for age in year,month,days
		{	++day;
			if(day > dinmon )
			{
				++agemonth; ++month; day = 1;  	     // Month increases after dinmon
				if(agemonth > 12)
				{
					++ageyear; agemonth = 1;
				}
				if(month > 11)
				{
					++year; month = 0;
				}
				dinmon = (agemonth == 2 ? checkLeap(ageyear) : daysInMon[agemonth]);
			}
			++i;
		}
		while(i<ctr);
		if(day>=31 ||day>=30)
		{	++month;
			day=0;
		}
		if(month>=12)
		{	++year;
			month=0;
		}
	}


void main()
{	clrscr();
	char y;
	date obj1,obj2,obj3;
	do
	{	obj1.getdata1();
		obj2.getdata2();
		obj3.checkdata(obj1,obj2);
		obj3.calculation(obj1,obj2);
		obj3.display();
		cout<<"\nDo you want to continue-YES-->(Y/y),NO-->(N/n)"<<(char)63;
		cin>>y;
	}
	while(y=='y' || y=='Y');
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

