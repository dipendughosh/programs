#include <stdio.h>
struct node
{
	int data;
	struct node * link;
}; 
main()
{
	struct node *s=NULL;

	void ins(struct node**,int,int);
	int del(struct node**,int);
	void display(struct node*);

	while(1)
	{
		int ch,p,d;
		printf("\n\n\tLINK LIST MENU");
		printf("\n\t1. Insert");
		printf("\n\t2. Delete");
		printf("\n\t3. Display");
		printf("\n\t4. Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n\nEnter the position:");
				scanf("%d",&p);
				printf("\nEnter the data:");
				scanf("%d",&d);
				ins(&s,d,p);
				display(s);
				break;

			case 2:
				printf("\n\nEnter the position:");
				scanf("%d",&p);
				d=del(&s,p);
				printf("\nItem deleted: %d",d);
				display(s);
				break;

			case 3:
				display(s);
				break;

			case 4:
				return;

			default:
				printf("\nError: Invalid choice!");
		}
	}
}

void ins(struct node**s,int d,int p)
{
	int i;
	struct node *t,*n;

	n=(struct node*)malloc(sizeof(struct node));
	n->data=d;

	if(p==0)
	{
		n->link=*s;
		*s=n;
	}
	else
	{
		for(t=*s,i=1;i<p;t=t->link,i++)
			if(t==NULL)
			{
				printf("\nERROR: Invalid position.");
				free(n);
				return;
			}
		n->link=t->link;
		t->link=n;
	}
}

int del(struct node**s,int p)
{
	int i,d;
	struct node *t, *r;
	if(*s==NULL)
	{
		printf("\nERROR: Empty list.");
		return -9999;
	}
	if(p==1)
	{
		r=*s;
		*s=(*s)->link;
	}
	else
	{
		for(t=*s,i=1;i<p-1;i++,t=t->link)
			if(t->link==NULL)
			{
				printf("\nERROR: Invalid position.");
				return -9999;
			}
		r=t->link;
		if(t->link==NULL)
		{
			printf("\nERROR: Invalid position.");
			return -9999;
		}
		t->link=t->link->link;
	}
	d=r->data;
	free(r);
	return d;
}

void display(struct node*s)
{
	struct node *t;
	printf("\n\nThe list is....\n\tS -> ");
	for(t=s;t!=NULL;t=t->link)
		printf("%d -> ",t->data);
	printf("NULL");
}
