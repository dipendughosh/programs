//Prims
#include<stdio.h>
#include<conio.h>

struct set
{	int v1,v2,d;
};

void main()
{	int i,j,k,n,dist[50][50],x,y,min,z;
	struct set g[100];
	clrscr();
	printf("Enter number of vertices-");
	scanf("%d",&n);
	printf("\nEnter weights between the vertices\n\tIf no edge enter 999\n\tIf no self loop enter 999\n");
	for(i=1;i<=n;i++)
	{	for(j=1;j<=n;j++)
		{	printf("%d - %d=",i,j);
			scanf("%d",&dist[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{	for(j=1;j<=n;j++)
			printf("%d\t",dist[i][j]);
		printf("\n");
	}
	if(n==1)
	{	if(dist[1][1]==999)
			printf("\nOnly one vertex tree,no self loop");
		else
			printf("\nOnly one vertex tree,with self loop of weight %d",dist[1][1]);
	}
	else
	{	for(i=1;i<n;i++)
		{	min=dist[1][2];
			for(j=1;j<=z;j++)
			{	for(k=1;k<=n;k++)
				{ 	if(j==k)
						continue;
					if(min>=dist[j][k])
					{    	min=dist[j][k];
						x=j;
						y=k;
					}
				}
			}
			g[i].d=dist[x][y];
			g[i].v1=x;
			g[i].v2=y;
			dist[x][y]=dist[y][x]=999;
			if(x>y)
				z=x;
			else
				z=y;
		}
		for(i=1;i<n;i++)
			printf("\n%d - %d -> %d",g[i].v1,g[i].v2,g[i].d);
	}
	getch();
}

