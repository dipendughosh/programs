// Adding numbers of two classes
#include<iostream.h>
#include<conio.h>
class a
{	int n;
	public:
	void getdata()
	{	cout<<"Enter mo.(n) : "; cin>>n;
	}
	void showdata()
	{	cout<<"Value of n : "<<n;
	}
	int carry()
	{	return n;

	}
};

class b : public a
{	int x;
	public:
	void getdata()
	{	a::getdata();
		cout<<"Enter mo.(x) : "; cin>>x;
	}
	int add()
	{   return (a::carry() + x);
	}
	void showdata()
	{   a:: carry();
		a::showdata();
		cout<<"\tValue of x : "<<x;
		cout<<"\n\nSUM OF x AND n IS : "<<add();
	}
};

void main()
{   clrscr();
	b obj;
	obj.getdata();
	obj.add();
	obj.showdata();
	getch();
}
