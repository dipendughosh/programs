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
	int n1,n2,x,p,i,hcf,lcm,a,b;
	cout<<"\nEnter 1st number:- ";
	cin>>n1;
	cout<<"\nEnter 2nd number:- ";
	cin>>n2;
	if(n1>=n2)
		x=n2;
	else
		x=n1;
	p=n1*n2;
	for(i=x;i<=p;i++)
	{	a=i%n1;
		b=i%n2;
		if(a==0 && b==0)
		{	lcm=i;
			break;
		}
	}
	for(i=1;i<=x;i++)
	{	a=n1%i;
		b=n2%i;
		if(a==0 && b==0)
			hcf=i;
	}
	cout<<"\nLCM = "<<lcm;
	cout<<"\nHCF = "<<hcf;
	getche();
}
