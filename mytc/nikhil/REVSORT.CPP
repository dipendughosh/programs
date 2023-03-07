#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
void main()
{   clrscr();
	void swap(int &,int &);
	void print(int []);
	int num,i=0,j;
	int a[10]={3,11,5,2,0,32,7,34,77,21};
	print(a);
	cout<<"\n";
	cout<<"Enter a number (<10) : ";  cin>>num;
	for(i=0,j=num-1;i<num/2;i++,j--)  swap(a[i],a[j]);
	cout<<"\n";
	print(a);
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