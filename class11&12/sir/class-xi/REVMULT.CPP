//12*42=21*24
//12*84=21*48
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
	int i,j,a,b,x,y;
	int reverse(int);
	for(i=11;i<=99;i++)
	{	for(j=i+1;j<=99;j++)
		{       if(i==j)
			{	break;
			}
			else
			{	a=i*j;
				x=reverse(i);
				y=reverse(j);
				b=x*y;
				if(a==b)
				{	cout<<"\n"<<i<<"*"<<j<<"="<<x<<"*"<<y;
				}
				else
				{	break;
				}
			}
		}
	}
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

int reverse(int n)
{       int a,d=0,t=1;
	while(n!=0)
	{	a=n%10;
		n=n/10;
		d=(a*t)+d;
		t=t*10;
	}
	return d;
}