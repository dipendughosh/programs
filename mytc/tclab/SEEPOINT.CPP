#include<iostream.h>
#include<conio.h>
void main()
{   clrscr();
	int x[]={10,20,30};
	int *a,*b,**c;
	a=x;
	cout<<*a<<endl;
	b=x+1;
	cout<<*b<<endl;
	c=&b;
	cout<<**c;
	getch();
}
