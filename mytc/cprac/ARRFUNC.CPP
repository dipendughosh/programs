#include<iostream.h>
#include<conio.h>
void main()
{
	void input(int[],int);
	void output(int[],int);
	int arr[50],size;
	clrscr();
	cout<<"Size of array : "; cin>>size;
	input(arr,size);
	output(arr,size);
	getche();
}

void input(int a[],int s)
{
	for(int i = 0; i < s; i++)
	{
		cout<<"Enter number : "; cin>>a[i];
	}
}

void output(int a[], int s)
{
	for(int j = 0; j < s; j++)
		cout<<"\n"<<a[j];
}