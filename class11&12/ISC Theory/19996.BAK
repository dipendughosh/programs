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
	int ispallin(int);
	int n1,n2,x,a,n;
	cout<<"\nEnter a number : - ";
	cin>>n1;
	n=n1;
	while(x!=1)
	{       n2=0;
		while(n!=0)
		{       n2*=10;
			a=n%10;
			n=n/10;
			n2=n2+a;
		}
		n=n1+n2;
		x=ispallin(n);
		if(x==0)
		{	n1=n2;
			n=n2;
		}
	}
	cout<<"\nPallindrome is "<<n;
	getche();
}
int ispallin(int a)
{       int b,n=0,n1=a,x;
	while(a!=0)
	{       n*=10;
		b=a%10;
		a=a/10;
		n=n+b;
	}
	if(n==n1)
		x=1;
	else
		x=0;
	return x;
}