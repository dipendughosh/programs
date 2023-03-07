/*****     5 Digit Numbers which are PRIME & PALINDROME     *****/
#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	long prime(long);
	long palin(long);
	long i;
	for(i= 10000;i<=99999;i++)
	{
		if(prime(i)==0)
		{
			if(palin(i)==0)
			{
				cout<<"  "<<i;

			}
		}
	}
	getche();
}

long prime(long num)
{
	long i,flag=0;
	for(i=2;i<=(num/2);i++)
	{
		if(num%i == 0)
		{
			flag = 1;
		}
	}
	return flag;
}

long palin(long num)
{
	long temp,s,z = num;
	s = num%10;
	num/=10;
	while(num>0)
	{
		temp =num%10;
		s*=10;
		s+=temp;
		num/=10;
	}
	if(z == s)
	{
		return 0;
	}
	return 1;
}
