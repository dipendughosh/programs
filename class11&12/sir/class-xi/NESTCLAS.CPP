#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>

class student
{	char name[80],roll[20];
	//int age;
	public :
		student(){}
		void getdata();
		void showdata();
		class date
		{	int dd,mm,yy;
			public :
				void getdate();
				void showdate();
				void calcage();
		};
	   //	date obj1;

};

void student::getdata()
{ 	cout<<"\nEnter name ::";
	gets(name);
	cout<<"\nEnter roll number ::";
	gets(roll);
	//obj1.getdate();
	//age=obj1.calcage();
}

void student::showdata()
{	cout<<"\nNAME -> "<<name;
	cout<<"\nROLL -> "<<roll;
}

void student::date::getdate()
{	cout<<"\nEnter age in dd-mm-yy::";
	cout<<"\nDD::";
	cin>>dd;
	cout<<"\nMM::";
	cin>>mm;
	cout<<"\nYY::";
	cin>>yy;
}

void student::date::showdate()
{	cout<<"\nAGE -> "<<dd<<" "<<mm<<" "<<yy;
}

void student::date::calcage()
{   int s;
	s=dd+(mm*30)+(yy*365);
	cout<<"\nage "<<s;
}

void main()
{   clrscr();
	student obj1;
	student::date obj2;
	obj1.getdata();
	obj2.getdate();
	obj2.calcage();
	obj1.showdata();
	obj2.showdate();
	getche();
}





