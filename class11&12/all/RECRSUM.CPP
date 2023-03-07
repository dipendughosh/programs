#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

void main()
{	clrscr();
	int n=200;
	int sum(int);
	cout<<"Sum of 1 to 200 is "<<sum(n);
	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
}
int sum(int a)
{	int s=0;
	if(a==0)
	{	return s;
	}
	else
	{	s=a+sum(a-1);
		return s;
	}
}