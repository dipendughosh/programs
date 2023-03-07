#include<iostream.h>
#include<conio.h>

void main()
{   clrscr();
	int x,y,n;
	int prime(int);
	int pallindrom(int);
	cout<<"Enter a number::";
	cin>>n;
	x=prime(n);
	if(x)
	{    y=pallindrom(n);
		 if(y)
		 {	cout<<n;
		 }
	}
	getch();
}

int prime(int num)
{   int i,x,y=0;
	for(i=1;i<=num;i++)
	{	x=num%i;
		if(x==0)
		{	y++;
		}
		if(y==2)
		{	return 1;
		}
		if(y>2)
		{   cout<<"\nNot prime::";
			return 0;
		}
	}
}

int pallindrom(int num)
{   int a,s=0,t=1,p;
	p=num;
	while(num==0)
	{	a=num%10;
		s+=(a*t);
		t*=10;
		num/10;
	}
	if(p==s)
	{	return 1;
	}
	if(p!=s)
	{   cout<<"\nNot pallindrom::";
		return 0;
	}
}

