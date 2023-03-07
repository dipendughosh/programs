#include<stdio.h>
#include<conio.h>

void main()
{       int a[3][2],b[2][3],c[3][3],i,j,k;
	clrscr();
	printf("A\n");
	for(i=0;i<3;i++)
		for(j=0;j<2;j++)
			scanf("%d",&a[i][j]);
	printf("B\n");
	for(i=0;i<2;i++)
		for(j=0;j<3;j++)
			scanf("%d",&b[i][j]);
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			c[i][j]=0;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			for(k=0;k<2;k++)
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
	printf("A\n");
	for(i=0;i<3;i++)
	{	for(j=0;j<2;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	printf("B\n");
	for(i=0;i<2;i++)
	{	for(j=0;j<3;j++)
			printf("%d\t",b[i][j]);
		printf("\n");
	}
	printf("C\n");
	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
			printf("%d\t",c[i][j]);
		printf("\n");
	}

	getch();
}

