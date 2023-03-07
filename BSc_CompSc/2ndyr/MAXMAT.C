#include<stdio.h>
#include<conio.h>


void main()
{       int i,j,k,dist[80][80],min,x,y;
	clrscr();
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			scanf("%d",&dist[i][j]);
	for(i=1;i<=3;i++)
	{	for(j=1;j<=3;j++)
			printf("%d\t",dist[i][j]);
		printf("\n");
	}
	for(i=1;i<3;i++)
	{	min=dist[2][1];
		for(j=1;j<=3;j++)
		{	for(k=1;k<=3;k++)
			{ 	if(min>=dist[j][k])
				{	min=dist[j][k];
					x=j;
					y=k;
				}
			}
		}
		printf("\n%d %d %d",x,y,min);
		dist[x][y]=dist[y][x]=999;
	}
	getch();
}

