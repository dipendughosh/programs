//NEAREST PRIME TO A NUMBER
#include<conio.h>
#include<iostream.h>
void main()
{	clrscr();
	int n,a,b;
	int primea(int);
	int primeb(int);
	cout<<"ENTER A NUMBER :";
	cin>>n;
	a=primea(n);
	b=primeb(n);
	if( a >= b )
		cout<<n-b<<" NO IS "<<b;
	else
		cout<<n+a<<" NO IS "<<a;
	getche();
}

int primeb(int s)
{	int i,n=0,x,y;
	for( i=s;i>=0;i--)
	{   n=0;
		for(int k=2;k<i;k++)
		{	x=i%k;
			if( x == 0 )
			{	n=1;

			}
		}
		if( n == 0 )
		{	y=i;
			break;
		}
	}
	return s-y;
}


int primea(int s)
{	int i,n,x,y;
	for( i=s;i<=2*s;i++)
	{
		n=0;
		for(int k=2;k<i;k++)
		{	x=i%k;
			if( x == 0 )
			{	n=1;

			}
		}
		if( n == 0 )
		{	y=i;
			break;
		}
	}
	return s-y;
}


































































































































































































































































































































































































































































