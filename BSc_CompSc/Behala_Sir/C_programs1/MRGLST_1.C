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
	int data;
	struct node *next;
};
void display(struct node *);
count(struct node *);
void add(struct node **,int);
void merge(struct node *, struct node *,struct node **);




void main()
{
	struct node *head_1,*head_2,*head_3;
	head_1=head_2=head_3=NULL;

	add(&head_1,1);
	add(&head_1,2);
	add(&head_1,3);
	add(&head_1,4);
	add(&head_1,5);
	add(&head_1,6);
	add(&head_1,7);

	clrscr();
	printf("first linked list:");
	display(head_1);
	printf("\n no.of elements in the linked list: %d",count(head_1));

	add(&head_2,8);
	add(&head_2,9);
	add(&head_2,3);
	add(&head_2,4);
	add(&head_2,5);
	add(&head_2,6);
	add(&head_2,7);

	printf("\n\n\n second linked list: ");
	display(head_2);
	printf("\n no.of elements in the linked list: %d",count(head_2));

	merge(head_1,head_2,&head_3);

	printf("\n\n\n the merged list:");
	display(head_3);
	printf("\n no.of elements in the list:%d",count(head_3));


	getch();

}

void add(struct node **head,int num)
{
	struct node *new1,*temp;
	temp=*head;
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=num;

	/* if the list is empty or if new node is to be added before the first node */

	if(*head==NULL || (*head)->data>num)
	{
		*head=new1;
		(*head)->next=temp;
	}
	else
	{
		/* traverse the entire linked list  to search the position */
		/* to insert the new node */

		while(temp!=NULL)
		{
			if(temp->data<num && (temp->next->data>num ||temp->next==NULL))
			{
				new1->next=temp->next;
				temp->next=new1;
				return;
			}

			temp=temp->next;	/* goto next node */
		}

		/* if num is greater than all other number present in the list */

		new1->next=NULL;
		temp->next=new1;
	}
}

void display(struct node *h)
{
	printf("\n");

	while(h!=NULL)
	{
		printf("%d  ",h->data);
		h=h->next;
	}
}

count(struct node *h)
{
	int c=0;

	while(h!=NULL)
	{
		h=h->next;
		c++;
	}
	return c;
}

void merge(struct node *h1, struct node *h2,struct node **h3)
{

	struct node *z;
	z=NULL;

	/* perform no work if the lists are empty */

	if(h1==NULL && h2==NULL)
		return;

	/* proceed if both the lists have elements */

	while(h1!=NULL && h2!=NULL)
	{
		/* if node is being added to the first node */

		if (*h3==NULL)
		{
			*h3=(struct node *)malloc(sizeof(struct node));
			z=*h3;
		}
		else
		{
			z->next=(struct node *)malloc(sizeof(struct node));
			z=z->next;
		}

		if(h1->data < h2->data)
		{
			z->data=h1->data;
			h1=h1->next;
		}


		else
		{
			if(h2->data < h1->data)
			{
				z->data = h2->data;
				h2=h2->next;
			}
			else
			{
				if(h1->data==h2->data)
				{
					z->data=h1->data;
					h1=h1->next;
					h2=h2->next;
				}
			}
		}

	}

	while(h1!=NULL)
	{
		z->next=(struct node *)malloc(sizeof(struct node));
		z=z->next;
		z->data=h1->data;
		h1=h1->next;

	}

	while(h2!=NULL)
	{
		z->next=(struct node *)malloc(sizeof(struct node));
		z=z->next;
		z->data=h2->data;
		h2=h2->next;

	}

	z->next=NULL;

	//display(z);

}




