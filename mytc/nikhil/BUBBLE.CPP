#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>

void main()
{   clrscr();
	void swap(int&,int&);
	void print(int []);
	int a[10]={3,11,5,2,0,32,7,34,77,21};
	int temp;
	for(int i=1;i<9;i++)
	{	for(int j=0;j<10-i;j++)
		{	if(a[j]>a[j+1])
			{	swap(a[j],a[j+1]);
				print(a);getch();
			}
		}
	}
	getch();
}

void swap(int &p,int &q)
{	int temp;
	temp=p;
	p=q;
	q=temp;
}

void print(int arr[])
{	for(int x=0;x<10;x++) cout<<arr[x]<<"  ";
	cout<<"\n";
}