#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

class book
{	int bkcode,pbcode,price,stock,b,s,x;
	public :
	book()
	{
	}
	void input();
	int check(int,int);
	void buy(int,int);
	void display();
};

void book::input()
{       cout<<"\nEnter book code->";
	cin>>b;
	cout<<"\nEnter number of books to buy->";
	cin>>s;
}

int book::check(int a,int d)
{       for(int i=0;i<3;i++)
	{	if(a==obj[i].bkcode)
		{	if(d<=stock)
				x=1;
			else
				x=0;
		}
	}
	return x;
}

void book::buy(int a,int d)
{       int sum=0;
	for(int i=0;i<3;i++)
	{	if(a==obj[i].bkcode)
		{	sum=d*obj[i].price;
			obj[i].stock-=d;
			break;
		}
	}
	cout<<"\nNumber of books bought = "<<d<<" \nAmount = Rs."<<sum;
}

void book::display()
{	for(int i=0;i<3;i++)
	{	cout<<obj[i].bkcode<<"  "<<obj[i].pbcode<<"  "<<obj[i].price<<"  "<<obj[i].stock<<"\n";
	}
}
void main()
{	clrscr();
	int y=0;
	void creatobj(book [3]);
	book obj[3];
	creat(obj[]);
	do
	{	obj.input();
		y=obj.check(obj.b,obj.s);
		if(y==1)
			obj.buy(obj.b,obj.s);
		else
			cout<<"\nNot possible";
		cout<<"Do you want to continue(y/n)->";
		cin>>m;
	}
	while(m=='y');
	obj.display();
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}
void creatobj(obj[])
{	for(int i=0;i<3;i++)
	{	cout<<"\nEnter book code "<<i<<" ->";
		cin>>obj[i].bkcode;
		cout<<"\nEnter publisher code "<<i<<" ->";
		cin>>obj[i].pbcode;
		cout<<"\nEnter price "<<i<<" ->";
		cin>>obj[i].price;
		cout<<"\nEnter stock "<<i<<" ->";
		cin>>obj[i].stock;
	}
}































