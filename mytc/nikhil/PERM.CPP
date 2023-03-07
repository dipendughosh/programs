#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
int i,m=0;
void swap(int x[],int p,int q);
void print(int arr[]);
void main()
{   clrscr();
	int a[3]={1,2,3};
	for(i=0;i<3;i++)
	{
	swap(a,0,1);
	print(a);
	swap(a,1,2);
	print(a);
	}
	getch();
}

void swap(int x[],int p,int q)
{   int temp;
	temp=x[p];
	x[p]=x[q];
	x[q]=temp;
}

void print(int arr[])
{	for(int x=0;x<3;x++) cout<<arr[x]<<"  ";
	cout<<"\n";
}