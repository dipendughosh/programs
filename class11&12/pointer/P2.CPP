//Difference between pointer &reference
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

void swapv(int,int);
void swapr(int &,int &);
void swapa(int *,int *);
void main()
{	clrscr();
	int a=10,b=20;
	swapv(a,b);//Call by value
	cout<<"\nMain\na = "<<a<<"    b = "<<b;
	swapa(&a,&b);//Call by address
	cout<<"\nMain\na = "<<a<<"    b = "<<b;
	swapr(a,b);//Call by reference
	cout<<"\nMain\na = "<<a<<"    b = "<<b;
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

void swapv(int i,int j)
{	int t;
	t=i;
	i=j;
	j=t;
	cout<<"\nFunction\ni = "<<i<<"    j = "<<j;
}

void swapa(int *i,int *j)
{	int t;
	t=*i;
	*i=*j;
	*j=t;
}

void swapr(int &i,int &j)
{	int t;
	t=i;
	i=j;
	j=t;
}