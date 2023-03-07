#include<conio.h>
#include<complex.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	clrscr();
	int n,s=0,p,m,h;
	cout<<"\nEnter number......-->";cin>>n;
	do
	{
		p=n;
		while(p>0)
		{
			h=p%10;
			s=s+h;
			p=p/10;
		}
		m=s;
		if(s>9)
		{
			n=s;
			s=0;
		}
		else
		{
			if(s==1)
			{
				cout<<"\nIt is a magic number.......";
			}
			else
				cout<<"\nIt is not a magic number...";
		}
	}
	while(m>9);
	getch();
}
