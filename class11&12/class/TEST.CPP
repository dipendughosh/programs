#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

class test
{	int a,b,d;
	public:
	void getdata()
	{	cin>>a;
		cin>>b;
	}
	void sumdata()
	{	d=a+b;
	}
	void showdata()
	{	cout<<"\nD="<<d;
	}
};

void main()
{	clrscr();
	test t;
	t.getdata();
	t.sumdata();
	t.showdata();
	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
}
/*#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

class test
{	int a,b,d;
	public:
	void getdata()
	{	cin>>a;
		cin>>b;
	}
	void sumdata()
	{	d=a+b;
	}
	void showdata()
	{	cout<<"\nD="<<d;
	}
};

int main()
{
	test t;
	t.getdata;
	t.sumdata;
	t.showdata;
	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
	return(0);

} */
