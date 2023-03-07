#include<conio.h>
#include<iostream.h>
#include<process.h>
void main()
{
	clrscr();
	int a[15];
	int size,no,pos;
	do
	{
		cout<<"\nEnter size of array..max size -- 14..-->";cin>>size;
	}
	while(size>14);
	for(int i=0;i<size;i++)
	{
		cout<<"\nEnter the "<<i+1<<"th value..-->";cin>>a[i];
	}
	void sort(int[],int);
	sort(a,size);
	cout<<"\nArray after sorting the digits..-->";
	void print(int[],int);
	print(a,size);
	cout<<"\nNumber to be inserted is..-->";cin>>no;
	cout<<"\nModified array is as follows..-->";
	if(no<a[0])
		pos=0;
	else
		if(no>=a[size-1])
		{
			a[size]=no;
			print(a,size+1);
			getch();
			exit(0);
		}
		else
		{
			for(int i=1;i<size;i++)
			{
				if(no>=a[i-1] && no<=a[i])
				{
					pos=i;
					break;
				}
			}
		}
	for(i=size;i>=pos+1;i--)
		a[i]=a[i-1];
	a[pos]=no;
	print(a,size+1);
	getch();
}
void sort(int x[],int length)
{
	int temp;
	for(int i=0;i<length-1;i++)
	{
		for(int j=i+1;j<length;j++)
		{
			if(x[i]>x[j])
			{
				temp=x[i];
				x[i]=x[j];
				x[j]=temp;
			}
		}
	}
}
void print(int x[],int length)
{       cout<<endl;
	for(int i=0;i<length;i++)
		cout<<x[i]<<"   ";
	cout<<endl;
}

