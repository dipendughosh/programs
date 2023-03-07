#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
int i=0,j=0;
void main()
{	clrscr();
	void swap(int&,int&);
	void print(int []);
	int a[10]={3,11,5,2,0,32,7,34,77,21};
	int temp;
	for(i=0;i<9;i++)
	{	for(j=i+1;j<10;j++)
		{	if(a[i]>a[j]) swap(a[i],a[j]);
			print(a);getch();
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