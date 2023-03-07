#include<stdio.h>
#include<conio.h>

struct set
{	int v1,v2,d;
};

void main()
{       int i,j,n,dist[50][50],x=0;
	struct set g[100],t;
	clrscr();
	printf("Enter number of verticesl-");
	scanf("%d",&n);
	printf("\nEnter weights between the vertices-\n");
	for(j=1;j<=n;j++)
	{	scanf("%d",&dist[i]);
		g[x].v1=i;
		g[x].v2=j;
		g[x].d=dist[i][j];
		x++;
	}
	for(i=1;i<=x-1;i++)
	{       for(j=1;j<=x-1-i;j++)
		{	if(g[j].d>g[j+1].d)
			{       t=g[j];
				g[j]=g[j+1];
				g[j+1]=t;
			}
		}
	}
	for(i=0;i<x;i++)
	{	if(g[i].d==g[i+1].d)
		{	for(j=i+1;j<x;j++)
				g[j]=g[j+1];
			x--;
		}
	}
	for(i=0;i<x;i++)
		printf("\n%d - %d -> %d",g[i].v1,g[i].v2,g[i].d);



	getch();
}

