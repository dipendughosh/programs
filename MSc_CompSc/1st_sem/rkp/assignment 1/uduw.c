//Undirected and unweighted

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

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
	void adjacency_matrix_create();
	void incidence_matrix_create();
	void adjacency_list_create();
	void display();
	adjacency_matrix_create();
	incidence_matrix_create();
	adjacency_list_create();
	display();
	return 0;
}

void adjacency_list_create()
{
	struct main_node *new1,*ptr1,*ptr2;
	struct sub_node *new2,*ptrr1;
	int i=0,j;
	do{

		new1=getmain(i++);
		if(head == NULL)
			head=new1;
		else
		{
			ptr1=head;
			while(ptr1->nextver != NULL)
				ptr1=ptr1->nextver;
			ptr1->nextver=new1;
		}
	}while(i < n);
	ptr1=head;
	while(ptr1 != NULL)
	{
		i=ptr1->ver;
		for(j=i+1;j<n;j++)
		{
			if(admt[i][j] == 1)
			{
				new2=getsub(0);
				ptr2=head;
				while(ptr2->ver != j)
					ptr2=ptr2->nextver;
				new2->vert=ptr2;
				if(ptr1->adver == NULL)
					ptr1->adver=new2;
				else
				{
					ptrr1=ptr1->adver;
					while(ptrr1->next != NULL)
						ptrr1=ptrr1->next;
					ptrr1->next=new2;
				}
				new2=getsub(0);
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
		}
		ptr1=ptr1->nextver;
	}
}

void adjacency_matrix_create()
{
	int i,j,c;
	printf("Enter number of vertices :- ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(i==j)
				admt[i][j]=0;
			else
			{
				printf("Does edge (%d , %d) exist ?(1=YES,0=NO) :- ",i+1,j+1);
				scanf("%d",&c);
				admt[i][j]=c;
				admt[j][i]=c;
			}
		}
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
		for(j=i+1;j<n;j++)
		{
			if(admt[i][j] == 1)
			{
				inmt[i][m]=1;
				inmt[j][m]=1;
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
	printf("\nAdjacency Matrix\n");
	printf("  ");
	for(i=0;i<n;i++)
		printf("%d ",i+1);
	printf("\n");
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
		printf("%d ",i+1);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",i+1);
		for(j=0;j<m;j++)
			printf("%d ",inmt[i][j]);
		printf("\n");
	}
	printf("\nAdjacency List\n");
	ptr1=head;
	printf("\nVertex\tAdjacent Vertices and weights\n");
	while(ptr1 != NULL)
	{
		printf("%d\t:",(ptr1->ver)+1);
		ptrr1=ptr1->adver;
		while(ptrr1 != NULL)
		{
			printf("%d  ,  ",(ptrr1->vert->ver)+1);
			ptrr1=ptrr1->next;
		}
		printf("\n");
		ptr1=ptr1->nextver;
	}
}