#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

class factorial
{       public:
	int n,f;
	public:
	factorial()
	{	cout<<"\nEnter a number->";
		cin>>n;
		f=1;
	}
	int fact(int n)
	{	if(n==0)
			return f;
		else
		{	f=n*fact(n-1);
		}
		return f;
	}
	void display()
	{	cout<<"\nFactoral of "<<n<<" is "<<f;
	}
	~factorial()
	{
	}
};
void main()
{	clrscr();
	factorial obj;
	obj.fact(obj.n);
	obj.display();
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

