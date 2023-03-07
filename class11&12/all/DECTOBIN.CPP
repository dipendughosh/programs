#include<iostream.h>
#include<conio.h>
void main()
{	clrscr();
	long a,n,d=0,t=1;
	cout<<"Enter decimal number ";
	cin>>n;
	while(n!=0)
	{	a=n%2;
		n=n/2;
		d=(a*t)+d;
		t=t*10;
	}
	cout<<d;
	getche();
}
