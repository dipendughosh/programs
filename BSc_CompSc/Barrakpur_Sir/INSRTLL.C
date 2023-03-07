//insertion sort using link list
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

struct node
{	int data;
	struct node *next;
};

struct node* getnode(int x)
{      	struct node *new1;
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=x;
	new1->next=NULL;
	return(new1);
}

void main()
{       struct node *head=NULL;
	void create(struct node **);
	void display(struct node *);
	void insert(struct node **);
	clrscr();
	create(&head);
	display(head);
	insert(&head);
	display(head);
	getch();
}

void create(struct node **h)
{	struct node *new1,*ptr;
	int x;
	printf("\tCreating List:-\n");
	printf("Enter value (-999 to stop) ");
	scanf("%d",&x);
	while(x!=-999)
	{	new1=getnode(x);
		if(*h==NULL)
			*h=new1;
		else
		{	ptr=*h;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new1;
		}
		printf("Enter value (-999 to stop) ");
		scanf("%d",&x);
	}
}

void display(struct node *h1)
{       struct node *ptr;
	printf("\n\tDisplaying List Items:-\n");
	ptr=h1;
	while(ptr!=NULL)
	{	printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}

/*void insert(struct node **h1)
{	int t;
	struct node *h2,*temp,*ptr;
	h2=NULL;
	while((*h1)!=NULL)
	{	temp=(*h1);
		(*h1)=(*h1)->next;
		while(1)
		{	if(h2==NULL)
			{	h2=temp;
				h2->next=NULL;
				break;
			}
			ptr=h2;
			while(ptr->next!=NULL && ptr->data<=temp->data)
				ptr=ptr->next;
			if(ptr==h2)
			{       if(h2->data>=temp->data)
				{	temp->next=h2;
					h2=temp;
					break;
				}
				else
				{	h2->next=temp;
					temp->next=NULL;
					break;
				}
			}
			if(ptr->data<=temp->data)
			{	temp->next=ptr->next;
				ptr->next=temp;
				break;
			}
			else
			{	continue;
			}
		}
	}
	(*h1)=h2;
} */

void insert(struct node **h)
{	struct node *h1=NULL,*temp=NULL,*qtr=NULL,*ptr=NULL;
	int flag=0;
	while((*h)!=NULL)
	{       flag=0;
		temp=(*h);
		(*h)=(*h)->next;
		if(h1==NULL)
		{	h1=temp;
			h1->next=NULL;
		}
		else
		{       while(flag==0)
			{	qtr=h1;
				while(qtr->next!=ptr)
					qtr=qtr->next;
				if(temp->data>=qtr->data)
				{	temp->next=qtr->next;
					qtr->next=temp;
					flag=1;
				}
				if(flag==1)
					break;
				else
					ptr=qtr;
			}
		}
		if(ptr==h1)
		{	temp->next=h1;
			h1=temp;
		}
	}
	(*h)=h1;
}
