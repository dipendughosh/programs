#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
void main()
{	clrscr();
	int num,i=0,x=0;
	void print(int []);
	int a[10]={3,11,5,2,0,32,7,34,77,21};
	print(a);
	int n[10];
	cout<<"\nEnter a number (<10) : ";  cin>>num;
	for(i=(num-1);i<10;i++)  n[x++]=a[i];
	for(int j=0;j<num;j++)  n[x++]=a[j];
	n[x]='\0';
	cout<<"\n";
	for(int p=0;p<10;p++) cout<<n[p]<<"  ";
	getch();
}

void print(int arr[])
{   for(int x=0;x<10;x++) cout<<arr[x]<<"  ";
	cout<<"\n";
}