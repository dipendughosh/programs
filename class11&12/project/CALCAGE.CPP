		//*CALCULATING AGE OF A PERSON*\\
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
int main()
//void main()
{	//clrscr();
	int daysInMon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};//days of mont array
	int checkLeap(int);                                         //leapyear check function
	int checkdate(int,int,int,int,int,int);                     //valid date check function
	int dob,mob,yob,day,month,year,curday,curmon,curyear;       //variable declaration
	int agemon = 0,ageday = 0, ageyear = 0;                     //variable declaration
	int dinmon = 0,ctr = 0,flag1;                               //variable declaration
	do                                                          //loop for date entering
	{
		cout<<"Enter date of birth : \n";                   //entering date of birth
		cout<<"Day   : "; cin>>dob;                         //day
		cout<<"Month : "; cin>>mob;                         //month
		cout<<"Year  : "; cin>>yob;                         //year
		cout<<"\nEnter current date : \n";                  //entering present date
		cout<<"Day   : "; cin>>curday;                      //day
		cout<<"Month : "; cin>>curmon;                      //month
		cout<<"Year  : "; cin>>curyear;                     //year
		flag1=checkdate(dob,mob,yob,curday,curmon,curyear); //validating dates
	}
	while(flag1==0 );
	day = dob;
	month = mob;
	year = yob;
	dinmon = (month == 2 ? checkLeap(year) : daysInMon[month]);  //last date of each month
	do                                                           //loop for age in days
	{
		++day; ++ctr;
		if(day > dinmon )
		{
			++month; day = 1;  			     // Month increases after dinmon
			if(month > 12)
			{
				++year; month = 1;
			}
			dinmon = (month == 2 ? checkLeap(year) : daysInMon[month]);
		}
	}
	while(day != curday || month != curmon || year != curyear);
	day = dob;
	month = mob;
	year = yob;
	dinmon = (month == 2 ? checkLeap(year) : daysInMon[month]);
	int i = 0;
	do                                                           //loop for age in year,month,days
	{	++ageday;
		if(ageday > dinmon )
		{
			++month; ++agemon; ageday = 1;  	     // Month increases after dinmon
			if(month > 12)
			{
				++year; month = 1;
			}
			if(agemon > 11)
			{
				++ageyear; agemon = 0;
			}
			dinmon = (month == 2 ? checkLeap(year) : daysInMon[month]);
		}
		++i;
	}
	while(i<ctr);
	if(ageday>=31 ||ageday>=30)
	{	++agemon;
		ageday=0;
	}
	if(agemon>=12)
	{	++ageyear;
		agemon=0;
	}
	cout<<"\nAge is : ";                                         //displaying age
	cout<<ageyear<<" Years "<<agemon<<" Months "<<ageday<<" Days.";
	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();return;
}

int checkLeap(int y)                                                 //leap year check function
{
	if(y % 4)
	{   	if(y % 100)
		{   	if(y % 400) return 29;
			else return 28;
		}
		return 29;
	}
	return 28;
}
int checkdate(int dd1,int mm1,int yy1,int dd2,int mm2,int yy2)       //validation of dates
{	int daysInMon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int dinmon1,dinmon2 ,flag;
	dinmon1 = (mm1 == 2 ? checkLeap(yy1) : daysInMon[mm1]);
	dinmon2 = (mm2 == 2 ? checkLeap(yy2) : daysInMon[mm2]);
	if(dd1>=1 && dd1<=dinmon1 && dd2>=1 && dd2<=dinmon2 && yy1<=2005 && yy2<=2005)
	{	if(yy1==yy2 )
		{	if(mm1==mm2 )
			{	if(dd1<=dd2)
				{	flag=1;
				}
				else
				{	cout<<"\nRE-ENTER DATA\n";
					flag=0;
				}
			}
		}
	}

	else
	{	cout<<"\nRE-ENTER DATA\n";
		flag=0;
	}
	return flag;
}


