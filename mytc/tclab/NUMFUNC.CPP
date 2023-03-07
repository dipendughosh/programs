#include <iostream.h>
#include <conio.h>

void main()
{	long n,f,r;
	long fact(long), reverse(long);
	clrscr();
	cout<<"Enter a number : "; cin>>n;
	f = fact(n);
	r = reverse(n);
	cout<<"\nthe factorial is : "<<f;
	cout<<"\nthe reverse is : "<<r;

	getch();
}

long fact(long num)
{   long ff = 1;
	while(num) ff *= num--;
	return ff;
}

long reverse(long num)
{   int a = 0,b;
	while (num)
	{	b = num % 10;
		a += b;
		a *= 10;
		num /= 10;
	}
	a /= 10;
	return a;
}


