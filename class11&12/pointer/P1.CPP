//pointer 1st program(reference)
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
	int i=0;
	int &j=i;
	cout<<"\ni = "<<i<<" j = "<<j;
	j=20;
	cout<<"\ni = "<<i<<" j = "<<j;
	j=30;
	cout<<"\ni = "<<i<<" j = "<<j;
	i++;
	cout<<"\ni = "<<i<<" j = "<<j;
	j++;
	cout<<"\ni = "<<i<<" j = "<<j;
	cout<<"\nAddress of i = "<<&i<<"\nAddress of j = "<<&j;
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

