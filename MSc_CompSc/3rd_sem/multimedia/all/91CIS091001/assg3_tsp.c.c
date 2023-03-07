#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void main()
{
	int n, **adj, i, j, strt, visiting, *visited, nextvisit, distance=0;
	clrscr();
	printf("\nENTER NUMBER OF CITIES: ");
	scanf("%d", &n);

	visited=(int*)malloc(n*sizeof(int));
	adj=(int**)malloc(n*sizeof(int*));
	for(i=0; i<n; i++)
	{
		*(adj+i)=(int*)malloc(n*sizeof(int));
	}
	printf("\nAUTO GENERATED WEIGHT MATRIX IS:\n");
	for(i=0; i<n; i++)
	{       adj[i][i]=0;
		visited[i]=0;
		for(j=i+1; j<n; j++)
		{
			adj[j][i]=adj[i][j]=random(20)+random(9)+1;
		}
	}
	printf("\n  |");
	for(i=0; i<n; i++)
		printf("%2d  ", i);
	printf("\n__|");
	for(i=0; i<n; i++)
		printf("____", i);
	printf("\n");
	for(i=0; i<n; i++)
	{
		printf("%2d|", i);
		for(j=0; j<n; j++)
		{
			printf("%2d  ", adj[i][j]);
		}
		printf("\n");
	}
	printf("\nENTER STARTING CITY NUMBER(0-%d): ", n-1);
	scanf("%d", &strt);
	if(strt<0 || strt>=n)
		printf("\nINVALID CITY");

	visiting=strt;
	for(i=0; i<n; i++)
	{
		printf("CITY %d\n", visiting);
		visited[visiting]=1;
		for(j=0; j<n; j++)
		{
			if(!visited[j])
			{
				nextvisit=j;
				break;
			}
		}
		for(j=0; j<n; j++)
		{
			if(!visited[j] && adj[visiting][j]<adj[visiting][nextvisit])
			{
				nextvisit=j;
			}
		}
		distance+=adj[visiting][nextvisit];
		visiting=nextvisit;
	}
	distance+=adj[visiting][strt];
	printf("CITY %d\n", strt);
	printf("TOTAL DISTANCE COVERED IN THIS OPTIMAL TRAVEL IS %dunits", distance);
	getch();
}