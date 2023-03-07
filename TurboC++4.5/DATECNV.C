/*Conversion of date
INPUT - 12 - 04 - 05.
OUTPUT- 12th April,2005.*/
#include<conio.h>
#include<stdio.h>

int daysInMon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

/*Declaring 2 functions.
Checking if LEAP YEAR
Checking if the entered dates are VALID*/
int checkLeap(int);
int checkdate(int,int,int);

void main()
{       //Declaring variables and functions
	int flag=1,i,len,a,t=1,s=0,dd[3],x=2;
	char dat[15];
	void date(int);
	void month(int);
//	clrscr();
	//Entering the dates and checking their validity
	do
	{       t=1;
		s=0;
		x=2;
		//clrscr();
		printf("\nEnter date in DD-MM-YYYY-> ");
		gets(dat);
		len=strlen(dat);
		printf("%d",len);
		for(i=(len-1);i>=-1;i--)
		{	a=dat[i]-48;
			if(a>=0 && a<=9)
			{	s=s+(a*t);
				t*=10;
			}
			else
			{	if(dat[0]=='-')
					s=s*(-1);
				dd[x]=s;
				s=0;
				t=1;
				--x;
			}
		}
		flag=checkdate(dd[0],dd[1],dd[2]);
		printf("\nPRESS ENTER.........");
		getch();
	}
	while(flag==0);
	//Printing the converted of date
	printf("\nEntered date is ->%d - %d - %d\n",dd[0],dd[1],dd[2]);
	date(dd[0]);
	month(dd[1]);
	printf(",%d",dd[2]);
	getche();
}

//Leap check function
int checkLeap(int y)
{	if( y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
	{	return 29;
	}
	else
	{	return 28;
	}
}

//Checking date validity function
int checkdate(int dd1,int mm1,int yy1)
{	int dinmon,flag=1;
	dinmon = (mm1 == 2 ? checkLeap(yy1) : daysInMon[mm1]);
	if(dd1>=1 && dd1<=dinmon && mm1<=12 && yy1>999 && yy1<10000)
	{	flag=1;
	}
	if(mm1<=0 || mm1>=13)
	{	printf("\nRE-ENTER DATE");
		printf("\nWRONG MONTH\n");
		flag=0;
	}
	if(dd1<1 || dd1>dinmon)
	{       printf("\nRE-ENTER DATE");
		printf("\nWRONG DAY\n");
		flag=0;
	}
	if(yy1<1000 || yy1>9999)
	{	printf("\nRE-ENTER DATE");
		printf("\nWRONG YEAR\n");
		flag=0;
	}
	return flag;
}

//Displaying day format
void date(int day)
{       if(day>=4 && day<=20)
	{	printf("\n%dth ",day);
	}
	else if(day==1 || day==21 || day==31)
	{	printf("\n%dst ",day);
	}
	else if(day==2 || day==22 )
	{	printf("\n%dnd ",day);
	}
	else if(day==3 || day==23 )
	{	printf("\n%drd ",day);
	}
	else
	{	printf("\n%dth ",day);
	}
}

//Displaying month
void month(int mont)
{      	char mon[13][20]={
			  "\0",
			  "January\0",
			  "Feburuary\0",
			  "March\0",
			  "April\0",
			  "May\0",
			  "June\0",
			  "July\0",
			  "August\0",
			  "September\0",
			  "October\0",
			  "November\0",
			  "December\0"
			 };
	printf("%s",mon[mont]);
}