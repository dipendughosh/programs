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
	print(a,size);
	cout<<"\nSTEPS..........\n";
	for(int i=0;i<size;i++)
	{
		temp=a[i];
		count=i-1;
		while(temp<a[count] && count>=0)
		{
			a[count +1]=a[count--];
		};
		a[count+1]=temp;
		print(a,size);
	}
	cout<<"\nSORTED ARRAY IS...........\n";
	print(a,size);
	getch();
}
void input(int x[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<"\nENTER NUMBER...........";cin>>x[i];
	}
}
void print(int x[],int len)
{
	cout<<"\nARRAY IS..............\n";
	for(int i=0;i<len;i++)
	{
		cout<<x[i]<<"\t";
	}
}