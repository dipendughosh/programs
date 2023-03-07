//krushkal's algorithm
#include<stdio.h>
#include<conio.h>

struct edgerecord
{	int vertex1,vertex2,weight;
};

struct edgerecord edge[20];
int parent[20],v,e;

int readedges(struct edgerecord edge[])
{	int p,vertex1,vertex2,weight;
	e=0;
	printf("\nEnter value for p:-\n");
	scanf("%d",&p);
	while(p!=9999)
	{	e=e+1;
		printf("\nEnter vertex1,vertex2,weight:-\n");
		scanf("%d  %d  %d",&vertex1,&vertex2,&weight);
		edge[e].vertex1=vertex1;
		edge[e].vertex2=vertex2;
		edge[e].weight=weight;
		printf("\nread 9999 to stop:-");
		scanf("%d",&p);
	}
	printf("\nEdges = %d",e);
	return(e);
}

void sortedges(struct edgerecord edge[],int e)
{	int i,j;
	struct edgerecord temp;
	edge[1].weight=-1;
	for(i=2;i<e+1;i++)
	{	temp=edge[i];
		j=i;
		while(edge[j-1].weight>temp.weight)
		{	edge[j]=edge[j-1];
			j=j-1;
		}
		edge[j]=temp;
	}
}

void initi(int parent[],int v)
{	int i;
	for(i=1;i<v+3;++i)
		parent[i]=0;
}

void findunion(int parent[],int vertex1,int vertex2)
{	int i,j;
	i=vertex1;
	j=vertex2;
	while(parent[i]>0)
		i=parent[--i];
	while(parent[j]>0)
		j=parent[--j];
	if(i!=j)
	{	parent[j]=i;
		printf("%d\t%d\n",vertex1,vertex2);
	}
}

void kruskal(struct edgerecord edge[],int v)
{	int edgessofar,edgeindex,i,j,parent[20];
	edgessofar=0;
	edgeindex=0;
	do
	{	edgeindex=edgeindex+1;
		edgessofar=edgessofar+1;
		i=edge[edgeindex].vertex1;
		j=edge[edgeindex].vertex2;
		findunion(parent,i,j);
	}while(edgessofar<v);
}

void main()
{       int i,parent[20],v,e;
	clrscr();
	printf("Enter number of vertices:-");
	scanf("%d",&v);
	e=readedges(edge);
	sortedges(edge,e);
	initi(parent,v);
	printf("\nKruskal's spanning tree edges is:\n");
	kruskal(edge,v);
	getch();
}

