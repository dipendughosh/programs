// Program to print x - x^2/2! + x^3/3! - ... + ... - ... x^n/n!
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int main()
{
	//clrscr();
	float x,fac,sum,limit,i=2,power;
	float factorial(int);
	cout<<"Enter a number       ";
	cin>>x;
	sum = x;
	cout<<"Enter limit of loop  ";
	cin>>limit;
	while(i<=limit)
	{
		power = pow(x,i);
		fac   = factorial(i);
		sum-= (power/fac);
		sum*=-1;
		i++;
	}
	cout<<"Sum of "<<x<<" - "<<x<<"^2/2!+...-...+..."
        <<x<<"^"<<limit<<"/"<<limit<<"! is "<<sum;
    cout<<endl;
    system("PAUSE");
    return 0;
}

float factorial(int n)
{
	int prod =1;
	while(n>=1)
	{
		prod*=n--;
	}
	return prod;
}

