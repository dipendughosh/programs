#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<iomanip.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<dos.h>


void main()
{	clrscr();
	int a=1,b=1,c=0,i,n;
	cout<<"\nEnter a number----> ";
	cin>>n;
	for(i=0;i<n/2;i++)
	{	c=a+b;
		a=b;
		b=c;
	}
	c=a+b;
	if(b==n)
		cout<<"\nIt is a fibonacci number!";
	else if(c-n>=b-n)
		cout<<"\nNear fibo is "<<b;
	else
		cout<<"\nNear fibo is "<<c;
	getche();
}































































































































