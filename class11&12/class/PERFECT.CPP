#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

class number
{	private:
	int n,s,i,a,b,c;
	public:
	number()
	{	cout<<"\nEnter a number->";
		cin>>n;
		s=0;
		i=0;
		a=0;
		b=0;
		c=0;
	}
	void prime();
	void perfect_square();
	void perfect_number();
	~number()
	{
	}
};

void number::prime()
{	for(i=1;i<=(n/2);i++)
	{	b=n%i;
		if(b==0)
			++c;
	}
	if(c==1)
		cout<<"\n"<<n<<" is prime";
	else
		cout<<"\n"<<n<<" is not prime";
}

void number::perfect_square()
{	for(i=0;i<n/2;i++)
	{	a=i*i;
		if(a==n)
		{	c=1;
		}
	}
	if(c==1)
	{	cout<<"\n"<<n<<" is a perfect square of "<<i;
	}
	else
	{	cout<<"\n"<<n<<" is not a perfect square";
	}
}

void number::perfect_number()
{	for(i=1;i<n;i++)
	{	a=n%i;
		if(a==0)
		{	s=s+i;
		}
	}
	if(s==n)
	{	cout<<"\n"<<n<<" is a perfect number";
	}
	else
	{	cout<<"\n"<<n<<" is not a perfect number";
	}
}
void main()
{	clrscr();
	number obj;
	obj.prime();
	obj.perfect_square();
	obj.perfect_number();
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

