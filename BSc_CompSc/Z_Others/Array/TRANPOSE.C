#include<stdio.h>
#include<conio.h>

void main()
{       int a[10][10],i,j,m,n,t;
	clrscr();
	printf("Enter number of rows:- ");
	scanf("%d",&m);
	printf("Enter number of columns:- ");
	scanf("%d",&n);
	printf("Enter elements of Matrice:-\n");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	clrscr();
	printf("\nEntered Matrice is:-\n");
	for(i=0;i<m;i++)
	{	for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	for(i=0;i<m;i++)
	{	for(j=i;j<n;j++)
		{	t=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=t;
		}
	}
	printf("\nThe Transposed Matrice is:-\n");
	for(i=0;i<n;i++)
	{	for(j=0;j<m;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	getch();
}

