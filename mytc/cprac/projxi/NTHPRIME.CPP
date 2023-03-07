/*****   To Print Nth Prime Number   *****/
#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int n, num = 2, a = 0,nom;
	int isprime(int);
	cout<<"Enter a number : "; cin>>n;
	do
	{
		if(isprime(num))
		{   ++a;
			if(a == n) break;
		}
		num++;
	} while(num > 0);
	cout<<num;
	getche();
}

int isprime(int p)
{
	for(int j = 2; j <= p/2; j++)
	{
		if(p % j == 0)
			return 0;
	}
	return 1;
}




