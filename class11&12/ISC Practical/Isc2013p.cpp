#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>

class msort
{       int a[20],b[20],c[40],n,m,x;
	public:
	msort();
	void getarrs();
	void showarrs();
	void sort();
	~msort();
};

msort :: msort()
{       int i;
	for(i=0;i<20;i++)
	{	a[i]=0;
		b[i]=0;
		c[i]=0;
		c[i+10]=0;
	}
	m=0;
	n=0;
	x=0;
}

void msort::getarrs()
{       int i;
	cout<<"\nEnter number of elements in array A:- ";
	cin>>m;
	cout<<"\nEnter A:-\n";
	for(i=0;i<m;i++)
		cin>>a[i];
	cout<<"\nEnter number of elements in array B:- ";
	cin>>n;
	cout<<"\nEnter B:-\n";
	for(i=0;i<n;i++)
		cin>>b[i];
	x=m+n;
}

void msort::sort()
{	int i,j,k,temp,z=0;
	for(i=0;i<m-1;i++)
	{	for(j=i+1;j<m;j++)
		{	if(a[i]<=a[j])
			{	temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=0;i<n-1;i++)
	{	for(j=i+1;j<n;j++)
		{	if(b[i]<=b[j])
			{	temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
	for(i=0;i<m;i++)
		c[i]=a[i];
	j=i;
	for(i=0;i<n;i++)
	{	c[j]=b[i];
		j++;
	}
	for(i=0;i<x-1;i++)
	{	for(j=i+1;j<x;j++)
		{	if(c[i]<=c[j])
			{	temp=c[i];
				c[i]=c[j];
				c[j]=temp;
			}
		}
	}
	for(i=0;i<x-1;i++)
	{	for(j=i+1;j<x;j++)
		{	if(c[i]==c[j])
			{	for(k=j;k<x;k++)
				{	c[k]=c[k+1];
				}
				x--;
			}
		}
	}
}

void msort :: showarrs()
{       int i;
	clrscr();
	cout<<"\nA:-\n";
	for(i=0;i<m;i++)
		cout<<a[i]<<"\t";
	cout<<"\nB:-\n";
	for(i=0;i<n;i++)
		cout<<b[i]<<"\t";
	cout<<"\nC:-\n";
	for(i=0;i<x;i++)
		cout<<c[i]<<"\t";
}

msort :: ~msort()
{
}

void main()
{	clrscr();
	msort obj;
	obj.getarrs();
	obj.sort();
	obj.showarrs();
	getche();
}
