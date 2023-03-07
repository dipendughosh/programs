//feed a series of numbers into a 1d array and find the number of
//times a number is repeated.
//another number entered and checked for the number of times present.
//dat number's position where it first occurs.
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#define MAX 40
class series
{   private:
		int a[MAX];
		int c;
		int x;
		int p;
		int temp;
		int t;
		int z;
		int flag;
		int first;
	public:
		series();
		void getdata();
		void zcalc();
		void calc();
		void firstnum();
		void print()
		{	cout<<"\n\nThe number repeated the most number of times is "
				<<temp<<",it being repeated "<<p<<" times.\n";
			if(flag==1) cout<<"\nThe number "<<z<<" is repeated "<<t<<" times.";
			else cout<<"\n\a\aSORRY!!!!!!\nNUMBER NOT FOUND.";
		}
};

series::series()
{   c=0;
	flag=0;
	first=0;
	p=0;
	t=0;
	cout<<"\nEnter the number of elements .....";
	cin>>x;
	cout<<"\nEnter the elements.....\n";
}
void series::getdata()
{   for(int i=0;i<x;i++)
		cin>>a[i];
	cout<<"\nEnter a number ..."; cin>>z;
}
void series::calc()
{   for(int i=0;i<=9;i++)
	{   c=0;
		for(int j=0;j<x;j++)
		   if (a[j] == i)	c++;

		if(c>p)
		{   p=c;    temp=i;}
	}
}
void series::zcalc()
{	for(int k=0;k<x;k++)
	{	if(a[k] == z)
		{ t++;
		  flag=1;
		}
	}
}
void series::firstnum()
{	for(int l=0;l<x;l++)
	{	if (a[l] == z)
		{	cout<<"\nThe first position of the number is "<<l+1;
			break;
		}
	}
}


void main()
{   clrscr();
	series s;
	s.getdata();
	s.calc();
	s.zcalc();
	s.print();
	s.firstnum();
	getch();
}
