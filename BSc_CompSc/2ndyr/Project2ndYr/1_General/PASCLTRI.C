//Pascal's Triangle
#include<stdio.h>
#include<conio.h>

void main()
{       //Declaring variables
	int a[20],arr[20][20],i,row,j,k,n,x,y;
	//clrscr();
	a[0]=1;
	n=0;
	printf("How many rows : ");
	scanf("%d",&row);
	//Creating the Pascal's Triangle
	for(i=0;i<row;i++)
	{	x=0;
		for(j=0;j<40-i;j++)
			arr[i][j]=0;
		for(j=0;j<n;j++)
		{       arr[i][j]=x+a[j];
			y=a[j];
			a[j]=x+a[j];
			x=y;
		}
		arr[i][j]=1;
		n++;
		a[j]=1;
	}
	//Displaying the Pascal's Triangle
	for(i=0;i<row;i++)
	{       for(k=0;k<40-i;k++)
			printf(" ");
		for(j=0;j<n;j++)
		{	if(arr[i][j]!=0)
				printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	getch();
}

