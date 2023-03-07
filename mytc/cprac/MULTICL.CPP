#include<iostream.h>
#include<conio.h>
class abc
{	int a, b, c;
	public:
	void getdata()
	{	cout<<"No. abc -> 1 : "; cin>>a;
		cout<<"No. abc -> 2 : "; cin>>b;
	}
	int add()
	{	c = a + b;
		cout<<"\nAdding..\n";
		return c;
	}
};
class xyz
{	int x, y, z;
	abc obj1;
	public:
	xyz()
	{
		obj1.getdata();
	}
	void getdata()
	{	cout<<"No. xyz -> 1 : "; cin>>x;
		cout<<"No. xyz -> 2 : "; cin>>y;
	}
	void add()
	{	z = x + y; }
	void output()
	{ 	cout<<"\n Answer is.......--> "<<(z+obj1.add());}
};
void main()
{
	clrscr();
	xyz objj;
	objj.getdata();
	objj.add();
	objj.output();
	getche();
}