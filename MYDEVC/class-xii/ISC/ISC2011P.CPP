#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>

class lucky
{	int arr[50],n,i,j;
	public:
	lucky()
	{	for(i=0;i<50;i++)
			arr[i]=0;
	}
	lucky(int x)
	{	n=x;
		for(i=0;i<n;i++)
			arr[i]=i+1;
	}
	void showarr()
	{	for(i=0;i<n;i++)
			cout<<arr[i]<<"\t";
	}
	void findluckyno()
	{       int x=2;
		cout<<"\n";
		for(i=0;i<n;i++)
		{       for(j=0;j<n;j++)
			{	arr[j]=arr[j+x];
			}
			x++;
		}
		for(i=0;i<n;i++)
			cout<<arr[i]<<"\t";

	}
};
void main()
{	clrscr();
	int n;
	cout<<"\nEnter n";
	cin>>n;
	lucky obj(n);
	obj.showarr();
	obj.findluckyno();


	getche();
}
