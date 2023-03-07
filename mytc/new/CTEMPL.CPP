//
# include <iostream.h>
# include <conio.h>

void main()
{	clrscr();
	int a,n,d;
	cout<<"ENTER A NUMBER :";
	cin>>n;
	while(n!=0)
	{	a=n%2;
		a=a*2;
		d=(d*10) + a;
		n= n/10;
	}
	cout<<"\nbinary ="<<d;
	getche();
}






	getch();
}

