//binary search tree
#include<stdio.h>
#include<conio.h>
#define NULL 0

struct bst
{	struct bst *left_child;
	int data;
	struct bst *right_child;
};

int tp;

struct bst *getnode(int x)
{	struct bst *new1;
	new1=(struct bst *)malloc(sizeof(struct bst));
	new1->left_child=NULL;
	new1->data=x;
	new1->right_child=NULL;
	return(new1);
}

void push(struct bst *stk[],struct bst *ptr)
{	stk[tp++]=ptr;
}

struct bst *pop(struct bst *stk[])
{	struct bst *ptr;
	ptr=stk[--tp];
	return(ptr);
}

void main()
{       struct bst *head;
	void create(struct bst **);
	void in(struct bst *);
	void pre(struct bst *);
	void post(struct bst *);
	void in_recur(struct bst *);
	void pre_recur(struct bst *);
	void post_recur(struct bst *);
	void del(struct bst **);
	clrscr();
	printf("\nCreating tree:-\n");
	create(&head);
	printf("\nRecursion version\n\n");
	printf("\nInorder\n");
	in_recur(head);
	printf("\nPreorder\n");
	pre_recur(head);
	printf("\nPostorder\n");
	post_recur(head);
	printf("\nNon-Recursion version\n\n");
	printf("\nInorder\n");
	in(head);
	printf("\nPreorder\n");
	pre(head);
	printf("\nPostorder\n");
	post(head);
	/*printf("\nDelete a node\n");
	del(&head);
	printf("\nRecursion version\n\n");
	printf("\nInorder\n");
	in_recur(head);
	printf("\nPreorder\n");
	pre_recur(head);
	printf("\nPostorder\n");
	post_recur(head);
	printf("\nNon-Recursion version\n\n");
	printf("\nInorder\n");
	in(head);
	printf("\nPreorder\n");
	pre(head);
	printf("\nPostorder\n");
	post(head);*/
	getch();
}

//creation
void create(struct bst **head)
{       struct bst *new1,*ptr,*ptr1;
	int x;
	char c;
	printf("Enter Root Node-");
	scanf("%d",&x);
	new1=getnode(x);
	(*head)=new1;
	while(1)
	{	printf("Enter data - ");
		scanf("%d",&x);
		new1=getnode(x);
		ptr=(*head);
		while(ptr!=NULL && ptr->data!=x)
		{	if(x<ptr->data)
			{	ptr1=ptr;
				ptr=ptr->left_child;
			}
			else
			{	ptr1=ptr;
				ptr=ptr->right_child;
			}
		}
		if(ptr==NULL)
		{	if(x<ptr1->data)
				ptr1->left_child=new1;
			else
				ptr1->right_child=new1;
		}
		else
		{	printf("\nDuplicate\n");
			free(new1);
		}
		fflush(stdin);
		printf("\nDo you want to continue?(Y/y):- ");
		fflush(stdin);
		scanf("%c",&c);
		if(c=='Y' || c=='y')
			continue;
		else
			break;
	}
	getch();
}

//inorder
void in(struct bst *head)
{	struct bst *stk[20];
	tp=0;
	stk[tp++]=NULL;
	while(1)
	{	while(head!=NULL)
		{	push(stk,head);
			head=head->left_child;
		}
		head=pop(stk);
		if(head==NULL)
			break;
		printf("%d\t",head->data);
		head=head->right_child;
	}
}

//preorder
void pre(struct bst *head)
{	struct bst *stk[20];
	tp=0;
	stk[tp++]=NULL;
	while(1)
	{	while(head!=NULL)
		{	if(head->right_child!=NULL)
				push(stk,head->right_child);
			printf("%d\t",head->data);
			head=head->left_child;
		}
		head=pop(stk);
		if(head==NULL)
			break;
	}
}

//postorder
void post(struct bst *head)
{	struct bst *stk[20],*stk1[20];
	int tp1;
	tp=0;
	tp1=0;
	stk[tp++]=NULL;
	while(1)
	{	while(head!=NULL)
		{	if(head->left_child!=NULL)
				push(stk,head->left_child);
			stk1[tp1++]=head;
			head=head->right_child;
		}
		head=pop(stk);
		if(head==NULL)
			break;
	}
	while(tp1>0)
		printf("%d\t",stk1[--tp1]->data);
}
/*
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
	{	if(par->right_child==ptr)
			par->right_child=NULL;
		else
			par->left_child=NULL;
		printf("\nDeleted - %d",ptr->data);
		free(ptr);
	}
	else if(ptr->right_child==NULL || ptr->left_child==NULL)
	{    	if(ptr->right_child==NULL)
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
	{	ptr1=ptr2=ptr->right_child;
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
} */

//inorder
void in_recur(struct bst *h)
{       if(h!=NULL)
	{	in_recur(h->left_child);
		printf("%d\t",h->data);
		in_recur(h->right_child);
	}
}

//preorder
void pre_recur(struct bst *h)
{       if(h!=NULL)
	{       printf("%d\t",h->data);
		pre_recur(h->left_child);
		pre_recur(h->right_child);
	}
}

//postorder
void post_recur(struct bst *h)
{       if(h!=NULL)
	{	post_recur(h->left_child);
		post_recur(h->right_child);
		printf("%d\t",h->data);
	}
}