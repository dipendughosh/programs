#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct tree
{
	struct tree *parent;
	struct tree *child,*right;
	int data;
};

struct tree* insert(struct tree *,int);
void main()
{
	struct tree *root,*a,*p=NULL,*head;
	int item
	,o,k,i;
	printf("\n enter the order:");
	scanf("%d",&o);
	k=o;
	root=NULL;
	head=(struct tree*)malloc(sizeof(struct tree));
	head->child=root;
	head->parent=NULL;
	head->right=NULL;
	for(i=k;i>0;i--)
	{
		b=(struct tree*)malloc(sizeof(struct tree));
		q=b;
		p=insert(head,i);

}
struct tree* insert(struct tree *root,int o)
{
	struct tree *p,*q,*a,*b;
	int c=o-1,i,item;
	if(c>=0)
	{

		b=(struct tree*)malloc(sizeof(struct tree));
		q=b;
	printf("\n enter the data :");
	scanf("%d",&item);
	a=(struct tree*)malloc(sizeof(struct tree));
	a->data=item;
	a->parent=root;
	a->child=NULL;
	a->right=NULL;
	p=a;
	if(c!=o)
	{
		for(i=c;i>=0;i--)
		{
			q->right=p;
			q=q->right;
			p=insert(p,i);

		}


	}
	else
	{
	    q->right=p;
	    q=q->right;
	    root->child=p;
	}
	}
	return(p);
}




