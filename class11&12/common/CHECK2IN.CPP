											//*PRGRAM-6*
//*To Check Bigger of to 2 Integers*
#include<iostream.h>
#include<conio.h>
void main()
{ clrscr();
	int a,b;                    //*Declaring Variables*
	cout<<"Enter 2 integers \n";
	cin>>a;                     //*Entering 1 Integer*
	cin>>b;                     //*Entering 2 Integer*
	if(a>b)                     //*Checking for Bigger*
	{  cout<<a<<" IS BIGGER THAN "<<b;
	}
	else                        //*Checking for Bigger if 1st is False*
	{  cout<<b<<" IS BIGGER THAN "<<a;
	}
	getch();
}
