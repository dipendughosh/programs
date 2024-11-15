//merge link list,sorted intersection & union
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

struct node
{	int data;
	struct node *next;
};

struct node* getnode(int x)
{       struct node *new1;
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=x;
	new1->next=NULL;
	return(new1);
}

void main()
{       struct node *head1,*head2,*head3,*head4;
	int c,i,x=1;
	void createlist(struct node **,struct node **);
	void union1(struct node **,struct node **,struct node **);
	void intersec(struct node **,struct node **,struct node **);
	void display(struct node *,struct node *,struct node *,struct node *);
	head1=head2=head3=head4=NULL;
	clrscr();
	do
	{       clrscr();
		printf("\t\tM E N U");
		printf("\n\t1.Create Link List");
		printf("\n\t2.Union Lists");
		printf("\n\t3.Intersection of Lists");
		printf("\n\t4.Display List");
		printf("\n\t5.Exit");
		printf("\n\n\tEnter Choice : - ");
		scanf("%d",&c);
		switch(c)
		{	case 1:
				if(head1!=NULL || head2!=NULL)
				{	printf("\nLists Exists,Do You want to create new lists(y=1,n=0)");
					scanf("%d",&x);
				}
				if(x==1)
				{
					head1=head2=NULL;
					createlist(&head1,&head2);
				}
				break;
			case 2:
				if(head1==NULL || head2==NULL)
					break;
				else
				{	union1(&head1,&head2,&head3);
					getch();
				}
				break;
			case 3:
				if(head1==NULL || head2==NULL)
					break;
				else
				{	intersec(&head1,&head2,&head4);
					getch();
				}
				break;
			case 4:
				if(head1==NULL || head2==NULL)
					break;
				else
				{	display(head1,head2,head3,head4);
					getch();
				}
				break;
			case 5:
				printf("Exiting Program");
				for(i=0;i<10;i++)
				{
					delay(600);
					printf(".");
				}
				exit(0);
			default:
				printf("\n\n\aWrong input\a");
				break;
		}
	}while(1);
}

void createlist(struct node **head1,struct node **head2)
{       struct node *new1,*ptr;
	int x;
	printf("\n\tCreating 1st List(sorted order):-\n");
	(*head1)=NULL;
	printf("Enter value (-999 to stop) - ");
	scanf("%d",&x);
	while(x!=-999)
	{	new1=getnode(x);
		if((*head1)==NULL)
			(*head1)=new1;
		else
		{	ptr=(*head1);
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new1;
		}
		printf("Enter value (-999 to stop) - ");
		scanf("%d",&x);
	}
	printf("\n\tCreating 2nd List(sorted order):-\n");
	(*head2)=NULL;
	printf("Enter value (-999 to stop) - ");
	scanf("%d",&x);
	while(x!=-999)
	{	new1=getnode(x);
		if((*head2)==NULL)
			(*head2)=new1;
		else
		{	ptr=(*head2);
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new1;
		}
		printf("Enter value (-999 to stop) - ");
		scanf("%d",&x);
	}
}

void union1(struct node **head1,struct node **head2,struct node **head3)
{       struct node *new1,*ptr,*ptr1,*ptr2;
	ptr1=(*head1);
	ptr2=(*head2);
	while(ptr1!=NULL && ptr2!=NULL)
	{	if(ptr2->data < ptr1->data)
		{	new1=getnode(ptr2->data);
			if((*head3)==NULL)
				(*head3)=new1;
			else
			{	ptr=(*head3);
				while(ptr->next!=NULL)
					ptr=ptr->next;
				ptr->next=new1;
			}
			ptr2=ptr2->next;
		}
		else if(ptr2->data > ptr1->data)
		{	new1=getnode(ptr1->data);
			if((*head3)==NULL)
				(*head3)=new1;
			else
			{	ptr=(*head3);
				while(ptr->next!=NULL)
					ptr=ptr->next;
				ptr->next=new1;
			}
			ptr1=ptr1->next;
		}
		else
		{	new1=getnode(ptr1->data);
			if((*head3)==NULL)
				(*head3)=new1;
			else
			{	ptr=(*head3);
				while(ptr->next!=NULL)
					ptr=ptr->next;
				ptr->next=new1;
			}
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
	}
	if(ptr1==NULL)
	{	ptr=(*head3);
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=ptr2;

	}
	else if(ptr2==NULL)
	{	ptr=(*head3);
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=ptr1;
	}
}

void intersec(struct node **head1,struct node **head2,struct node **head4)
{       struct node *new1,*ptr,*ptr1,*ptr2;
	ptr1=(*head1);
	ptr2=(*head2);
	while(ptr1!=NULL && ptr2!=NULL)
	{	if(ptr2->data < ptr1->data)
			ptr2=ptr2->next;
		else if(ptr2->data > ptr1->data)
			ptr1=ptr1->next;
		else
		{	new1=getnode(ptr1->data);
			if((*head4)==NULL)
				(*head4)=new1;
			else
			{	ptr=(*head4);
				while(ptr->next!=NULL)
					ptr=ptr->next;
				ptr->next=new1;
			}
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
	}
}

void display(struct node *head1,struct node *head2,struct node *head3,struct node *head4)
{       struct node *ptr;
	printf("\n\tDisplaying 1st List Items:-\n");
	ptr=head1;
	while(ptr!=NULL)
	{	printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("\n\tDisplaying 2nd List Items:-\n");
	ptr=head2;
	while(ptr!=NULL)
	{	printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	if(head3!=NULL)
	{	printf("\n\tDisplaying Union List Items:-\n");
		ptr=head3;
		while(ptr!=NULL)
		{	printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
	if(head4!=NULL)
	{	printf("\n\tDisplaying Intersected List Items:-\n");
		ptr=head4;
		while(ptr!=NULL)
		{	printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}
