//
# include <iostream.h>
# include <conio.h>

void main()
{	clrscr();
	int a,i=1;
	 cout<<"\n enter no  ";cin>>a;
	while (i*i++<=a) ;
	if (((i-1)*(i-1))==a)
		cout<<"\n the perfect square is  "<< i-1;
	else
		cout<<"\n the perfect square is not possible ";
		getche();
}







