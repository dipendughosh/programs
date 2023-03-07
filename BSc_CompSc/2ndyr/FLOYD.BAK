//Floyd's-Warshall
#include<stdio.h>
#include<conio.h>

void main()
{       //declaring variables
	int dist[10][10],i,j,k,n;
	clrscr();
	//Entering the weighted matrix
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
	//Displaying the enetred matrix
	printf("\nPrinting the originalmatrix\n\nVertices");
	for(i=0;i<n;i++)
		printf("\t%d",i+1);
	printf("\n");
	for(i=0;i<n;i++)
	{       printf("\n    %d\t",i+1);
		for(j=0;j<n;j++)
			printf("\t%d",dist[i][j]);
	}
	//Finding the minimum weights between all pairs of vertices
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				if(dist[j][i]+dist[i][k]<dist[j][k])
					dist[j][k]=dist[j][i]+dist[i][k];
	//Displaying the minimum weighted katrix
	printf("\n\nThe minimum wieghts between all vertices\n");
	printf("\nVertices");
	for(i=0;i<n;i++)
		printf("\t%d",i+1);
	printf("\n");
	for(i=0;i<n;i++)
	{       printf("\n    %d\t",i+1);
		for(j=0;j<n;j++)
			printf("\t%d",dist[i][j]);
	}
	getch();
}

