#include<conio.h>
#include<complex.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
class abc
{
	int a,b,c;
	public:
		void input()
		{
			cout<<"\n1.Input a--> ";cin>>a;
			cout<<"\n2.Input b--> ";cin>>b;
		}
		int add()
		{
			c=a+b;
			return c;
		}
};
class xyz
{
	int x,y,z;
	abc obj1;
	public:
		xyz()
		{
			cout<<"\n3.Input x--> ";cin>>x;
			cout<<"\n4.Input y--> ";cin>>y;
			obj1.input();
		}
		void add()
		{
			z=x+y;
		}
		void output()
		{
			cout<<"\nSum of all no is....--> "<<(z+obj1.add());
		}
};
void main()
{
	clrscr();
	xyz first;
	first.add();
	first.output();
	getch();
}
