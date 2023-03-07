#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct tree
{
	struct tree *parent;
	struct tree *child,*right;
	int data,order;
};

void insert(int);
void traversal();
struct tree *root;

void main()
{
	int o;
	printf("\n enter the order:");
	scanf("%d",&o);
	root=NULL;
	insert(o);
	traversal();
}

void insert(int o)
{
	struct tree *new1,*queue[100],*ptr;
	int front=-1,rear=-1,i;
	new1=(struct tree *)malloc(sizeof(struct tree));
	new1->data=o;
	new1->order=o;
	new1->parent=NULL;
	new1->child=NULL;
	new1->right=NULL;
	root=new1;
	queue[++rear]=new1;
	while(front != rear)
	{
		ptr=queue[++front];
		for(i=0;i<ptr->order;i++)
		{
			new1=(struct tree *)malloc(sizeof(struct tree));
			new1->data=i;
			new1->order=i;
			new1->parent=ptr;
			new1->child=NULL;
			new1->right=NULL;
			if(i == 0)
				ptr->child=new1;
			else
				queue[rear]->right=new1;
			queue[++rear]=new1;
		}
	}
}

void traversal()
{
	struct tree *queue[100],*ptr,*ptr2;
	int front=-1,rear=-1;
	ptr=root;
	queue[++rear]=ptr;
	printf("B{%d}[%d]\n",ptr->data,ptr->order);
	while(front != rear)
	{
		ptr=queue[++front];
		ptr2=ptr->child;
		while(ptr2 != NULL)
		{
			printf("B{%d}[%d]\t",ptr2->data,ptr2->order);
			queue[++rear]=ptr2;
			ptr2=ptr2->right;
		}
		printf("\n");
	}
}