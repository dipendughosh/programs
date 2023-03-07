//* MULTIPLICATION OF 2 DYNAMIC MATRIX*
#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{	clrscr();
	int n=10,m=10,p=10,q=10,i,k,j;
	cout<<"ROW OF ARRAY A:";
	cin>>n;
	cout<<"\nCOLUMN OF ARRAY A:";
	cin>>m;
	cout<<"\nROW OF ARRAY B:";
	cin>>p;
	cout<<"\nCOLUMN OF ARRAY B:";
	cin>>q;
	if(m==p)
	{	int a[10][10],b[10][10],c[10][10];
		cout<<"\nVALUES OF ARRAY A\n";
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				cin>>a[i][j];
		cout<<"\nVALUES OF ARRAY B\n";
		for(i=0;i<p;i++)
			for(j=0;j<q;j++)
				cin>>b[i][j];
		for(i=0;i<n;i++)
			for(j=0;j<q;j++)
				c[i][j]=0;
		for(i=0;i<n;i++)
			for(j=0;j<q;j++)
				for(k=0;k<m;k++)
					c[i][j]+=a[i][k]*b[k][j];
		cout<<"\nARRAY A\n";
		for(i=0;i<n;i++)
		{	for(j=0;j<m;j++)
			{	cout<<a[i][j]<<"\t";
			}
			cout<<"\n";
		}
		cout<<"\nARRAY B\n";
		for(i=0;i<p;i++)
		{	for(j=0;j<q;j++)
			{	cout<<b[i][j]<<"\t";
			}
			cout<<"\n";
		}
		cout<<"\nARRAY C\n";
		for(i=0;i<n;i++)
		{	for(j=0;j<q;j++)
			{	cout<<c[i][j]<<"\t";
			}
			cout<<"\n";
		}
	}
	else
		cout<<"\nMultiplication not possible:";
	getche();
}
