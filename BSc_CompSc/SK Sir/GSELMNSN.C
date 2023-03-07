//gauss elemination method
#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{       float a[20][20],x[20],r;
	int i,j,k,n;
	clrscr();
	printf("Enter number of equations-");
	scanf("%d",&n);
	printf("Enter co-efficient Matrix with R.H.S-\n");
	for(i=0;i<n;i++)
	{	for(j=0;j<=n;j++)
		{	printf("a[%d][%d]=",i,j);
			scanf("%f",&a[i][j]);
		}
	}
	for(k=0;k<n;k++)
	{	for(j=k+1;j<n;j++)
		{	r=a[j][k]/a[k][k];
			for(i=0;i<=n;i++)
			{	a[j][i]=a[j][i]-r*a[k][i];
			}
		}
	}
	x[n-1]=a[n-1][n]/a[n-1][n-1];
	for(j=n-2;j>=0;j--)
	{	x[j]=a[j][n];
		for(i=n-1;i>j;i--)
		{	x[j]=x[j]-a[j][i]*x[i];
		}
		x[j]=x[j]/a[j][j];
	}
	printf("The solution is .........\n");
	for(i=0;i<n;i++)
	{	printf("x%d=%f\n",i,x[i]);
	}
	getch();
}

