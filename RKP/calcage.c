//Calculating age of a person
#include<string.h>
#include<conio.h>
#include<stdio.h>

int main()
{	//clrscr();
	//Declaring variables and function prototypes
	//Days of month array
	int daysInMon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	//Leapyear check function
	int checkLeap(int);                                         
	//Valid date check function
	int checkdate(int,int,int,int,int,int);                     
	int dob,mob,yob,day,month,year,curday,curmon,curyear;       
	int agemon = 0,ageday = 0, ageyear = 0;                     
	int dinmon = 0,ctr = 0,flag1;                               
	//Entering data and checking their validity
	do                                                          
	{
		printf("Enter date of birth : \n");     
		printf("Day   : "); scanf("%d",&dob);    
		printf("Month : "); scanf("%d",&mob);    
		printf("Year  : "); scanf("%d",&yob);    
		printf("\nEnter current date : \n");    
		printf("Day   : "); scanf("%d",&curday); 
		printf("Month : "); scanf("%d",&curmon); 
		printf("Year  : "); scanf("%d",&curyear);
		flag1=checkdate(dob,mob,yob,curday,curmon,curyear); 
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
	printf("\nAge is : ");                                         //displaying age
	printf("%d Years %d Months %d Days",ageyear,agemon,ageday);
	getch();
	return(0);
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
				{	printf("\nRE-ENTER DATA\n");
					flag=0;
				}
			}
		}
	}

	else
	{	printf("\nRE-ENTER DATA\n");
		flag=0;
	}
	return flag;
}


