//PASCAL'S TRIANGLE
//MAX SIZE 5X5
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	clrscr();
	int a[10][10];
	int row,col;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			a[i][j]=0;
		}
	}
	cout<<"\nEnter number of rows...........";cin>>row;
	clrscr();
	row++;
	col=(row*2)-1;col--;
	a[0][col/2]=1;
	a[row-2][0]=1;
	a[row-2][col-1]=1;
	cout<<endl<<endl;
	for(i=1;i<row;i++)
	{
		for(int j=1;j<col-1;j++)
		{
			a[i][j]=a[i-1][j-1]+a[i-1][j+1];
		}
	}
	cout<<"\nPASCAL'S TRIANGLE......\n\n";
	for(i=0;i<row-1;i++)
	{       cout<<"\t";
		for(int j=1;j<col;j++)
		{

			if(a[i][j]!=0)
				cout<<a[i][j]<<" ";
			else
				cout<<"  ";
		}
		cout<<endl;
	}
	getch();
}