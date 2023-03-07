//Undirected and weighted

#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct sub_node;

struct main_node
{
	int ver;
	struct main_node *nextver;
	struct sub_node *adver;
};

struct sub_node
{
	int wt;
	struct main_node *vert;
	struct sub_node *next;
};

struct main_node* getmain(int x)
{
	struct main_node *new1;
	new1=(struct main_node *)malloc(sizeof(struct main_node));
	new1->ver=x;
	new1->nextver=NULL;
	new1->adver=NULL;
	return(new1);
}

struct sub_node* getsub(int x)
{
	struct sub_node *new1;
	new1=(struct sub_node *)malloc(sizeof(struct sub_node));
	new1->wt=x;
	new1->vert=NULL;
	new1->next=NULL;
	return(new1);
}

struct main_node *head=NULL;
int admt[50][50],inmt[50][50],n=0,m=0;

int main()
{
	void adjacency_list_create();
	void adjacency_matrix_create();
	void incidence_matrix_create();
	void display();
	adjacency_list_create();
	adjacency_matrix_create();
	incidence_matrix_create();
	display();
	return 0;
}

void adjacency_list_create()
{
	struct main_node *new1,*ptr1,*ptr2;
	struct sub_node *new2,*ptrr1;
	int f,x,y;
	char c;
	do
	{
		n++;
		new1=getmain(n);
		printf("Vertex %d created",n);
		if(head == NULL)
			head=new1;
		else
		{
			ptr1=head;
			while(ptr1->nextver != NULL)
				ptr1=ptr1->nextver;
			ptr1->nextver=new1;
		}
		printf("\nDo you want to enter any more node?(Y/y=YES) :- ");
		fflush(stdin);
		scanf("%c",&c);
	}while(c == 'y' || c == 'Y');
	ptr1=head;
	do
	{
		f=0;
		if(ptr1->adver != NULL)
		{
			printf("\nThe vertex %d had adjacent vertices which are :- ",ptr1->ver);
			ptrr1=ptr1->adver;
			while(ptrr1->next != NULL)
				printf("%d\t",(ptrr1->vert->ver));
			printf("%d\t",(ptrr1->vert->ver));
			printf("\nAny more adjacent vertex?(Y/y=YES) :- ");
			fflush(stdin);
			scanf("%c",&c);
			if(c == 'y' || c == 'Y')
				f=1;
		}
		else
			f=1;
		if(f == 1)
		{
			printf("\nAny vertex adjacent to %d ?(Y/y=YES) :- ",ptr1->ver);
			fflush(stdin);
			scanf("%c",&c);
			while(c == 'y' || c == 'Y')
			{
				printf("Enter vertex adjacent to %d :- ",ptr1->ver);
				scanf("%d",&x);
				if(x < n)
				{
					printf("Enter weight of edge (%d , %d) :- ",ptr1->ver,x);
					scanf("%d",&y);
					new2=getsub(y);
					ptr2=head;
					while(ptr2->ver != x)
						ptr2=ptr2->nextver;
					new2->vert=ptr2;
					if(ptr1->adver == NULL)
						ptr1->adver=new2;
					else
						ptrr1->next=new2;
					new2=getsub(y);
					new2->vert=ptr1;
					if(ptr2->adver == NULL)
						ptr2->adver=new2;
					else
					{
						ptrr1=ptr2->adver;
						while(ptrr1->next != NULL)
							ptrr1=ptrr1->next;
						ptrr1->next=new2;
					}
				}
				printf("\nAny more adjacent vertex?(Y/y=YES) :- ");
				fflush(stdin);
				scanf("%c",&c);
			}
		}
		ptr1=ptr1->nextver;
	}while(ptr1 != NULL);
}

void adjacency_matrix_create()
{
	struct main_node *ptr;
	struct sub_node *ptrr;
	int i,j,x,y;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			admt[i][j]=0;
	ptr=head;
	while(ptr != NULL)
	{
		ptrr=ptr->adver;
		while(ptrr != NULL)
		{
			x=(ptr->ver)-1;
			y=(ptrr->vert->ver)-1;
			admt[x][y]=ptrr->wt;
			ptrr=ptrr->next;
		}
		ptr=ptr->nextver;
	}
}

void incidence_matrix_create()
{
	int i,j,x;
	x=n*(n-1)/2;
	for(i=0;i<n;i++)
		for(j=0;j<x;j++)
			inmt[i][j]=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;i<n;j++)
		{
			if(admt[i][j] > 0)
			{
				inmt[i][m]=admt[i][j];
				inmt[j][m]=admt[i][j];
				m++;
			}
		}
	}
}

void display()
{
	struct main_node *ptr1;
	struct sub_node *ptrr1;
	int i,j;
	printf("\nAdjacency List\n");
	ptr1=head;
	printf("\nVertex\tAdjacent Vertices and weights\n");
	while(ptr1 != NULL)
	{
		printf("%d\t:",ptr1->ver);
		ptrr1=ptr1->adver;
		while(ptrr1 != NULL)
		{
			printf("%d(%d)  ,  ",(ptrr1->vert->ver),(ptrr1->wt));
			ptrr1=ptrr1->next;
		}
		printf("\n");
		ptr1=ptr1->nextver;
	}
	getch();
	printf("\nAdjacency Matrix\n");
	printf("  ");
	for(i=0;i<n;i++)
		printf("%d ",i);
	for(i=0;i<n;i++)
	{
		printf("%d ",i);
		for(j=0;j<n;j++)
			printf("%d ",admt[i][j]);
		printf("\n");
	}
	printf("\nIncidence Matrix\n");
	printf("  ");
	for(i=0;i<m;i++)
		printf("%d ",i);
	for(i=0;i<n;i++)
	{
		printf("%d ",i);
		for(j=0;j<m;j++)
			printf("%d ",admt[i][j]);
		printf("\n");
	}
}