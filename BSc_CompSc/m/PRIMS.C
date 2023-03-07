//prim's algorithm
#include<stdio.h>
#include<conio.h>


void main()
{       float lcost[8],a[8][8];
	int clost[8],i,j,k,min,n;
	clrscr();
	printf("\nEnter number of vertices - ");
	scanf("%d",&n);
	printf("\nEnter weights between the vetices,if no edge between vertices enter 999\n");
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		if(i==j)
			dist[i][j]=0;
		else
		{	printf("%d - %d = ",i+1,j+1);
			scanf("%d",&dist[i][j]);
		}
	}
	min=
	for(i=2;i<=n;++i)
	{	lcost[i]=a[1][i];
		clost[i]=1;
	}
	printf("Mnimum cost spanning tree are:\n");
	for(i=2;i<=n;++i)
	{	min=lcost[2];
		k=2;
		for(j=3;j<=n;++j)
			if(lcost[j]<min)
			{	min=lcost[j];
				k=j;
			}
		printf("%d\t%d\n",k,clost[k]);
		lcost[k]=200;
		for(j=2;j<=n;++j)
			if((a[k][j]<lcost[j]) && (lcost[j]<200))
			{	lcost[j]=a[k][j];
				clost[j]=k;
			}
	}
	getch();
}

