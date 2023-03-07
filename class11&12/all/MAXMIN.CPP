#include<iostream.h>
#include<conio.h>
void main()
{	clrscr();
	int a,b,max,min;
	cout<<"Enter 1 st number ";
	cin>>a;
	cout<<"Enter 2 nd number ";
	cin>>b;
	if(a>b)
	{	max=a;
		min=b;
	}
	else
	{	max=b;
		min=a;
	}
	if(max>=(2*min))
		cout<<"\nMAX ="<<max;
	else
		cout<<"\nMIN ="<<min;
	getche();
}