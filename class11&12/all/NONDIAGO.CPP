#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
void main()
{	clrscr();
	void nondiago(int [3][3]);
	int i,j,a[3][3];
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
		{	cin>>a[i][j];
		}
	}
	cout<<"ARRAY\n";
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
		{	cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
	nondiago(a);
	getche();
}
void nondiago(int arr[3][3])
{	int i,j,k;
	/*for(k=0;k<100;k++)
	{	for(i=0;i<3;i++)
		{	for(j=0;j<3;j++)
			{	if(k!=arr[i][j])
				{	arr[i][j]=k;

				}
			}break;
		}
	}
	cout<<"K "<<k;
	for(i=0;i<3;i++)
	{	j=i;
		arr[i][j]=k;
	}
	j=3;
	for(i=0;i<3;i++)
	{	arr[i][j]=k;
		--j;
	}
	cout<<"ARRAY\n";
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
		{	cout<<arr[i][j]<<"\t";
		}
		cout<<"\n";
	}
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
		{	if(arr[i][j]!=k)
			{	cout<<arr[i][j]<<"\n";
			}
		}
	}
}         */
	for(i=0,j=4;i<3;i++,j--)
	{	arr[i][i]=0;
		arr[i][j]=0;
	}
	cout<<"ARRAY\n";
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
		{	cout<<arr[i][j]<<"\t";
		}
		cout<<"\n";
	}
}