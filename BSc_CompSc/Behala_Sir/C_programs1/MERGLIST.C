/* 		         surya rules			*/

/*		 merging of two linked lists		*/

/* 		the program is working fine		*/



#include"stdio.h"
#include"conio.h"
#include"graphics.h"
#include"dos.h"
#include"string.h"
#include"math.h"
#include"alloc.h"

struct node
{
	int data ;
	struct node *link;
};

void display( struct node *);
count (struct node *);
void merge(struct node *,struct node *,struct node **);
void add (struct node **,int );
void main()
{
	struct node *first,*second,*third;
	first=second=third=NULL;
	add(&first,1);
	add(&first,2);
	add(&first,3);
	add(&first,4);
	add(&first,5);
	add(&first,6);
	add(&first,7);

	clrscr();
	printf("first linked list:");
	display(first);
	printf("\n no.of elements in the list is : %d",count(first));

	add(&second,8);
	add(&second,9);
	add(&second,3);
	add(&second,4);
	add(&second,5);
	add(&second,6);
	add(&second,7);

	printf("\n\n second linked list:");
	display(second);
	printf("\n no.of elements in the linked list is : %d ",count(second));


	merge(first,second,&third);

	printf("\n\n the concatenated list :");
	display(third);
	printf("\n no.of elements in the linked list: %d ",count(third));

	getch();
}


/* adds node to an ascending order linked list */

void add (struct node **q,int num)
{
	struct node *r,*temp=*q;
	r=(struct node *)malloc(sizeof(struct node));
	r->data=num;

	/* if list is empty or if new node is to be added before the first node */

	if(*q==NULL ||(*q)->data>num)
	{
		*q=r;
		(*q)->link= temp;
	}
	else
	{
		/* traverse the entire linked list to search the position to insert the new node */

		while (temp!= NULL)
		{
			if (temp->data<num && temp->link->data>num ||temp->link==NULL)
			{
				r->link=temp->link;
				temp->link=r;
				return;
			}
			temp=temp->link; /* goto next node */
		}
		r->link=NULL;
		temp->link=r;
	}
}

/* displays the contents of the linked list */

void display( struct node *q)
{
	printf("\n");

	/* traverse the entire linked list */

	while(q!=NULL)
	{
		printf(" %d ",q->data);
		q=q->link;
	}
}

/* counts the number of nodes present in the linked list */

count (struct node *q)
{
	int c=0;
	while (q!=NULL)
	{
		q=q->link;
		c++;
	}
	return c;
}

/* merges the two linked lists, restricting the common elements to occur only once in the final list */


void merge(struct node *p,struct node *q,struct node **s)
{
	struct node *z;
	z=NULL;

	/* if both lists are empty */

	if(p==NULL && q==NULL)
		return;

	/* traverse both linked lists till the end.if end of anyone list is reached loop is terminated */

	while(p!=NULL && q!=NULL)
	{
		/* if node being added in the first node */

		if(*s==NULL)
		{
			*s=(struct node *)malloc(sizeof(struct node));
			z=*s;
		}
		else
		{
			z->link=(struct node *)malloc(sizeof(struct node));
			z=z->link;
		}
		if(p->data<q->data)
		{
			z->data=p->data;
			p=p->link;
		}
		else
		{
			if(q->data<p->data)
			{
				z->data=q->data;
				q=q->link;
			}
			else
			{
				if(p->data==q->data)
				{
					z->data=q->data;
					p=p->link;
					q=q->link;
				}
			}
		}
	}

	/* if end of first list has not been reached */

	while(p!=NULL)
	{
		z->link=(struct node *)malloc(sizeof(struct node));
		z=z->link;
		z->data=p->data;
		p=p->link;
	}

	/* if end of second list has not been reached */

	while(q!=NULL)
	{
		z->link=(struct node *)malloc(sizeof(struct node));
		z=z->link;
		z->data=q->data;
		q=q->link;
	}
	z->link=NULL;
}






