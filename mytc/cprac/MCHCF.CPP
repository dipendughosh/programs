#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int x,y,n=2,i=0;
	cout<<"\nEnter two numbers ";
	cin>>x;
	cin>>y;
	while(n<=x)
	{
		if(x%n == 0)
		{
			if(y%n == 0)
			{
				i = n;

			}
		}
		n++;
	}
	if(i>1)
	{
		cout<<i<<"  is the h.c.f";
	}
	else
	{
		cout<<x<<"  &  "<<y<<"  do not have an h.c.f";
	}
	getche();
}