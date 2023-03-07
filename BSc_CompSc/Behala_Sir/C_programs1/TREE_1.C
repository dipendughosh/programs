/* 		         surya rules			*/

/*	      creation of a binary search tree		*/
/*		  searching an element			*/
/*		deletion of the searched node		*/

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

	void inorder(struct btreenode *sr)
	{

		if(sr!=NULL)
		{
			inorder(sr->left);
			printf("\n	%d",sr->data);
			inorder(sr->right);
			printf("\n\n");
		}
	}

	void insert(struct btreenode **sr,int num)
	{
	       //	printf("item = %d",num);


		if((*sr)==NULL)
		{
			(*sr)=(struct btreenode *)malloc(sizeof(struct btreenode));

			(*sr)->left=NULL;
			(*sr)->data=num;
			(*sr)->right=NULL;
		}


		else
		{
			/* if new data is less traverse left */
			if(num<((*sr)->data))
				insert(&((*sr)->left),num);

			else
				/* traverse to right */
				insert(&((*sr)->right),num);
		}
	}


	struct btreenode *find(struct btreenode **sr,int item)
	{

		struct btreenode *ptr;

		ptr=*sr;

		do
		{
			if(item==ptr->data)
			{
				return(ptr);
			}
			if(item<ptr->data)
			{
				ptr=ptr->left;
			}
			else
			{
				ptr=ptr->right;
			}

		}while(ptr!=NULL);

		return (0);

	}


	void del(struct btreenode **sr,struct btreenode *loc)
	{
		struct btreenode *child,*ptr,*par,*save,*suc,*parsuc;
		ptr=loc;
		par=*sr;

		/* finding the parent of the node that is to be deleted */

		while(par->left!=loc || par->right!=loc)
		{
			if(loc->data < par->data)
				par=par->left;
			else
				par=par->right;
		}

		/* deletion of the node */

		if(loc->right!=NULL && loc->left!=NULL)
		{
			ptr=loc->right;
			save=loc;
			while(ptr->left!=NULL)
			{
				save=ptr;
				ptr=ptr->left;
			}
				suc=ptr;
				parsuc=save;


			/* deletion of inorder successor (use the else method) */
			/* using suc in place of ptr in else method */
			/* using parsuc in place of par */

			if(suc->left==NULL && suc->right==NULL)
				child=NULL;

			else if(suc->left!=NULL)
				child=suc->left;
			else
				child=suc->right;



			if(suc==parsuc->left)
				parsuc->left=child;
			else
				parsuc->right=child;

	    /* deletion of inorder successor ends */

			if(loc==par->left)
				par->left=suc;
			else
				par->right=suc;


			suc->left=loc->left;
			suc->right=loc->right;


		}

		else

		{
			if(ptr->left==NULL && ptr->right==NULL)
				child=NULL;

			else if(ptr->left!=NULL)
				child=ptr->left;
			else
				child=ptr->right;



			if(loc==par->left)
				par->left=child;
			else
				par->right=child;
		}
	}

void main()
{

	struct btreenode *head,*loc;
	int req,num,i=1,item;
	head=NULL;	/* empty tree */

	clrscr();
	printf("enter the number of data to be inserted: ");
	scanf("%d",&req);

	while(i++<=req)
	{
		printf("\n enter data: ");

		scanf("%d",&num);
		insert(&head,num);
	}

	printf("\n enter item to be searched in the tree:");
	scanf("%d",&item);

	loc=find(&head,item);

	if(item==loc->data)
		printf("\n search successful");
	else
		printf("\n search unsuccessful");
	printf("\n\n\n\n\n item=%d ",loc->data);

	inorder(head);
	getch();
	printf("\n\n");
	del(&head,loc);
	inorder(head);


	getch();

}