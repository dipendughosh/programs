#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

void main()
{	clrscr();
	int arr1[10][10],arr2[10][10],m,n,p,q,i,j;
	cout<<"Enter number of rows of array 1 : ";
	cin>>m;
	cout<<"\nEnter number of columns of array 1 : ";
	cin>>n;
	cout<<"\nEnter number of rows of array 2 : ";
	cin>>p;
	cout<<"\nEnter number of columns of array 2 : ";
	cin>>q;
	cout<<"\nARRAY 1\n ";
	for(i=0;i<m;i++)
	{	for(j=0;j<n;j++)
		{	cin>>arr1[i][j];
		}
	}
	cout<<"\nARRAY 2 \n";
	for(i=0;i<p;i++)
	{	for(j=0;j<q;j++)
		{	cin>>arr2[i][j];
		}
	}
	cout<<"\nARRAY 1 \n";
	for(i=0;i<m;i++)
	{	for(j=0;j<n;j++)
		{	cout<<arr1[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\nARRAY 2 \n";
	for(i=0;i<p;i++)
	{	for(j=0;j<q;j++)
		{	cout<<arr2[i][j]<<"\t";
		}
		cout<<"\n";
	}
	void sum(int [10][10],int,int,int [10][10]);
	void mult(int [10][10],int,int,int [10][10],int,int);
	void diag1(int [10][10],int);
	if(m==p && n==q)
	{	sum(arr1,m,n,arr2);
	}
	else
	{	cout<<"\nSUM NOT POSSIBLE ";
	}
	if(n==p)
	{	mult(arr1,m,n,arr2,p,q);
	}
	else
	{	cout<<"\nMULTIPLICATION NOT POSSIBLE ";
	}
	if(m==n)
	{	diag1(arr1,m);
	}
	else
	{	cout<<"\nARRAY 1 IS NOT A SQUARE MATRIX SO NO DIAGONAL ELLEMENTS ";
	}
	if(p==q)
	{	diag1(arr2,p);
	}
	else
	{	cout<<"\nARRAY 2 IS NOT A SQUARE MATRIX SO NO DIAGONAL ELLEMENTS ";
	}
	getche();
}
void sum(int a[10][10],int e,int d,int b[10][10])
{	int i,j,c[10][10];
	for(i=0;i<e;i++)
	{	for(j=0;j<d;j++)
		{	c[i][j]=a[i][j]+b[i][j];
		}
	}
	cout<<"\nSUM OF MATRIX \n";
	for(i=0;i<e;i++)
	{	for(j=0;j<d;j++)
		{	cout<<c[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
void mult(int a[10][10],int g,int d,int b[10][10],int e,int f)
{	int i,j,k,c[10][10];
	for(i=0;i<g;i++)
	{	for(j=0;j<f;j++)
		{	c[i][j]=0;
		}
	}
	for(i=0;i<g;i++)
	{	for(j=0;j<f;j++)
		{	for(k=0;k<d;k++)
			{	c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
			}
		}
	}
	cout<<"\nMULTIPLIED ARRAYS\n";
	for(i=0;i<g;i++)
	{	for(j=0;j<f;j++)
		{	cout<<c[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
void diag1(int a[10][10],int b)
{	int i,j,y=1;
	cout<<"\nDIAGONAL ELEMENTS OF ARRAY "<<y<<" ARE :\n";
	for(i=0;i<b;i++)
	{	j=i;
		cout<<a[i][j]<<"\t";
	}
	for(i=0;i<b;i++)
	{	for(j=0;j<b;j++)
		{	if((i+j)==(b-1))
			{	cout<<a[i][j]<<"\t";
			}
		}
	}
	cout<<"\n";
	++y;
}