//binary search tree(ok)
#include<stdio.h>
#include<conio.h>
#define NULL 0

struct bst
{	struct bst *left_child;
	char data;
	struct bst *right_child;
};

struct stk
{	struct bst *add;
	int s;
};

struct bst *getnode(int x)
{	struct bst *new1;
	new1=(struct bst *)malloc(sizeof(struct bst));
	new1->left_child=NULL;
	new1->data=x;
	new1->right_child=NULL;
	return(new1);
}

void main()
{       struct bst *ptr,*new1,*head,*q[20],*ptr1,*stk1[20],*stk2[20],*par,*ptr2;
	struct stk stk3[20];
	int x,y,r,f,tp;
	void create(struct bst **);
	void in(struct bst *);
	void pre(struct bst *);
	void post(struct bst *);
	void del(struct bst **);
	clrscr();
	create(&head);
	in(head);
	pre(head);
	post(head);
	del(&head);
	in(head);
	pre(head);
	post(head);
	getch();
}

//creation
void create(struct bst **head)
{       struct bst *new1,*ptr,*ptr1;
	int x;
	printf("Enter Root Node-");
	scanf("%d",&x);
	new1=getnode(x);
	(*head)=new1;
	while(1)
	{       printf("Enter data or 999 to stop - ");
		scanf("%d",&x);
		if(x==999)
			break;
		new1=getnode(x);
		ptr=(*head);
		while(ptr!=NULL)
		{	if(x<ptr->data)
			{	ptr1=ptr;
				ptr=ptr->left_child;
			}
			else if(x>ptr->data)
			{	ptr1=ptr;
				ptr=ptr->right_child;
			}
			else
			{	printf("\nDuplicate");
				break;
			}
		}
		if(x!=ptr->data)
		{	if(x<ptr1->data)
				ptr1->left_child=new1;
			else
				ptr1->right_child=new1;
		}
		else
			free(new1);
	}
	getch();
}

//inorder
void in(struct bst *head)
{	struct bst *ptr1,*stk1[20];
	int tp;
	printf("\nInorder\n");
	tp=0;
	stk1[tp]=head;
	tp++;
	while(tp!=0)
	{	ptr1=stk1[tp-1]->left_child;
		while(ptr1!=NULL)
		{	stk1[tp]=ptr1;
			tp++;
			ptr1=ptr1->left_child;
		}
		if(stk1[tp-1]->right_child!=NULL)
		{	printf("%d\t",stk1[tp-1]->data);
			stk1[tp-1]=stk1[tp-1]->right_child;
		}
		if(stk1[tp-1]->right_child==NULL)
		{	printf("%d\t",stk1[tp-1]->data);
			tp--;
			if(tp!=0)
			{	printf("%d\t",stk1[tp-1]->data);
				stk1[tp-1]=stk1[tp-1]->right_child;
			}
		}
	}
	getch();
}

//preorder
void pre(struct bst *head)
{	struct bst *ptr,*stk2[20];
	int tp;
	printf("\nPreOrder\n");
	tp=0;
	ptr=head;
	while(ptr!=NULL)
	{	printf("%d\t",ptr->data);
		if(ptr->right_child!=NULL)
		{	stk2[tp]=ptr->right_child;
			tp++;
		}
		if(ptr->left_child!=NULL)
			ptr=ptr->left_child;
		else
		{	ptr=stk2[tp-1];
			tp--;
			if(tp==-1)
				break;
		}
	}
	getch();
}

//postorder
void post(struct bst *head)
{	struct bst *ptr;
	struct stk stk3[20];
	int x,tp;
	printf("\nPostOrder\n");
	tp=0;
	ptr=head;
	while(tp!=-1)
	{	while(ptr!=NULL)
		{	stk3[tp].add=ptr;
			stk3[tp].s=0;
			tp++;
			if(ptr->right_child!=NULL)
			{	stk3[tp].add=ptr->right_child;
				stk3[tp].s=1;
				tp++;
			}
			ptr=ptr->left_child;
		}
		tp--;
		ptr=stk3[tp].add;
		x=stk3[tp].s;
		while(x==0)
		{	printf("%d\t",ptr->data);
			tp--;
			ptr=stk3[tp].add;
			x=stk3[tp].s;
		}
		if(x==1)
		{	ptr=stk3[tp].add;
			x=stk3[tp].s;
		}
	}
	getch();
}

//deletion
void del(struct bst **head)
{	struct bst *ptr,*par,*ptr1,*ptr2;
	int x;
	printf("\nDeleting a node\n");
	printf("Enter node to delete-  ");
	scanf("%d",&x);
	par=ptr=(*head);
	while(ptr!=NULL && ptr->data!=x)
	{	par=ptr;
		if(x<ptr->data)
			ptr=ptr->left_child;
		else
			ptr=ptr->right_child;
	}
	if(ptr->right_child==NULL && ptr->left_child==NULL)
	{       if(x==(*head)->data)
		{	printf("\nDeleted - %d",ptr->data);
			free(*head);
			(*head)=NULL;
			printf("\nTree empty");
			return;
		}
		if(par->right_child==ptr)
			par->right_child=NULL;
		else
			par->left_child=NULL;
		printf("\nDeleted - %d",ptr->data);
		free(ptr);
	}
	else if(ptr->right_child==NULL || ptr->left_child==NULL)
	{       if((*head)->data==x)
		{	if(ptr->right_child==NULL)
				(*head)=ptr->left_child;
			else
				(*head)=ptr->right_child;
			return;
		}
		if(ptr->right_child==NULL)
		{	if(par->right_child==ptr)
				par->right_child=ptr->left_child;
			else
				par->left_child=ptr->left_child;
		}
		if(ptr->left_child==NULL)
		{	if(par->right_child==ptr)
				par->right_child=ptr->right_child;
			else
				par->left_child=ptr->right_child;
		}
		printf("\nDeleted - %d",ptr->data);
		free(ptr);
	}
	else
	{       ptr1=ptr2=ptr->right_child;
		while(ptr2->left_child!=NULL)
		{	ptr1=ptr2;
			ptr2=ptr2->left_child;
		}
		ptr1->left_child=ptr2->right_child;
		ptr2->right_child=ptr->right_child;
		ptr2->left_child=ptr->left_child;
		if(par==ptr)
			(*head)=ptr2;
		else
		{	if(par->right_child==ptr)
				par->right_child=ptr2;
			else
				par->left_child=ptr2;
		}
	}
}