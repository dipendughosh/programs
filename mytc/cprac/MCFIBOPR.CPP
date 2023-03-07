#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int fibo(int);
	int prime(int);
	int num;
	for(num =1;num<1001;num++)
	{
		if(fibo(num)==0)
		{
			if(prime(num)==0)
			{
				cout<<"\nthe number "<<num<<"  is fibonacci and   prime";
			}
		}
	}
	getche();
}
int fibo(int n)
{
	int x =1,y =0,z =0;
	while(z<n+1)
	{
		z = x+y;
		x = y;
		y =z;
		if(z == n)
		{
			return 0;
		}
	}
	return 1;
}
int prime(int n)
{
	int i,flag = 0;
	for(i =2;i<=n/2;i++)
	{
		if(n%i == 0)
		{
			flag =1;
			break;
		}
	}
	return flag;
}




