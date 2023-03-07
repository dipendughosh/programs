//PASCAL'S TRIANGLE!
#include<iostream.h>
#include<conio.h>
void main()
{	clrscr();
	int arr[4][9],i,j;
	for(i=0;i<4;i++)
	{	for(j=0;j<9;j++)
			arr[i][j]=0;
	}
	arr[0][4]=1;
	for(i=1;i<=3;i++)
	{	for(j=1;j<8;j++)
		{
			arr[i][j]=arr[i-1][j-1]+arr[i-1][j+1];
		}
	}
	for(i=0;i<4;i++)
	{	for(j=0;j<9;j++)
		{  if(arr[i][j]==0)
				cout<<" ";
			else
				cout<<arr[i][j];
		 }
		 cout<<"\n";
	}
	getche();
}