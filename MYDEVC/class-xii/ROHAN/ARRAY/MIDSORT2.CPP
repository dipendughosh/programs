//lucky number my style
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	clrscr();
	int c=1,p=-1,pl=3,pos,m,k=0;
	int findlarge(int[],int);
	void prn(int[]);
	int largepos(int[],int);
	void swap(int[],int,int);
	int a[7]={ 19,8,36,43,98,81,17 };
	int large=a[0];
	prn(a);
	getch();
	for(int i=0;i<7;i++)
	{
		if(a[i]>=large)
		{
			large=a[i];
			pos=i;
		}
	}
	getch();
	swap(a,pl,pos);
	for(int j=1;j<6;j++)
	{
		large=findlarge(a,large);
		pos=largepos(a,large);
		++k;
		m=c*p;
		p=p*-1;
		pl=3-m;
		if(k==2)
		{
			c++;
			k=0;
		}
		swap(a,pl,pos);
		prn(a);
		getch();
	}
	prn(a);
	getch();
}
int findlarge(int a[],int xmax)
{
	int big=-32600;
	for(int i=0;i<7;i++)
	{
		if(a[i]>=xmax)
			continue;
		if(a[i]>big)
			big=a[i];
	}
	return big;
}
int largepos(int a[],int search)
{
	int xx;
	for(int i=0;i<7;i++)
		if(a[i]==search)
			xx=i;
	return xx;
}
void prn(int a[])//,int p1,int p2)
{       cout<<endl;
	for(int i=0;i<7;i++)
		cout<<a[i]<<"\t";
}
void swap(int a[],int p1,int p2)
{
	int temp;
	temp=a[p1];
	a[p1]=a[p2];
	a[p2]=temp;
}