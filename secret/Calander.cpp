//CALANDER(MAY 2005)(DONE)
#include<iostream.h>
#include<process.h>
#include<conio.h>
#include<stdio.h>

const char *mname[]={"January",
		     "February",
		     "March",
		     "April",
		     "May",
		     "June",
		     "July",
		     "August",
		     "September",
		     "October",
		     "November",
		     "December"
		    };

int mday[]={31,28,31,30,31,30,31,31,30,31,30,31};

int isleap(unsigned int year)
{	if((year%400==0) || ((year%4==0) && (year%100!=0)))
		return 1;
	else
		return 0;
}

int countday(int year)
{	int i,sum=0;
	for(i=1;i<year;i++)
		if(isleap(i))
			sum++;
	return ((year-1+sum+1)%7);
}

void prnmonth(int day,int year,int month)
{	int i,j,k=1,x=20,y=7;
	clrscr();
	_setcursortype(0);
	gotoxy(x,y);
	textattr(30);
	cprintf("  SUN");
	textattr(26);
	cprintf("   MON    TUE   WED   THR   FRI   SAT ");
	gotoxy(x,y+1);
	textattr(7);
	textcolor(7);
	printf("%c",201);
	for(i=1;i<42;i++)
		printf("%c",205);
	printf("%c",187);
	for(i=2;i<11;i++)
	{	gotoxy(x,y+i);
		printf("%c",186);
	}
	for(i=2;i<11;i++)
	{	gotoxy(x+42,y+i);
		printf("%c",186);
	}
	gotoxy(x,y+11);
	printf("%c",200);
	for(i=1;i<42;i++)
		printf("%c",205);
	printf("%c",188);
	textcolor(12);
	gotoxy(x+2,y+10);
	cprintf("%s",mname[month-1]);
	gotoxy(x+36,y+10);
	cprintf("%5d",year);
	textcolor(7);
	i=x+3+6*day;
	j=y+3;
	gotoxy(i,j);
	for(k=1;k<=mday[month-1];k++)
	{	printf("%2d",k);
		if(i<=x+35)
			i+=6;
		else
		{	j++;
			i=x+3;
		}
		gotoxy(i,j);
	}
}

void calander(int year,int month)
{	int sum=0,i;
	clrscr();
	if(isleap(year))
		mday[1]=29;
	else
		mday[1]=28;
	for(i=0;i<month-1;i++)
		sum+=mday[i];
	prnmonth((sum+countday(year))%7,year,month);
}

int valid(int year,int month)
{	if((year>0 && year<=32766) && (month>=1 && month<=12))
		return 1;
	else
		return 0;
}

void main()
{       int year,month;
	struct date cuda;
	char ch=' ';
	clrscr();
	textcolor(7);
	printf("Enter year-> ");
	scanf("%d",&year);
	printf("\nEnter month-> ");
	scanf("%d",&month);
	if(!valid(year,month))
	{	printf("\nInvalid Date\n\a");
		getche();
		exit(0);
	}
	else
	{	printf("\nPress Enter key to view this month");
		getche();
	}
	do
	{	calander(year,month);
		gotoxy(1,20);
		printf("Press N for Next month.");
		gotoxy(1,21);
		printf("Press B for Previous month.");
		gotoxy(1,22);
		printf("Press X for Next year.");
		gotoxy(1,23);
		printf("Press Z for Previous year");
		gotoxy(1,24);
		printf("Press Esc for Exit");
		ch=getch();
		if(ch==27)
			break;
		if(ch=='n' || ch=='N')
		{	if(month>=1 && month <12)
				month++;
			else
			{	year++;
				month=1;
			}
		}
		if(ch=='b' || ch=='B')
		{	if(month>1 && month<=12)
				month--;
			else
			{	if(year!=1)
				{	year--;
					month=12;
				}
			}
		}
		if(ch=='x' || ch=='X')
			year=year+1;
		if(ch=='z' || ch=='Z')
			if(year!=1)
				year=year-1;
	}
	while(1);
	clrscr();
	_setcursortype(2);
}

