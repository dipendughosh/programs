#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<process.h>
void main()
{
	clrscr();
	int arr[5][8];
	int p=1;
	for(int row=0;row<5;row++)
	{
		if(row%2==0)
		{
			for(int i=0;i<8;i++)
			{
				arr[row][i]=p++;
			}


		}
		else

		{	for(int j=7;j>=0;j--)
			{       arr[row][j]=p++;
			}

		}
	}
	cout<<"\nMatrix is.....\n\n\n";
	for(row=0;row<5;row++)
	{
		for(int col=0;col<8;col++)
			cout<<"\t"<<arr[row][col];
		cout<<endl<<endl;
	}
	getch();
}
