#include<stdio.h>
#include<conio.h>

void main()
{       int a[10][10],row,col,i,j;
	clrscr();
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			a[i][j]=0;
	printf("Enter number of rows...........");
	scanf("%d",&row);
	clrscr();
	row++;
	col=(row*2)-1;
	col--;
	a[0][col/2]=1;
	a[row-2][0]=1;
	a[row-2][col-1]=1;
	for(i=1;i<row;i++)
		for(j=1;j<col-1;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j+1];
	printf("PASCAL'S TRIANGLE......\n\n");
	for(i=0;i<row-1;i++)
	{       printf(" ");
		for(j=1;j<col;j++)
		{	if(a[i][j]!=0)
				printf("%d ",a[i][j]);
			else
				printf("  ");
		}
		printf("\n");
	}
	getch();
}

