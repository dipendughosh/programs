//print in desired position
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
	int i,j,r,c;
	char string[80];
	cout<<"\nEnter string->";
	gets(string);
	cout<<"\nPOSITION OF PRINTING ENTERED STRING";
	cout<<"\nROW->";
	cin>>r;
	cout<<"\nCOLUMN->";
	cin>>c;
	clrscr();
	for(i=0;i<=r;i++)
	{	for(j=0;j<=c;j++)
		{	if(i<r && j<c)
				cout<<" ";
			if(i==r && j==c)
			{	cout<<string;
				break;
			}
		}
	}
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}































































































































