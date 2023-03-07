#include<iostream.h>
#include<conio.h>

void main()
{
	clrscr();
	void swap(int&,int&);
	int p = 7,q = 8;
	cout<<"Before ---> p = "<<p<<" q = "<<q;
	swap(p,q);
	cout<<"\nAfter ---> p = "<<p<<" q = "<<q;
	getche();
}
void swap(int& a,int& b)
{
	int temp = a;
	a = b; b = temp;
	cout<<"\nIn func ---> p = "<<a<<" q = "<<b;
}


