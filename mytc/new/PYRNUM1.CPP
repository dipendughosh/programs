# include <conio.h>
# include <iostream.h>
void main()
{	int p=9,b;
	clrscr();
	for (;p>=1;p--)
	{   for (int b=p;b>=1;b--)
			cout <<b<<"\t";
		cout <<"\n";
	}
	getch();
}