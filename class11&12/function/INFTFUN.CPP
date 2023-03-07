#include<iostream.h>
#include<conio.h>
void main()
{	clrscr();
	int f;
	int ft(int);
	cout<<"ENTER DISTENCE IN FEET ";
	cin>>f;
	cout<<"\nDISTENCE IN INCHES = "<<ft(f);
	getche();
}
int ft(int x)
{	return x*12;
}