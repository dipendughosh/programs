#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

void main()
{	clrscr();
	int n1,n2,x,a,b,hcf,i;
	cout<<"\nEnter 1st number:";
	cin>>n1;
	cout<<"\nEnter 2nd number:";
	cin>>n2;
	if(n1>=n2)
		x=n2;
	else
		x=n1;
	for(i=1;i<=x;i++)
	{	a=n1%i;
		b=n2%i;
		if(a==0 && b==0)
		{	hcf=i;
		}
	}
	cout<<"\nH.C.F. is ->"<<hcf;
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}


