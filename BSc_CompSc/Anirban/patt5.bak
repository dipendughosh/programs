# include <stdio.h>
# include <conio.h>
void main()
{
int a[10][10];
int n=0,i,j,k=1,l=1;
printf("enter the number of rows");
scanf("%d",&n);
for(i=0;i<=n-1;i++)
{
	if((i%2)==0)
		{
			for(j=0;j<=n-1;j++)
				{
					a[i][j]=k;
					k=k+1;
				}
		}
	else
		{
			for(j=0;j<=n-1;j++)
				{
					a[i][j]=l+8;
					l++;
				}
		}
}
for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			printf("%d ",a[i][j]);
		}
	printf("\n");
	}
getch();
}