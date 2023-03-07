#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	clrscr();
	int a[19][19],b[19],c[19];
	int d=0,x=0,max,min,size,pos;
	do
	{
		cout<<"\nEnter the size of array...";cin>>size;
	}
	while(size<0 || size>20);
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<"\nPlease enter data.....";cin>>a[i][j];
		}
	}
	clrscr();
	cout<<"OUTPUT  :-  \n";
	for(i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"\n\n";
	for(i=0;i<size;i++)
	{
		min=a[i][0];
		for(int j=0;j<size;j++)
		{
			if(a[i][j]<=min)
			{
				min=a[i][j];
				pos=j;
			}
		}
		b[i]=min;
		c[i]=pos;
		pos=0;
	}
	for(i=0;i<size;i++)
	{
		max=b[i];
		for(int j=0;j<size;j++)
		{
			if(max>=a[j][c[i]])
				d++;
		}
		if(d==size)
		{
			cout<<"\nSaddle apoint of the array is...:- "<<max<<endl;
			x=1;
			break;
		}
		max=0;
		d=0;
	}
	if(x==0)
		cout<<"\nSorry the matrix does not have a Saddle Point...."<<endl;
	getch();
}
