//Binary search
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	clrscr();
	int arr[500];
	int input(int []);
	void sort(int[],int);
	void prn(int[],int);
	clrscr();
	int high,low=0,c=0,ser;
	high=input(arr);
	cout<<"\nOriginal array........\n";prn(arr,high);
	sort(arr,high);
	cout<<"\nSorted array..........\n";prn(arr,high);
	int mid;
	cout<<"\nEnter search term....";cin>>ser;
	do
	{
		mid=(high+low)/2;
		if(ser==arr[mid])
		{
			cout<<"\nFound  \nPosition is ..."<<mid+1;
			c=1;
			break;
		}
		if(ser>=arr[mid])
		{
			low=mid;
		}
		else
		{
			high=mid;
		}
	}
	while(low<high-1);
	if(c==0)
	{
		cout<<"\nSorry number is absent.........\n";
	}
	getch();
}
void sort(int a[],int size)
{
	int temp;
	for(int i=0;i<--size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(a[i]>=a[j])
			{
				//swaping the values
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
}
void prn(int x[],int size)
{
	cout<<"\n";
	for(int i=0;i<size;i++)
		cout<<x[i]<<"\t";
	cout<<endl;
}
int input(int a[])
{
	int size=0,x=0;
	while(x!=99)
	{
		cout<<"\nEnter Value........";cin>>x;
		if(x!=99)
			a[size++]=x;
	}
	return (size);
}
