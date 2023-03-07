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
	int num,x;
	long int sum=0,a;
	long int factorial(long int);
	cout<<"\nEnter a number:>";
	cin>>num;
	a=num;
	while(a!=0)
	{	x=a%10;
		a/=10;
		sum+=factorial(x);
	}
	if(num==sum)
		cout<<num<<" is a special number";
	else
		cout<<num<<" is not special number";
	getche();
}

long int factorial(long int n)
{	long int f=1,i;
	for(i=1;i<=n;i++)
		f*=i;
	return f;
}































































































































