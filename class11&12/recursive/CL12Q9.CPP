#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

int f;
void main()
{	clrscr();
	int x,n,y;
	int recursive(int,int);
	cout<<"\nx^n\nEnter x: ";
	cin>>x;
	cout<<"Enter n: ";
	cin>>n;
	f=x;
	y=recursive(x,n);
	cout<<"\n"<<x<<"^"<<n<<"="<<y;
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

int recursive(int x,int n)
{	if(n==0)
		return f;
	else
		f=f*recursive(x,n-1);
	return (0);
}