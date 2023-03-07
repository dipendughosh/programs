#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>

struct year
{	int date;
	int month;
	int year;
	long days;
}
input[3],curr;

void main()
{   clrscr();
	long r1,r2,r3;
	long double d=100000000;
	int a=0;
	cout<<"Enter three inputs : \n";
	for(int i=0;i<3;i++)
	{	cin>>input[i].date>>input[i].month>>input[i].year;
		input[i].days=(input[i].year-1)*365+(input[i].month)*30+input[i].date;
		cout<<"\n";
	}
	cout<<"Enter current date : ";
	cin>>curr.date>>curr.month>>curr.year;
	curr.days=(curr.year-1)*365+(curr.month)*30+curr.date;

	if(input[a++].days>curr.days) r1=input[a].days-curr.days;
		else curr.days-input[a].days;
	if(input[a++].days>curr.days) r1=input[a].days-curr.days;
		else curr.days-input[a].days;
	if(input[a].days>curr.days) r1=input[a].days-curr.days;
		else curr.days-input[a].days;
	a=0;
	if(r1<d){d=r1;a=1;}
	else if(r2<d) {d=r2;a=2;}
	else if(r3<d) {d=r3;a=3;}
//	clrscr();
	cout<<"\n";
	cout<<input[a].date<<' '<<input[a].month<<' '<<input[a].year;
	getche();
}


