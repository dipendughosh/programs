//Dijkstra's Algorithm
#include<stdio.h>
#include<conio.h>

void main()
{       //Declaring variables
	int dist[50][50],s1[50],s2[50],i,j,n,a,z,b,min,x=0;
	clrscr();
	//Entering the weighted matrix
	printf("\nEnter number of vertices - ");
	scanf("%d",&n);
	printf("\nEnter weights between the vetices,if no edge between vertices enter 999\n");
	for(i=1;i<=n;i++)
	{	for(j=1;j<=n;j++)
		if(i==j)
			dist[i][j]=0;
		else
		{	printf("%d - %d = ",i,j);
			scanf("%d",&dist[i][j]);
		}
	}
	//Initialing temporary array
	for(i=1;i<=n;i++)
	{	s1[i]=999;
		s2[i]=0;
	}
	printf("\nEnter the vertex to start from:- ");
	scanf("%d",&a);
	printf("\nEnter the vertex to reach:- ");
	scanf("%d",&z);
	b=a;
	s1[b]=0;
	s2[b]=1;
	//Loop to fimd the minimum distance
	printf("\t");
	for(i=1;i<=n;i++)
		printf("\t%d",i);
	printf("\n");
	while(1)
	{       for(j=1;j<=n;j++)
		{	if(s1[j]>s1[b]+dist[b][j])
				s1[j]=dist[b][j]+s1[b];
		}
		printf("\nStep %d - \t",++x);
		for(i=1;i<=n;i++)
			printf("%d\t",s1[i]);
		for(i=1;i<=n;i++)
		{       if(s2[i]==0)
			{	min=s1[i];
				break;
			}
		}
		for(i=1;i<=n;i++)
		{	if(min>=s1[i])
			{       if(s2[i]==0)
				{	min=s1[i];
					b=i;
				}
			}
		}
		if(s2[z]==1)
			break;
		s2[b]=1;
	}
	printf("\nShortest distance between vertex %d and vertex %d is %d",a,z,s1[z]);
	getch();
}

