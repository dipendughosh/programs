//JUMBLING A THREE DIGIT NUMBER.
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	void prn(int[]);
	void swap(int[],int,int);
	int n,h,p=0;
	clrscr();
	int a[3];
	do
	{
		cout<<"\nEnter number....";cin>>n;
	}
	while(n>999 ||n<100);
	while(n>0)
	{
		h=n%10;
		n=n/10;
		a[p++]=h;
	}
	for(int i=1;i<=3;i++)
	{
		swap(a,0,1);
		prn(a);
		swap(a,1,2);
		prn(a);
	}
	getch();
}
void swap(int x[],int f1,int f2)
{
	int temp;
	temp=x[f1];
	x[f1]=x[f2];
	x[f2]=temp;
}
void prn(int a[])
{
	cout<<"\na possible combination...";
	for(int i=0;i<3;i++)
	{
		cout<<a[i];
	}
	cout<<endl;
}

