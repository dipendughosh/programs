//sum of series
# include <iostream.h>
# include <conio.h>
void main()
{	int p=0,term,s;
	clrscr();
	cout << "the term please : ";
	cin >> term;
	for (int i=1;i<=term;i++)
	{	cout <<"\n"<< p;
		s+=p;
		p+=2;

	}
	cout<<"\nsum of series : "<<s;
   getch();
}




