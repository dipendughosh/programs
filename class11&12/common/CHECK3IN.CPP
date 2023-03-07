												//*PROGRAM-7*
//*Checking Bigger of 3 Integers*
#include<iostream.h>
#include<conio.h>
void main()
{ clrscr();
	int a,b,c;                   //*Declering Variables*
	cout<<"Enter 3 Integers\n";
	cin>>a;                      //*Entering Integer*
	cin>>b;                      //*Entering Integer*
	cin>>c;                      //*Entering Integer*
	if(a>=b && a>=c)
	{  cout<<a<<" Is Bigger than "<<b<<" & "<<c<<"\n";
	}
	if(b>=a && b>=c)
	{	 cout<<b<<" Is Bigger than "<<a<<" & "<<c<<"\n";
	}
	if(c>=a && c>=b)
	{  cout<<c<<" Is Bigger than "<<a<<" & "<<b<<"\n";
	}
	getch();
}
