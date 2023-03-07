#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
void main()
{	clrscr();
	int x;
	void prime(int);
	cout<<"ENTER A NUMBER:";
	cin>>x;
	prime(x);
	getche();
}
void prime(int a)
{	int b,c,i;
	for(i=1;i<=(a/2);i++)
	{	b=a%i;
		if(b==0)
			++c;
	}
	if(c==1)
		cout<<"\nPRIME";
	else
		cout<<"\nNOT PRIME";
}
