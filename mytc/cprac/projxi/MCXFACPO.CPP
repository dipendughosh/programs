/******    TO PRINT THE SERIES X-X^2/2!+-+-+-+-+-+-X^N/N!    ******/
#include<iostream.h>
#include<conio.h>
#include<Math.h>
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
	cout<<"Sum of "<<x<<"-"<<x<<"^2/2!+...-...+..."<<x<<"^"<<limit<<"/"<<limit<<"! is "<<sum;
	getche();
    return 0;
}
int factorial(int n)
{
	int prod =1;
	while(n>=1)
	{
		prod*=n--;
	}
	return prod;
}





