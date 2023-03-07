#include<stdio.h>
#include<conio.h>

void main()
{       int a[5][5],b[5][5],i,j;
	clrscr();
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			b[j][i]=a[i][j];
	for(i=0;i<5;i++)
	{	for(j=0;j<5;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	for(i=0;i<5;i++)
	{	for(j=0;j<5;j++)
			printf("%d\t",b[i][j]);
		printf("\n");
	}
	getch();
}

