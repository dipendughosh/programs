#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
void main()
{	clrscr();
	int fibo();
	int fact(int);
	cout<<"SUM OF FIRST 10 FIBONACCI NUMBERS="<<fibo();
	getche();
}
int fibo()
{       int fact(int);
	int i,x=0,y=1,z,a,s=0;
	for(i=2;i<=10;i++)
	{	z=x+y;
		x=y;
		y=z;
		a=fact( z);
		s=s+a;
	}
	return s;
}
int fact(int x)
{	int i,f=1;
	for(i=x;i>=1;i--)
		f=f*i;
	return f;
}









































































































































































