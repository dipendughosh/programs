#include<conio.h>
#include<complex.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	clrscr();
	int number,start,count=0;
	char ch;
do
{
	clrscr();
	count=0;
	cout<<"\nEnter number....--> ";cin>>number;
	for(int i=1;i<number;i++)
	{
		start=i;
		for(int j=i+1;j<=number;j++)
		{
		       start+=j;
		       if(start==number)
		       {
				cout<<"\nNumber's are (";
				for(int k=i;k<=j;k++)
				{	cout<<k<<" ";	}
				cout<<")"<<endl;
				count++;
		       }
		       if(start>number)
				break;
		}
	}
	if(count==0)
	{
		cout<<"\nSorry no such sets....";
	}
	cout<<"\nWant to continue...(Y/N)..--> ";cin>>ch;
 }
 while(ch=='Y');
 cout<<"\nExiting programme.....";
	getch();
}
