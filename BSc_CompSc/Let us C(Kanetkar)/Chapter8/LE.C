#include<stdio.h>
#include<conio.h>

void main()
{       int a[6][6],b[6][6],c[6][6],i,j,k;
	clrscr();
	printf("A\n");
	for(i=0;i<6;i++)
		for(j=0;j<6;j++)
			scanf("%d",&a[i][j]);
	printf("B\n");
	for(i=0;i<6;i++)
		for(j=0;j<6;j++)
			scanf("%d",&b[i][j]);
	for(i=0;i<6;i++)
		for(j=0;j<6;j++)
			c[i][j]=a[i][j]+b[i][j];
	printf("\nA\n");
	for(i=0;i<6;i++)
	{	for(j=0;j<6;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	printf("\nB\n");
	for(i=0;i<6;i++)
	{	for(j=0;j<6;j++)
			printf("%d\t",b[i][j]);
		printf("\n");
	}
	printf("\nC\n");
	for(i=0;i<6;i++)
	{	for(j=0;j<6;j++)
			printf("%d\t",c[i][j]);
		printf("\n");
	}
	getch();
	clrscr();
	printf("A\n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	printf("B\n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&b[i][j]);
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			c[i][j]=0;
	clrscr();
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			for(k=0;k<3;k++)
				c[i][j]=c[i][j]+(a[i][j]*b[j][k]);
	printf("\nA\n");
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	printf("\nB\n");
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
			printf("%d\t",b[i][j]);
		printf("\n");
	}
	printf("\nC\n");
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
			printf("%d\t",c[i][j]);
		printf("\n");
	}
	getch();
}

