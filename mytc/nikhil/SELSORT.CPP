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
	int temp,p;
	for(int i=0;i<9;i++)
	{   temp=a[i];
		for(int j=i+1;j<10;j++)
		{   if(a[j]<temp) {temp=a[j];p=j;}
		}
		cout<<"\n";
		swap(a[i],a[p]);
		print(a); getch();
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