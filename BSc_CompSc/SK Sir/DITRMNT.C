//diterminant
#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{       float a[20][20],x[20],r,s=1.0;
	int i,j,k,n;
	clrscr();
	printf("Enter number of equations-");
	scanf("%d",&n);
	printf("Enter Matrix-\n");
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{	printf("a[%d][%d]=",i,j);
			scanf("%f",&a[i][j]);
		}
	}
	for(k=0;k<n;k++)
	{	for(j=0;j<n;j++)
		{	if(k==j)
				continue;
			r=a[j][k]/a[k][k];
			for(i=0;i<n;i++)
			{	a[j][i]=a[j][i]-r*a[k][i];
			}
		}
	}
	for(i=0;i<n;i++)
	{	s=s*a[i][i];
	}
	printf("\nDitermanant value=%f",s);
	getch();
}
