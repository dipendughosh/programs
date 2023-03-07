//SORTING A VECTOR IN BUBBLE SORT MANNER
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	int size,temp,count;
	clrscr();
	int a[100];
	cout<<"\nENTER SIZE OF ARRAY.............";cin>>size;
	void input(int[],int);
	void print(int[],int);
	input(a,size);
	clrscr();
	cout<<"\nENTERED ARRAY IS.....";
	print(a,size);
	void sort(int[],int);
	sort(a,size);
	cout<<"\nSORTED ARRAY IS......";
	print(a,size);
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
void input(int x[],int length)
{       cout<<endl;
	for(int i=0;i<length;i++)
	{	cout<<"\nEnter numbers......";cin>>x[i];	}
	cout<<endl;
}
