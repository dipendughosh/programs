#include <iostream.h>
#include <conio.h>

void change(int& p,int& q)
{	int temp;
	temp=p; p=q; q=temp;
	cout<<"\nin change ==>> a = "<<p<<" : b = "<<q;
	//return(p,q);
}

void main()
{
	int a=34,b=45;
	clrscr();
	cout<<"a = "<<a<<" : b = "<<b;
	change(a,b);
	cout<<"\nin main - > a = "<<a<<" : b = "<<b;
	getche();
}


