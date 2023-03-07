//breadth first search(ok)
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define NULL 0

struct main_node
{	int c;
	int stat;
	struct main_node *next;
	struct cnct_node *link;
};

struct cnct_node
{	struct main_node *linked;
	struct cnct_node *nexted;
};

struct main_node *getnode(int a)
{	struct main_node *new1;
	new1=(struct main_node *)malloc(sizeof(struct main_node));
	new1->c=a;
	new1->stat=1;
	new1->next=NULL;
	new1->link=NULL;
	return(new1);
}

struct cnct_node *getnode1()
{	struct cnct_node *new1;
	new1=(struct cnct_node *)malloc(sizeof(struct cnct_node));
	new1->nexted=NULL;
	new1->linked=NULL;
	return(new1);
}

void main()
{       struct main_node *new1,*ptr,*head,*ptr1,*q[10];
	struct cnct_node *new2,*ptr2,*ptr3;
	int y,x,f,r;
	head=NULL;
	clrscr();
	printf("Enter the vertices of the graph(integers):- \n");
	do
	{	printf("Enter :-");
		scanf("%d",&y);
		new1=getnode(y);
		if(head==NULL)
			head=new1;
		else
		{	ptr=head;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new1;
		}
		printf("Do you want to continue(1-Yes,0-No):- ");
		scanf("%d",&x);
	}while(x==1);
	printf("Enter the vertices adjacent to the vertices :- \n");
	ptr=head;
	while(ptr!=NULL)
	{       printf("Does %d have any adjacent vertex?(1-Yes,0-No):- ",ptr->c);
		scanf("%d",&x);
		while(x==1)
		{       printf("Enter adjacent vertex of - %d(if no adjacent vertex,enter 0) - ",ptr->c);
			scanf("%d",&y);
			if(y==0)
				break;
			ptr1=head;
			while(ptr1!=NULL && ptr1->c!=y)
				ptr1=ptr1->next;
			if(ptr1==NULL)
			{	printf("\n%d is not a vertex of the graph\n",y);
				printf("Do you want to re-enter(1-Yes,0-No):- ");
				scanf("%d",&x);
				getch();
				continue;
			}
			new2=getnode1();
			new2->linked=ptr1;
			if(ptr->link==NULL)
				ptr->link=new2;
			else
			{	ptr2=ptr->link;
				while(ptr2->nexted!=NULL)
					ptr2=ptr2->nexted;
				ptr2->nexted=new2;
			}
			printf("Does %d have any more adjacent vertices?(1-Yes,0-No):- ",ptr->c);
			scanf("%d",&x);
		}
		ptr=ptr->next;
	}
	printf("\nThe Adjacency list is\n");
	ptr=head;
	while(ptr!=NULL)
	{	printf("%d : ",ptr->c);
		ptr2=ptr->link;
		while(ptr2!=NULL)
		{	printf("%d,",ptr2->linked->c);
			ptr2=ptr2->nexted;
		}
		printf("\n");
		ptr=ptr->next;
	}
	printf("\nPress Enter for BFS-\n");
	getch();
	printf("\nEnter starting point-");
	scanf("%d",&y);
	printf("\nThe BFS output is-\n");
	ptr=head;
	while(ptr->c!=y)
		ptr=ptr->next;
	f=0;
	r=0;
	q[r++]=ptr;
	q[f]->stat=2;
	while(f!=r)
	{       q[f]->stat=3;
		printf("%d\t",q[f]->c);
		ptr2=q[f++]->link;
		while(ptr2!=NULL)
		{	if(ptr2->linked->stat==3 || ptr2->linked->stat==2)
			{	ptr2=ptr2->nexted;
				continue;
			}
			q[r++]=ptr2->linked;
			ptr2->linked->stat=2;
			ptr2=ptr2->nexted;
		}
	}
	getch();
}

