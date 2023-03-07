//*pyramid*
#include<iostream.h>
#include<conio.h>
void main()
{	int i=0;
	void design(int),pyr(int);
	clrscr();
	while(i<=5)
	{	cout<<endl;
		design(i);
		pyr(i);
		i++;
	}
	getche();
}
void design(int n)
{	int j=n;
	for(;j>0;j--)
		cout<<j;
}
void pyr(int x)
{	int r;
	for(r=0;r<=x;r++)
		cout<<r;
}
