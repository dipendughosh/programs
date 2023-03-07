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
	long int factorial(long int);
	long int i,a,b,c,s=0;
	for(i=1;i<=1000000;i++)
	{       b=i;
		s=0;
		while(b!=0)
		{	a=b%10;
			b=b/10;
			c=factorial(a);
			s=s+c;
		}
		if(s==i)
		{	cout<<i<<" ";
		}
	}
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

long int factorial(long int n)
{       long int f=1,i;
	for(i=1;i<=n;i++)
	{	f=f*i;
	}
	return f;
}