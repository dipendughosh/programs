//inter change values
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	int a,b;
	cout<<"Enter a number :";
	cin>>a;
	cout<<"Enter second number :";
	cin>>b;
	a=a+b;
	b=a-b;
	a=a-b;
	cout<<"\nThe values after interchange "<<a<<" "<<b;
	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
}