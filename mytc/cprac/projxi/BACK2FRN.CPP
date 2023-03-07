#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int row,column,i,j,flag=1;char arrout[15][15];
	char character ='A';
	cout<<"enter limits for array ";
	cin>>row>>column;
	for(i = 0;i<column;i++)
	{
		if(flag == 1)
		{
			for(j=0;j<row;j++)
				arrout[j][i]=character++;
		}
		else
		{
			for(j=row-1;j>=0;j--)
			{	arrout[j][i]=character++;
			}
		}
		flag *= -1;
	}
	cout<<"\n";
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			cout<<arrout[i][j]<<" ";
		}
		cout<<"\n";
	}
	getche();
}