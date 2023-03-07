#include<stdio.h>
#include<conio.h>

void main()
{       int a[10][10],n,m,i,j,k,f,f1;
	clrscr();
	printf("Enter rows of A, m = ");
	scanf("%d",&m);
	printf("Enter columns of A, n = ");
	scanf("%d",&n);
	printf("A\n");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	clrscr();
	printf("\nA\n");
	for(i=0;i<m;i++)
	{	for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	for(i=0;i<m;i++)
	{	for(j=0;j<n;j++)
		{	for(k=0;k<n;k++)
			{	if(a[i][j]<a[i][k])
					f=1;
				else
				{	f=0;
					break;
				}
			}
			if(f==1)
			{	for(k=0;k<m;k++)
				{	if(a[i][j]>a[k][j])
						f1=1;
					else
					{	f1=0;
						break;
					}
				}
			}
			if(f1==1 && f==1)
				printf("\n%d",a[i][j]);
		}
	}
	getch();
}

