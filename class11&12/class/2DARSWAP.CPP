//2 d array transpose,1 d array making after the size
#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<iomanip.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<dos.h>

class a1darr
{	private:
	int x,*a;
	public:
	a1darr()
	{	x=0;
		a=new int[x];
	}
	void getdata();
	void showdata();
	~a1darr()
	{
	}
};

void a1darr::getdata()
{	int i;
	cout<<"\nEnter number of elements in array: ";
	cin>>x;
	cout<<"Enter data of array:\n";
	for(i=0;i<x;i++)
		cin>>a[i];
}

void a1darr::showdata()
{	int i;
	cout<<"Array Data:\n";
	for(i=0;i<x;i++)
		cout<<a[i]<<"\t";
}

class a2darr
{	private:
	int x,*a;
	public:
	a2darr()
	{	x=0;
		a=new int[x*x];
	}
	void getdata();
	void showdata();
	void transpose();
	~a2darr()
	{
	}
};

void a2darr::getdata()
{	int i,j;
	cout<<"\nEnter number of column and row: ";
	cin>>x;
	cout<<"Enter data of array:\n";
	for(i=0;i<x;i++)
		for(j=0;j<x;j++)
			cin>>a[i*x+j];
}

void a2darr::showdata()
{	int i,j;
	cout<<"Array Data:\n";
	for(i=0;i<x;i++)
	{	for(j=0;j<x;j++)
			cout<<a[i*x+j]<<"\t";
		cout<<"\n";
	}
}

void a2darr::transpose()
{	int i,j,temp;
	for(i=0;i<x;i++)
		for(j=i;j<x;j++)
		{	temp=a[i*x+j];
			a[i*x+j]=a[j*x+i];
			a[j*x+i]=temp;
		}
}

void main()
{	clrscr();
	cout<<"\n\t\t1 D ARRAY";
	a1darr obj1;
	obj1.getdata();
	obj1.showdata();
	cout<<"\n\t\t2 D ARRAY";
	a2darr obj2;
	obj2.getdata();
	obj2.showdata();
	obj2.transpose();
	obj2.showdata();
	getche();
}
