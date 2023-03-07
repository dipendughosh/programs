#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

void main()
{	clrscr();
	int i,j,a[2][2],b[2][2];
	cout<<"\nA\n";
	for(i=0;i<2;i++)
	{	for(j=0;j<2;j++)
		{	cin>>a[i][j];
		}
	}
	for(i=0;i<2;i++)
	{	for(j=0;j<2;j++)
		{	b[j][i]=a[i][j];
		}
	}
	cout<<"\nA\n";
	for(i=0;i<2;i++)
	{	for(j=0;j<2;j++)
		{	cout<<a[i][j];
		}
		cout<<"\n";
	}

	cout<<"\nA\n";
	for(i=0;i<2;i++)
	{	for(j=0;j<2;j++)
		{	cout<<b[i][j];
		}
		cout<<"\n";
	}
	getche();
}