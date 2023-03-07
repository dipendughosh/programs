# include <conio.h>
# include <iostream.h>
void main()
{    clrscr();
	int i,s=0;
	do
	{
		cout<<"\nplease enter the no : ";
		cin>>i;
		cout<<"\n the no is : "<<i;
		s+=i;
	}
	while (i!=0);
	cout<<"\nsum is  "<<s;
	getch();
}
