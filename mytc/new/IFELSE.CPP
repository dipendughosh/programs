//
# include <iostream.h>
# include <conio.h>
void main()
{	clrscr();
	int a,b;
	cout<<"Put value : "; cin>>a;

	b = ( a == 10 ? 10 : a == 4 ? 4 : a + 1 );

	cout<<"\na is "<<a<<" and b is "<<b;
	getch();
}



