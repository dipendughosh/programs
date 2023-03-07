/*Entering 2 dates and calculating the number
of days lapsed between the 2 dates*/
#include<conio.h>
#include<stdio.h>

//Declaring a structure to store the a date
struct days
{	int dd,mm,yyyy;
};

//Declaring 2 structure type variables to store the 2 dates
struct days d1,d2;

int daysInMon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

/*Declaring 3 functions.
Checking if LEAP YEAR
Checking if the entered dates are VALID
Calculayting the days lapsed*/
int checkLeap(int);
int checkdate();
void calculation();

int ctr=0;

void main()
{       //Declaring variable
	int flag;
	clrscr();
	//Entering the dates and checking their validity
	do
	{       printf("Enter dates in the format:-\n\tDD-MM-YYYY\n");
		printf("Enter 1st date  : \n");
		printf("Day   : ");scanf("%d",&d1.dd);
		printf("Month : ");scanf("%d",&d1.mm);
		printf("Year  : ");scanf("%d",&d1.yyyy);
		printf("\nEnter 2nd date : \n");
		printf("Day   : ");scanf("%d",&d2.dd);
		printf("Month : ");scanf("%d",&d2.mm);
		printf("Year  : ");scanf("%d",&d2.yyyy);
		flag=checkdate();
	}
	while(flag==0 );
	calculation();
	//Printing the number of days lapsed
	//clrscr();
	printf("\n\tEntered Dates are  :-\n\t\t%d-%d-%d\n\t\t%d-%d-%d\n",d1.dd,d1.mm,d1.yyyy,d2.dd,d2.mm,d2.yyyy);
	printf("\nDays lapsed = %d",ctr);
	getch();
}

//Leap check function
int checkLeap(int y)
{       if(y % 4)
	{   	if(y % 100)
		{   	if(y % 400) return 28;
			else return 29;
		}
		return 28;
	}
	return 29;
}

//Checking date validity function
int checkdate()
{       struct days d3;
	int dinmon1,dinmon2 ,flag;
	dinmon1 = (d1.mm == 2 ? checkLeap(d1.yyyy) : daysInMon[d1.mm]);
	dinmon2 = (d2.mm == 2 ? checkLeap(d2.yyyy) : daysInMon[d2.mm]);
	if(d1.dd>=1 && d1.dd<=dinmon1 && d2.dd>=1 && d2.dd<=dinmon2 && d1.mm>=1 && d1.mm<12 && d2.mm>=1 && d2.mm<12 && d1.yyyy<=2008 && d2.yyyy<=2008)
		flag=1;
	else
	{	printf("\nRE-ENTER DATA\n");
		flag=0;
	}
	if(d1.yyyy>d2.yyyy)
	{       d3=d1;
		d1=d2;
		d2=d3;
	}
	else if(d1.yyyy==d2.yyyy && d1.mm>d2.mm)
	{       d3=d1;
		d1=d2;
		d2=d3;
	}
	else if(d1.yyyy==d2.yyyy && d1.mm==d2.mm && d1.dd>d2.dd)
	{       d3=d1;
		d1=d2;
		d2=d3;
	}
	return flag;
}

//Function for calculating the number of days lapsed
void calculation()
{       int day,month,year,dinmon=0;
	day = d1.dd;
	month = d1.mm;
	year = d1.yyyy;
	dinmon = (month == 2 ? checkLeap(year) : daysInMon[month]);
	if(d1.dd==d2.dd && d1.mm==d2.mm && d1.yyyy==d2.yyyy)
		ctr=0;
	else
	{	do
		{       ++day; ctr++;
			if(day > dinmon )
			{
				++month; day = 1;
				if(month > 12)
				{
					++year; month = 1;
				}
				dinmon = (month == 2 ? checkLeap(year) : daysInMon[month]);
			}
		}
		while(day != d2.dd || month != d2.mm || year != d2.yyyy);
	}
}

