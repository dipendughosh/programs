//directed

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct subvert;

struct mainvert
{
	int ver;
	int dfsno;
	int dfscmpno;
	int visited;
	struct mainvert *nextver;
	struct subvert *adver;
};

struct subvert
{
	struct mainvert *vert;
	struct subvert *next;
};

struct mainvert *getmain(int x)
{
	struct mainvert *new1;
	new1=(struct mainvert *)malloc(sizeof(struct mainvert));
	new1->ver=x;
	new1->dfsno=0;
	new1->dfscmpno=0;
	new1->visited=0;
	new1->nextver=NULL;
	new1->adver=NULL;
	return(new1);
}

struct subvert *getsub()
{
	struct subvert *new1;
	new1=(struct subvert *)malloc(sizeof(struct subvert));
	new1->vert=NULL;
	new1->next=NULL;
	return(new1);
}

struct mainvert *head;
int n;

int main()
{
	void adjacency_list_create();
	void display();
	void sort();
	void resort();
	void dfs_trav();
	void edge_diff();
	adjacency_list_create();
	display();
	sort();
	dfs_trav();
	resort();
	edge_diff();
	return 0;
}

void adjacency_list_create()
{
	struct mainvert *new1,*ptr,*ptr1;
	struct subvert *new2,*ptrr1;
	int f1,c,a;
	n=0;
	head=NULL;
	do
	{
		n++;
		new1=getmain(n);
		if(head == NULL)
			head=new1;
		else
		{
			ptr=head;
			while(ptr->nextver != NULL)
				ptr=ptr->nextver;
			ptr->nextver=new1;
		}
		printf("Vertex %d created",n);
		printf("\nDo you want to add any more vertex?(YES=1,NO=0) :- ");
		scanf("%d",&c);
	}while(c == 1);
	printf("Enter the adjacent vertices of the vertices");
	ptr=head;
	while(ptr != NULL)
	{
		f1=1;
		c=0;
		do
		{
			printf("\nEnter the vertex adjacent to %d (if no adjacent vertex enter 0):- ",ptr->ver);
			scanf("%d",&a);
			if(a == 0)
				break;
			ptr1=head;
			while(ptr1 != NULL && ptr1->ver != a)
				ptr1=ptr1->nextver;
			if(ptr1 == NULL)
			{
				printf("\nWrong Input : Re-Enter\n");
				continue;
			}
			ptrr1=ptr->adver;
			while(ptrr1 != NULL && ptrr1->vert->ver != a)
				ptrr1=ptrr1->next;
			if(ptrr1 != NULL)
			{
				if(ptrr1->vert->ver == a)
					printf("\n%d is already adjacent to %d",a,ptr->ver);
			}
			else
			{
				new2=getsub();
				new2->vert=ptr1;
				if(ptr->adver == NULL)
					ptr->adver=new2;
				else
				{
					ptrr1=ptr->adver;
					while(ptrr1->next != NULL)
						ptrr1=ptrr1->next;
					ptrr1->next=new2;
				}
			}
		}while(1);
		ptr=ptr->nextver;
	}
}

void dfs_trav()
{
	struct mainvert *mstack[50],*tstack[50],*ptr,*ptr1,*ptr2,*temp;
	struct subvert *ptrr1;
	int s,dfsn,dfsc,mtop,ttop,c,f,f2,min;
	printf("\nDFS Traversal");
	
	do
	{
		printf("\nEnter starting node :- ");
		scanf("%d",&s);
		ptr=head;
		while(ptr->ver != s)
			ptr=ptr->nextver;
		if(ptr == NULL)
		{
			printf("Wrong Input : %d is not a vertex of the given graph\n->To re-enter press 1 else 0 :- ",s);
			scanf("%d",&c);
			if(c == 0)
				break;
		}
		else
			break;
	}while(1);
	mtop=-1;
	ttop=-1;
	dfsn=1;
	dfsc=1;
	tstack[++ttop]=ptr;
	ptr->visited=1;
	do
	{
		f=0;
		f2=1;
		temp=tstack[ttop--];
		if(temp->dfsno == 0)
			temp->dfsno=dfsn++;
		ptrr1=temp->adver;
		while(ptrr1 != NULL)
		{
			if(ptrr1->vert->visited == 0)
			{
				tstack[++ttop]=ptrr1->vert;
				ptrr1->vert->visited=1;
				f=1;
			}
			if(ptrr1->vert->dfsno == 0)
				f2=0;
			ptrr1=ptrr1->next;
		}
		mstack[++mtop]=temp;
		if(f == 0 && f2 == 1)
		{
			ptr=mstack[mtop--];
			ptr->dfscmpno=dfsc++;
			if(mtop != -1)
				ptr=mstack[mtop--];
			else
			{
				ptr1=head;
				min=ptr1->ver;
				ptr2=ptr1;
				while(ptr1 != NULL)
				{
					if(ptr1->ver < min && ptr1->visited != 1 && ptr1->ver != ptr->ver)
					{
						ptr2=ptr1;
						min=ptr1->ver;
					}
					ptr1=ptr1->nextver;
				}
				ptr=ptr2;
			}
			tstack[++ttop]=ptr;
		}
		if(dfsc > n)
			break;

	}while(1);
	for(s=1;s<=n;s++)
	{
		ptr=head;
		while(ptr != NULL)
		{
			if(s == ptr->dfsno)
			{
				printf("%d\t",ptr->ver);
				break;
			}
			ptr=ptr->nextver;
		}
	}
	printf("\n");
}

