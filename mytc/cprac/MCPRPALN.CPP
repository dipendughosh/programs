//3 digit to 5 digit prime,palin ,nonfibo numbers
#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int prime(int);
	int palin(int);
	int nonfibo(int);
	int i;
	for(i= 100;i<=30000;i++)
	{
		if(prime(i)==0)
		{
			if(palin(i)==0)
			{
				if(nonfibo(i)==0)
				{
					cout<<"  "<<i;
				}
			}
		}
	}
	getche();
}

int prime(int num)
{
	int i,flag=0;
	for(i=2;i<=(num/2);i++)
	{
		if(num%i == 0)
		{
			flag = 1;
		}
	}
	return flag;
}

int palin(int num)
{
	int temp,s,z = num;
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
int nonfibo(int num)
{
	int x =1,y =0,z =0,j =num+1;
	while(z<j)
	{
		z =x+y;
		x = y;
		y = z;
		if(z == num)
		{
			return 1;
		}
	}
	return 0;
}


