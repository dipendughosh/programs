#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int arr[4][4],i,j,temp;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			cin>>arr[i][j];
	for(i=0;i<4;i++)
	{	for(j=0;j<4;j++)
			cout<<arr[i][j]<<"\t";
		cout<<"\n";
	}
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(i<=j)
			{
				temp=arr[i][j];
				arr[i][j]=arr[j][i];
				arr[j][i]=temp;
			}

		}
	cout<<endl<<endl;
	for(i=0;i<4;i++)
	{	for(j=0;j<4;j++)
			cout<<arr[i][j]<<"\t";
		cout<<"\n";
	}
	getche();
}

