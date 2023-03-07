#include<conio.h>
#include<iostream.h>
void main()
{
	clrscr();
	int arr[5][5];
	//the 2d array chosen is 5x5;
	int max,min;
	for(int row=0;row<5;row++)
	{
		for(int col=0;col<5;col++)
		{
			cout<<"\nEnter the data..-->";cin>>arr[row][col];
		}
	}
	//finding the largest number,smallest number
	max=arr[0][0];
	min=arr[0][0];
	for(row=0;row<5;row++)
	{
		for(int col=0;col<5;col++)
		{
			if(arr[row][col]>=max)
				max=arr[row][col];
			if(arr[row][col]<=min)
				min=arr[row][col];

		}
	}
	//printing the max & min values;
	for(row=0;row<5;row++)
	{
		for(int col=0;col<5;col++)
		{
			if(arr[row][col]==max)
				cout<<"\nMaximum number -->"<<arr[row][col]<<"\t";
			if(arr[row][col]==min)
				cout<<"\nMinimum number -->"<<arr[row][col]<<endl;

		}
	}
	getch();
}