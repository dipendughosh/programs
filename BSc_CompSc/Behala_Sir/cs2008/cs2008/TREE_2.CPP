/* 		         surya rules			*/

/*		 deletion of a node from a tree		*/

/* 		the program is working fine		*/



#include"stdio.h"
#include"conio.h"
#include"graphics.h"
#include"dos.h"
#include"string.h"
#include"math.h"
#include"alloc.h"

struct btreenode
{
	struct btreenode *left;
	int data;
	struct btreenode *right;
};


	/* inserts a node into the tree */

	void insert(struct btreenode **sr,int num)
	{
		if(*sr==NULL)
		{
			(*sr)=(struct btreenode *)malloc(sizeof(struct btreenode));
			(*sr)->left=NULL;
			(*sr)->data=num;
			(*sr)->right=NULL;
		}
		else	/* search the location to insert the node */
		{
			/* if new data is less, traverse left */
			if(num < (*sr)->data)
				insert(&((*sr)->left),num);
			else
				/* traverse to right */
				insert(&((*sr)->right),num);
		}
	}


	/* returns the address of the node to be deleted,address of its parent and whether the node exists */

	int search(struct btreenode **root,int num,struct btreenode **par,struct btreenode **node)
	{
		struct btreenode *temp;
		temp=*root;
		*par=NULL;

		while(temp!=NULL)
		{
			/* if the node to be deleted is found return 1 */
			if(temp->data==num)
			{
				*node=temp;
				return(1);
			}
			if(temp->data>num)
			{
				*par=temp;
				temp=temp->left;

			}
			else
			{
				*par=temp;
				temp=temp->right;
			}
		}
		return(0);
	}



	/* deletes a node from a tree */

	void del(struct btreenode **root,int num)
	{
		struct btreenode *parent,*node,*nodesuc;
		int search_result=0;

		/* if tree is empty */

		if(*root==NULL)
		{
			printf("tree is empty........");
		}

		else
		{
			parent=NULL;
			node=NULL;

			/* call search function to see if node exists */

			search_result=search(root,num,&parent,&node);
			if(search_result==0)
				printf("\n\n data to be deleted not found in the tree...");


			/* if the node to be deleted has two children */

			if(node->left!=NULL && node->right!=NULL)
			{
				parent=node;
				nodesuc=node->right;

				while(nodesuc->left!=NULL)
				{
					parent=nodesuc;
					nodesuc=nodesuc->left;
				}
				node->data=nodesuc->data;
				node=nodesuc;
			}


			/* if the node to be deleted has no child */

			if(node->left==NULL && node->right==NULL)
			{
				if(parent->right==node)
					parent->right=NULL;
				else
					parent->left=NULL;

				free(node);
				return;
			}

			/* if the node to be deleted has only right child */

			if(node->left==NULL && node->right!=NULL)
			{
				if(parent->left==node)
					parent->left=node->right;
				else
					parent->right=node->right;

				free(node);
				return;
			}

			/* if the node to be deleted has only left child */

			if(node->left!=NULL && node->right== NULL)
			{
				if(parent->left==node)
					parent->left=node->left;
				else
					parent->right=node->left;

				free(node);
				return;
			}
		}

	}

	/* travel the tree in inorder(left,root,right) fashion */

	void inorder(struct btreenode *sr)
	{



		if(sr!=NULL)
		{
			inorder(sr->left);
			/* print the data of the node whose left is NULL*/
			/* or the path has already been trversed        */
			printf("%4d",sr->data);
			inorder(sr->right);
		}
	}





void main()
{
	struct btreenode *head;
	int req,i=1,num,element;
	head=NULL;

	clrscr();
	printf("enter how many nodes do you want to enter : ");
	scanf("%d",&req);

	while(i<=req)
	{
		printf("enter data: ");
		scanf("%d",&num);
		insert(&head,num);
		i++;
	}

	printf("\n binary tree before deletion.....");
	inorder(head);

	printf("\n\n\n enter element to be deleted: ");
	scanf("%d",&element);

	del(&head,element);

	printf("\n\n binary tree after deletion....");
	inorder(head);

	getch();

}