//K-ARY TREE to BINARY TREE representation implementation

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Binary Tree node structure
struct bin_node
{
	int data;
	struct bin_node *left,*right;
};

//K-Ary Tree header node structure
struct header_node
{
	struct header_node *multhead;
	struct k_node *header;
};

//K-Ary Tree node structure;
struct k_node
{
	int data;
	struct k_add *ptr;
};

//K-Art Tree sibling address structure
struct k_add
{
	struct k_node *ad;
	struct k_add *next;
};


struct bin_node *getbin_node(int x)
{
	struct bin_node *new1;
	new1=(struct bin_node *)malloc(sizeof(struct bin_node));
	new1->data=x;
	new1->left=NULL;
	new1->right=NULL;
	return(new1);
};

struct header_node *getheader_node()
{
	struct header_node *new1;
	new1=(struct k_node *)malloc(sizeof(struct k_node));
	new1->header=NULL;
	new1->multhead=NULL;
	return(new1);
};

struct k_node *getk_node(int x)
{
	struct k_node *new1;
	new1=(struct k_node *)malloc(sizeof(struct k_node));
	new1->data=x;
	new1->ptr=NULL;
	return(new1);
};

struct k_add *getk_add()
{
	struct k_add *new1;
	new1=(struct k_add *)malloc(sizeof(struct k_add));
	new1->ad=NULL;
	new1->next=NULL;
	return(new1);
};


struct header_node *khead;

void main()
{
	void create_k_ary_tree();
	void display_k_ary_tree();
	create_k_ary_tree();
	display_k_ary_tree()
}

void create_k_ary_tree()
{
	do
	{
		printf("\nEnter data :- ");
		scanf("%d",&x);
		new1=getk_node(x);
		if(khead == NULL)
			khead=new1;
		else
		{
			ptr1=khead;


		printf("Do you want to continue?(YES=1,NO=0) :- ");
		scanf("%d",&c);
	}while(c == 1);
}

void display_k_ary_tree()
{
}