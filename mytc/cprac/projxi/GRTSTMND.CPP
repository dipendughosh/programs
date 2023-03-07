#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	void inputarray(int,int[100][100])
	,outputarray(int,int[100][100]);
	int limit,arr[100][100],i,j = 0,max = 0;
	cout<<"\nenter limit for array \n";
	cin>>limit;
	inputarray(limit,arr);
	outputarray(limit,arr);
	for(i=0;i<limit;i++)
	{
		if(arr[i][j]>max)
			max = arr[i][j];
		j++;
	}
	cout<<"the greatest number of the main "
		<<"diagonal is "<<max;
	getche();
}
void inputarray(int l,int arr[100][100])
{
	int i,j;
	for(i = 0;i<l;i++)
	{
		for(j = 0;j<l;j++)
		{
			cout<<"enter a number \n";
			cin>>arr[i][j];
		}
	}
}
void outputarray(int l,int arr[100][100])
{
	int i,j;
	clrscr();
	cout<<"\nthe original array  is :::::\n";
	for(i = 0;i<l;i++)
	{
		for(j = 0;j<l;j++)
		{
			cout<<"\t"<<arr[i][j];
		}
		cout<<"\n";
	}
}