void edge_diff()
{
	struct mainvert *ptr;
	struct subvert *ptrr;
	printf("\nTree Edge:-\n"); 
	ptr=head;
	while(ptr != NULL)
	{
		ptrr=ptr->adver;
		while(ptrr !=NULL)
		{
			if((ptr->dfsno) < (ptrr->vert->dfsno) && (ptr->dfscmpno) > (ptrr->vert->dfscmpno) && ((ptr->dfsno)-(ptrr->vert->dfsno) == 1 || (ptr->dfsno)-(ptrr->vert->dfsno) == -1 || (ptr->dfscmpno)-(ptrr->vert->dfscmpno) == 1 || (ptr->dfscmpno)-(ptrr->vert->dfscmpno) == -1))
				printf("(%d , %d)\t",ptr->ver,ptrr->vert->ver);
			ptrr=ptrr->next;
		}
		ptr=ptr->nextver;
	}
	printf("\nForward Edge:-\n"); 
	ptr=head;
	while(ptr != NULL)
	{
		ptrr=ptr->adver;
		while(ptrr !=NULL)
		{
			if(((ptr->dfsno) < (ptrr->vert->dfsno) && (ptr->dfscmpno) > (ptrr->vert->dfscmpno)) && ((ptr->dfsno)-(ptrr->vert->dfsno) != 1 && (ptr->dfsno)-(ptrr->vert->dfsno) != -1 && (ptr->dfscmpno)-(ptrr->vert->dfscmpno) != 1 && (ptr->dfscmpno)-(ptrr->vert->dfscmpno) != -1))
				printf("(%d , %d)\t",ptr->ver,ptrr->vert->ver);
			ptrr=ptrr->next;
		}
		ptr=ptr->nextver;
	}
	printf("\nBack Edge:-\n"); 
	ptr=head;
	while(ptr != NULL)
	{
		ptrr=ptr->adver;
		while(ptrr !=NULL)
		{
			if(((ptr->dfsno) > (ptrr->vert->dfsno) && (ptr->dfscmpno) < (ptrr->vert->dfscmpno)) && ((ptr->dfsno)-(ptrr->vert->dfsno) != 1 || (ptr->dfsno)-(ptrr->vert->dfsno) != -1 || (ptr->dfscmpno)-(ptrr->vert->dfscmpno) != 1 || (ptr->dfscmpno)-(ptrr->vert->dfscmpno) != -1))
				printf("(%d , %d)\t",ptr->ver,ptrr->vert->ver);
			ptrr=ptrr->next;
		}
		ptr=ptr->nextver;
	}
	printf("\nCross Edge:-\n"); 
	ptr=head;
	while(ptr != NULL)
	{
		ptrr=ptr->adver;
		while(ptrr !=NULL)
		{
			if((ptr->dfsno) > (ptrr->vert->dfsno) && (ptr->dfscmpno) > (ptrr->vert->dfscmpno))
				printf("(%d , %d)\t",ptr->ver,ptrr->vert->ver);
			ptrr=ptrr->next;
		}
		ptr=ptr->nextver;
	}
	printf("\n");
}

void sort()
{
	struct mainvert *ptr1,*ptr2;
	struct subvert *ptrr1,*ptrr2;
	ptr1=head;
	while(ptr1 != NULL)
	{
		ptrr1=ptr1->adver;
		while(ptrr1 != NULL)
		{
			ptrr2=ptrr1->next;
			while(ptrr2 != NULL)
			{
				if(ptrr1->vert->ver < ptrr2->vert->ver)
				{
					ptr2=ptrr1->vert;
					ptrr1->vert=ptrr2->vert;
					ptrr2->vert=ptr2;
				}
				ptrr2=ptrr2->next;
			}
			ptrr1=ptrr1->next;
		}
		ptr1=ptr1->nextver;
	}
}

void resort()
{
	struct mainvert *ptr1,*ptr2;
	struct subvert *ptrr1,*ptrr2;
	ptr1=head;
	while(ptr1 != NULL)
	{
		ptrr1=ptr1->adver;
		while(ptrr1 != NULL)
		{
			ptrr2=ptrr1->next;
			while(ptrr2 != NULL)
			{
				if(ptrr1->vert->ver > ptrr2->vert->ver)
				{
					ptr2=ptrr1->vert;
					ptrr1->vert=ptrr2->vert;
					ptrr2->vert=ptr2;
				}
				ptrr2=ptrr2->next;
			}
			ptrr1=ptrr1->next;
		}
		ptr1=ptr1->nextver;
	}
}

void display()
{
	struct mainvert *ptr1;
	struct subvert *ptrr1;
	/*Adjacency List Representation*/
	printf("\nAdjacency List\n");
	ptr1=head;
	printf("\nVertex:\tAdjacent Vertices\n");
	while(ptr1 != NULL)
	{
		printf("%d\t:",ptr1->ver);
		ptrr1=ptr1->adver;
		while(ptrr1 != NULL)
		{
			printf("%d,\t",ptrr1->vert->ver);
			ptrr1=ptrr1->next;
		}
		printf("\n");
		ptr1=ptr1->nextver;
	}	
}