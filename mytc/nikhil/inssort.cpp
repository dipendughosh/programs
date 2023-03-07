#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>

void main()
{   clrscr();
	void swap(int&,int&);
	void print(int []);
	int a[10]={3,11,5,2,0,32,7,34,77,21};
	print(a);
	cout<<"\n";
	int temp;
	for(int i=0;i<9;i++)
	{	temp=a[i];
		for(int j=i;j<10;j++)
		{   if(a[j]<temp)
			{	for(int x=0;x<j;x++) a[x]=a[x+1];
				a[j]=temp;
			}
		}
		print(a); getch();
	}
	getch();
}


void print(int arr[])
{	for(int x=0;x<10;x++) cout<<arr[x]<<"  ";
	cout<<"\n";
}