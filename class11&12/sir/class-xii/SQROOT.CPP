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
	int n,x;
	double p=0.0;
	cin>>n;
	for(float i=0.0;i<=n;i+=0.1)
	{
		p=(i*i);
		if(p>=n)
		{
			cout<<i;
			x=i*i;
			cout<<"\nsq is...."<<x;
			break;
		}
	}
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

