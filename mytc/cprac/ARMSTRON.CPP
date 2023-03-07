// Armstrong numbers
#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int num;
	int digitsum(int);
	for(int i = 100; i < 1000; i++)
	{
		num = digitsum(i);
		if(num == i)
		{
			cout<<"\nThe number "<<num<<"  is an armstrong number";
		}
	}
	getche();
}

int digitsum(int x)
{
	int sum = 0,temp,cube;
	while(x>0)
	{
		temp = x%10;
		x/=10;
		cube =( temp*temp*temp);
		sum+=cube;
	}
	return sum;
}


