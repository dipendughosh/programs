//Input:current date,no.of days to be added.
//Output:the date after the current date+no.of days entered.
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>

struct cal
{	int d;
	int m;
	int y;
}cur,ndate;

void main()
{	clrscr();
	int n,rest;
	unsigned long daysadd;
	cout<<"Enter current date :\n";
	cout<<"Date : "; cin>>cur.d;
	cout<<"Month : "; cin>>cur.m;
	cout<<"Year : "; cin>>cur.y;
	cout<<"Number of days to be added : ";  cin>>n;
	daysadd=(cur.y-1)*365+cur.m*30+cur.d;
	daysadd+=n; cout<<"\ntotal: "<<daysadd;
	ndate.y=daysadd/365; cout<<"\tyear : "<<ndate.y;
	rest=daysadd%365; cout<<"\nrest : "<<rest;
	if(rest<=30) {ndate.m=1;ndate.d=rest;}
	else {ndate.m=rest/30;ndate.d=rest%30;}
	cout<<"\n\nThe new date : "<<ndate.d<<'.'<<ndate.m<<'.'<<ndate.y;
	getch();
}