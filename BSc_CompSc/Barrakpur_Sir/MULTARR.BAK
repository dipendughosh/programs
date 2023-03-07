//* MULTIPLICATION OF 2 DYNAMIC MATRIX*
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{	int n=10,m=10,p=10,q=10,i,k,j;
	int a[10][10],b[10][10],c[10][10];
	clrscr();
	printf("ROW OF ARRAY A:");
	scanf("%d",&n);
	printf("\nCOLUMN OF ARRAY A:");
	scanf("%d",&m);
	printf("\nROW OF ARRAY B:");
	scanf("%d",&p);
	printf("\nCOLUMN OF ARRAY B:");
	scanf("%d",&q);
	if(m==p)
	{
		printf("\nVALUES OF ARRAY A\n");
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&a[i][j]);
		printf("\nVALUES OF ARRAY B\n");
		for(i=0;i<p;i++)
			for(j=0;j<q;j++)
				scanf("%d",&b[i][j]);
		for(i=0;i<n;i++)
			for(j=0;j<q;j++)
				c[i][j]=0;
		for(i=0;i<n;i++)
			for(j=0;j<q;j++)
				for(k=0;k<m;k++)
					c[i][j]+=a[i][k]*b[k][j];
		printf("\nARRAY A\n");
		for(i=0;i<n;i++)
		{	for(j=0;j<m;j++)
			{	printf("%d\t",a[i][j]);
			}
			printf("\n");
		}
		printf("\nARRAY B\n");
		for(i=0;i<p;i++)
		{	for(j=0;j<q;j++)
			{	printf("%d\t",b[i][j]);
			}
			printf("\n");
		}
		printf("\nARRAY C\n");
		for(i=0;i<n;i++)
		{	for(j=0;j<q;j++)
			{	printf("%d\t",c[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf("\nMultiplication not possible:");
	getche();
}
