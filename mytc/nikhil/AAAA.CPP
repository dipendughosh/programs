#include<conio.h>
#include<iostream.h>


void main()
{   clrscr();
	for (int i=20;i<=31;i++)
	{	char c=i;
		if (i==26)
		{	cout<<i<<"->"<<endl;
			continue;
		}
		cout<<i<<"->"<<c<<"\n";
	}
	getch();
}
