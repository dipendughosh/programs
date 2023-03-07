#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	clrscr();
	int s=0,p,a=0,b=1,c=0;
	cout<<"\nfibonacci numbers upto 50.......\n";
	do
	{
		c=a+b;
		a=b;
		b=c;
		if(b>50)
			break;
		else
			cout<<a<<"\t";
	}
	while(s==0);
	cout<<"\nNon fibonacci numbers upto 50...\n";
	a=0;b=1;c=0;s=0;
	do
	{
		p=b;
		c=a+b;
		a=b;
		b=c;
		if(b>50)
			break;
		for(int i=p+1;i<b;i++)
		{
			cout<<i<<"\t";
		}
	}
	while(s==0);
	getch();
}
