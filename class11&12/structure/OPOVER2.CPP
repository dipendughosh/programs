//MATRIX
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

struct matrix
{       int arr[3][3];
};

matrix operator +(matrix,matrix);
matrix operator -(matrix,matrix);
matrix operator *(matrix,matrix);
void main()
{	clrscr();
	matrix a,b,c;
	int i,j;
	cout<<"\nElements of A->\n";
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			cin>>a.arr[i][j];
	cout<<"\nElements of B->\n";
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			cin>>b.arr[i][j];
	clrscr();
	cout<<"\nARRAY A->\n";
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
			cout<<a.arr[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\nARRAY B->\n";
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
			cout<<b.arr[i][j]<<" ";
		cout<<"\n";
	}
	c=a+b;
	cout<<"\nADDITION->\n";
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
			cout<<c.arr[i][j]<<" ";
		cout<<"\n";
	}
	c=a-b;
	cout<<"\nSUBTRACTION->\n";
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
			cout<<c.arr[i][j]<<" ";
		cout<<"\n";
	}
	c=a*b;
	cout<<"\nMULTIPLICATION->\n";
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
			cout<<c.arr[i][j]<<" ";
		cout<<"\n";
	}
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

matrix operator +(matrix a,matrix b)
{	matrix c;
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			c.arr[i][j]=a.arr[i][j]+b.arr[i][j];
	return c;
}

matrix operator -(matrix a,matrix b)
{	matrix c;
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			c.arr[i][j]=a.arr[i][j]-b.arr[i][j];
	return c;
}

matrix operator *(matrix a,matrix b)
{	matrix c;
	int i,j,k;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			c.arr[i][j]=0;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			for(k=0;k<3;k++)
				c.arr[i][j]=c.arr[i][j]+(a.arr[i][k]*b.arr[k][j]);
	return c;
}




























































































































