//binary tree creation(incomnplete)
#include<stdio.h>
#include<conio.h>
#define NULL 0

struct binary_tree
{	struct binary_tree *left_child;
	char data;
	struct binary_tree *right_child;
}*head,*q[20],*s[20];

struct binary_tree *getnode(int x)
{	struct binary_tree *new1;
	new1=(struct binary_tree *)malloc(sizeof(struct binary_tree));
	new1->left_child=NULL;
	new1->data=x;
	new1->right_child=NULL;
	return(new1);
}

void main()
{	void create();
	void dfs();
	void bfs();
	clrscr();
	create();
	dfs();
	bfs();
	getch();
}

void create()
{       struct binary_tree *new1,*q[20];
	int x,f,r;
	char y;
	printf("Enter Root Node-");
	scanf("%d",&x);
	f=r=0;
	new1=getnode(x);
	head=new1;
	q[0]=head;
	do
	{	printf("Enter node value - ");
		scanf("%d",&x);
		new1=getnode(x);
		if(q[f]->left_child!=NULL)
		{	q[f++]->right_child=new1;
			q[++r]=new1;
		}
		else
		{	q[f]->left_child=new1;
			q[++r]=new1;
		}
		printf("\nDo you want to continue(Y/y):-");
		fflush(stdin);
		scanf("%c",&y);
	}while(y=='y' || y=='Y');
	printf("\n");
}

void dfs()
{	struct binary_tree *ptr;
	int top=-1;
	top++;
	s[top]=head;
	while(top!=-1)
	{       ptr=s[top];
		top--;
		printf("%d\t",ptr->data);
		if(ptr->left_child!=NULL)
			s[++top]=ptr->left_child;
		if(ptr->right_child!=NULL)
			s[++top]=ptr->right_child;
	}
	printf("\n");
}

void bfs()
{	struct binary_tree *ptr;
	int f=-1,r=-1;
	f++;
	r++;
	q[r]=head;
	while(f<=r)
	{       ptr=q[f];
		f++;
		printf("\n%d\t",ptr->data);
		if(ptr->left_child!=NULL)
			q[++r]=ptr->left_child;
		if(ptr->right_child!=NULL)
			q[++r]=ptr->right_child;
	}
}

