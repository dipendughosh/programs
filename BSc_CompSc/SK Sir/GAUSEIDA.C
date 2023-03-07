//gauss seidal method
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{       float a[20][20],x[20],y[20],r;
	int i,j,k,n,flag;
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
	for(i=0;i<n;i++)
	{	x[i]=0.0;
		y[i]=0.0;
	}
	do
	{	flag=0;
		for(j=0;j<n;j++)
		{	x[j]=a[j][n];
			for(i=0;i<n;i++)
			{	if(i==j)
					continue;
				x[j]=x[j]-x[i]*a[j][i];
			}
			x[j]=x[j]/a[j][j];
		}
		for(i=0;i<n;i++)
		{       if(fabs(y[i]-x[i])>0.0005)
			{	flag=1;
				for(j=0;j<n;j++)
					y[j]=x[j];
				break;
			}
		 }
	}while(flag);
	printf("\nSolution is-\n");
	for(i=0;i<n;i++)
		printf("x%d = %.3f\n",i,x[i]);
	getch();
}

