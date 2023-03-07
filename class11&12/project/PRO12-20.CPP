//14
/*To find the digit frequency and digit
  sum of the digits of a number(done)*/
#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<iomanip.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<dos.h>

class number
{	private:
	long num;
	public:
	number();
	number(long);
	void digitfrequency();
	int digitsum();
	~number();
};

number ::number()
{	num=0;
}

number ::number(long n)
{	num=n;
}

void number::digitfrequency()
{	int counter=1,arr[20],i,j,x=0,a,flag=1;
	long n=num;
	while(n!=0)
	{	a=n%10;
		n/=10;
		arr[x]=a;
		x++;
	}
	cout<<"\nDigit\tFrequency";
	for(i=0;i<x-1;i++)
	{	for(j=i+1;j<x;j++)
		{	if(arr[i]==9999)
			{	flag=0;
				break;
			}
			if(arr[i]==arr[j])
			{	counter++;
				arr[j]=9999;
			}

		}
		if(flag!=0)
		{	cout<<"\n"<<arr[i]<<"\t"<<counter;
			counter=1;
		}
		else
			flag=1;
	}
}

int number::digitsum()
{	int a,sum=0;
	long n=num;
	while(n!=0)
	{	a=n%10;
		sum+=a;
		n/=10;
	}
	return sum;
}

number ::~number()
{
}

void main()
{	clrscr();
	long n;
	int x;
	cout<<"\nEnter a number-->";
	cin>>n;
	number obj(n);
	obj.digitfrequency();
	x=obj.digitsum();
	cout<<"\nSum of digits is-->"<<x;
	getche();
}































































































































