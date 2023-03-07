//Prims
#include<stdio.h>
#include<conio.h>

struct set
{	int v1,v2,d;
};

void main()
{       struct set g[100];
	int i,j,n,dist[50][50],x=0,nd[50],min,k,y,c;
	clrscr();
	printf("Enter number of vertices -");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		nd[i]=0;
	printf("\nEnter weights between the vertices,if no edge enter 999\n");
	for(i=1;i<=n;i++)
	{	for(j=1;j<=n;j++)
		{	if(i==j)
				dist[i][j]=0;
			else
			{	printf("%d - %d=",i,j);
				scanf("%d",&dist[i][j]);
				if(dist[i][j]==999)
					continue;
				else
					nd[i]++;
			}
		}
	}
	printf("\nIs the entered Graph \n1.Directed\n2.UnDirected\n");
	scanf("%d",&c);
	for(i=1;i<n;i++)
	{	min=dist[1][2];
		for(j=1;j<=n;j++)
		{	for(k=1;k<=n;k++)
			{       if(j==k)
					continue;
				if(min>=dist[j][k])
				{	if(nd[k]>0 && nd[j]>0)
					{	min=dist[j][k];
						x=j;
						y=k;
					}
				}
			}
		}
		printf("\n%d %d %d",x,y,min);
		--nd[x];
		--nd[y];
		g[i].v1=x;
		g[i].v2=y;
		g[i].d=dist[x][y];
		if(c==2)
			dist[x][y]=dist[y][x]=999;
		else
		{	if(dist[x][y]==dist[y][x])
				dist[x][y]=dist[y][x]=999;
			else
				dist[x][y]=999;
		}
	}
	for(i=1;i<n;i++)
		printf("\n%d - %d -> %d",g[i].v1,g[i].v2,g[i].d);



	getch();
}

