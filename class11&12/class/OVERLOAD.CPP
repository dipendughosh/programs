#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>


class test
{       int x,y,z,a,b,c;
	public:
	test()
	{	x=4;
		y=5;
		z=3;
	}
	int getdata(int,int);
	int getdata(int);
	int getdata(int,int,int);
	void showdata(int p)
	{	cout<<p<<"\n";
	}
};
int test::getdata(int a,int b)
{	return (a+b);
}
int test::getdata(int a,int b,int c)
{	return (a+b+c);
}
int test::getdata(int a)
{	return (a);
}
void main()
{	clrscr();
	test obj;
	obj.showdata(obj.getdata(obj.x,obj.y));
	obj.showdata(obj.getdata(obj.x,obj.y,obj.z));
	obj.showdata(obj.getdata(obj.x));
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}
/*#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

int main()
{	cout<<"\nPRESS ANY KEY TO CONTINUE ............";
	getche();
	return(0);
	
}*/
