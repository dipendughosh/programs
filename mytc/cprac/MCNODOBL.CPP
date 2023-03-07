#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	void input(int[],int);
	void output(int[],int);
	int select(int[],int,int,int);
	int arr[50],size,i;
	cout<<"enter size of array ===>";
	cin>>size;
	input(arr,size);
	cout<<"\noutput of original array " ;
	output(arr,size);
	int out[50],l=1,y,p=0,u;
	out[0] = arr[0];
	for(i = 1;i<size;i++)
	{
		y = arr[i];
		if(select(out,p,l,y)==0)
		{
			out[l]=y;
			l++;
		}
		y = out[l];
	}
	cout<<endl;
	for(u=0;u<l;u++)
	{
		cout<<" "<<out[u];
	}
	getche();
}
void input(int a[],int s)
{
	for(int i =0;i<s;i++)
	{
		cout<<"enter number ";
		cin>>a[i];
	}
}
void output(int a[],int s)
{
	for(int i = 0;i<s;i++)
	{
		cout<<" "<<a[i];
	}
}
int select(int a[],int s,int x,int z)
{
	while(s<x)
	{
		if(a[s]==z)
		{
			return 1;
		}
		s++;
	}
	return 0;
}
