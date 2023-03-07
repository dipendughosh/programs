#include<stdio.h>
#include<conio.h>

void main()
{       int a[20],i,row,j,n,x,y;
	clrscr();
	a[0]=1;
	n=0;
	printf("How many rows : ");
	scanf("%d",&row);
	for(i=0;i<row;i++)
	{	x=0;
		for(j=0;j<40-i;j++)
			printf(" ");
		for(j=0;j<n;j++)
		{	printf("%d ",x+a[j]);
			y=a[j];
			a[j]=x+a[j];
			x=y;
		}
		printf("1\n");
		n++;
		a[j]=1;
	}

	getch();
}

