// Program which maintains a B-tree of order 5.

#include <conio.h>
#include <stdio.h>
#include<stdlib.h>

struct btnode
{
	int count ;
	int value[10] ;
	struct btnode *child[10] ;
} ;
struct btnode *root=NULL ;

void insert(int) ;
int setval(int,struct btnode *,int *,struct btnode **);
struct btnode *search(int,struct btnode *,int *);
int searchnode(int,struct btnode *,int *);
void fillnode(int,struct btnode *,struct btnode *,int);
void split(int,struct btnode *,struct btnode *,int,int *,struct btnode **);
void display(struct btnode *);

int max,min;	

void main( )
{
	int x,y;
	printf("\nEnter order :- ");
	scanf("%d",&max);
	min=max/2;
	do
	{
		printf("Enter element:- ");	
		scanf("%d",&x);
		insert ( x ) ;
		printf("Do you want to continue?(YES=1,NO=0):- ");
		scanf("%d",&y);
	}while(y);
	printf("B-tree of order %d:\n",max);
	display ( root );
	printf("\n");

}

// inserts a value in the B-tree
void insert(int val)
{
	int i;
	struct btnode *c, *n;
	int flag;
	flag=setval(val,root,&i,&c);
	if(flag)
	{
		n=(struct btnode *)malloc(sizeof(struct btnode));
		n->count=1;
		n->value[1]=i;
		n->child[0]=root;
		n->child[1]=c;
		root=n;
	}
}

// sets the value in the node
int  setval(int val,struct btnode *n,int *p,struct btnode **c)
{
	int k;
	if(n==NULL)
	{
		*p=val;
		*c=NULL;
		return 1;
	}
	else
	{
		if(searchnode(val,n,&k))
			printf("\nKey value already exists.\n");
		if(setval(val,n->child[k],p,c))
		{
			if(n->count<max)
			{
				fillnode(*p,*c,n,k);
				return 0;
			}
			else
			{
				split(*p,*c,n,k,p,c);
				return 1;
			}
		}
		return 0;
	}
}

// searches value in the node
struct btnode *search(int val,struct btnode *root,int *pos)
{
	if(root==NULL)
		return NULL;
	else
	{
		if(searchnode(val,root,pos))
			return root;
		else
			return search(val,root->child[*pos],pos);
	}
}

// searches for the node
int searchnode(int val,struct btnode *n,int *pos)
{
	if(val<n->value[1])
	{
		*pos=0;
		return 0;
	}
	else
	{
		*pos=n->count;
		while((val<n->value[*pos])&&*pos>1)
			(*pos)--;
		if(val==n->value[*pos])
			return 1;
		else
			return 0;
	}
}

// adjusts the value of the node
void fillnode(int val,struct btnode *c,struct btnode *n,int k)
{
	int i;
	for(i=n->count;i>k;i--)
	{
		n->value[i+1]=n->value[i];
		n->child[i+1]=n->child[i];
	}
	n->value[k+1]=val;
	n->child[k+1]=c;
	n->count++;
}

// splits the node
void split(int val,struct btnode *c,struct btnode *n,int k,int *y,struct btnode **newnode)
{
	int i,mid;
	if(k<=min)
		mid=min;
	else
		mid=min+1;
	*newnode=(struct btnode *)malloc(sizeof(struct btnode));
	for(i=mid+1;i<=max;i++)
	{
		(*newnode)->value[i-mid]=n->value[i];
		(*newnode)->child[i-mid]=n->child[i];
	}
	(*newnode)->count=max-mid;
	n->count=mid;
	if(k<=min)
		fillnode(val,c,n,k);
	else
		fillnode(val,c,*newnode,k-mid);
	*y=n->value[n->count];
	(*newnode)->child[0]=n->child[n->count];
	n->count--;
}


// displays the B-tree
void display(struct btnode *root)
{
	int i;
	if(root!=NULL)
	{
		for(i=0;i<root->count;i++)
		{
			display(root->child[i]);
			printf("%d\t",root->value[i+1]);
		}
		display(root->child[i]);
	}
}