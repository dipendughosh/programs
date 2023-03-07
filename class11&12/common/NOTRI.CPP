#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	int i,n,j,x=1;
	cout<<"Enter a number :";
	cin>>n;
	for(i=1;i<=n;i++)
	{      for(j=0;j<i;j++)
		{	cout<<x<<" ";
			++x;
			if(x>n)
				break;
		}
		if(x>n)
			break;
		cout<<"\n";
	}
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}
