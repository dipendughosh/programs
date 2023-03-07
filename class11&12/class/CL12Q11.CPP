#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

class number
{	long int num;
	public:
	number()
	{	num=0;
	}
	number(long int n)
	{	num=n;
	}
	void digitfrequency()
	{	long int a,n=num,x=0,y=0,i,j,k,arr[20];
		while(n!=0)
		{	a=n%10;
			n=n/10;
			arr[x]=a;
			x++;
		}
		for(i=0;i<x;i++)
		{	for(j=0;j<x;j++)
			{	if(arr[i]==arr[j])
				{	for(k=j;k<x;k++)
					{	arr[k]=arr[k+1];
					}
					y++;
					arr[k]=3657;
				}
			}
			if(arr[i]!=3657)
				cout<<arr[i]<<" "<<y;
			y=0;
		}
	}
	int sumdigit()
	{       int s=0,a;
		while(num!=0)
		{       a=num%10;
			num=num/10;
			s=s+a;
		}
		cout<<"\nSum="<<s;
		return (0);
	}
};



void main()
{	clrscr();
	int n;
	cout<<"\nEnter number : ";
	cin>>n;
	number obj(n);
	obj.digitfrequency();
	obj.sumdigit();
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

