//swaping at given positions
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

struct node
{	int data;
	struct node *next;
}*head=NULL;

int count=0;

struct node *new1,*ptr,*ptr1,*ptr2,*ptr3,*ptr4;

struct node* getnode(int x)
{      	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=x;
	new1->next=NULL;
	return(new1);
}

void main()
{       int c,i;
	void createlist();
	void swap();
	void display();
	clrscr();
	do
	{       clrscr();
		printf("\t\tM E N U");
		printf("\n\t1.Create Link List");
		printf("\n\t2.Swap");
		printf("\n\t3.Display list");
		printf("\n\t4.Exit");
		printf("\n\n\tEnter Choice : - ");
		scanf("%d",&c);
		switch(c)
		{	case 1:
				createlist();
				break;
			case 2:
				if(head==NULL)
					break;
				else
					swap();
				break;
			case 3:
				if(head==NULL)
					break;
				else
				{	display();
					getch();
				}
				break;
			case 4:
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

void createlist()
{	int x;
	printf("\n\tCreating List:-\n");
	head=NULL;
	printf("Enter value (-999 to stop) - ");
	scanf("%d",&x);
	while(x!=-999)
	{	new1=getnode(x);
		if(head==NULL)
			head=new1;
		else
		{	ptr=head;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new1;
		}
		printf("Enter value (-999 to stop) - ");
		scanf("%d",&x);
	}
	count=1;
	ptr=head;
	while(ptr!=NULL)
	{	count++;
		ptr=ptr->next;
	}
}

void swap()
{	int a,b,c=1;
	do
	{	printf("\nEnter positions to swap data:---\n");
		printf("\nEnter first position:-");
		scanf("%d",&a);
		printf("\nEnter second position:-");
		scanf("%d",&b);
		if(a>count || b>count)
		{	printf("\nRe Enter,Out of range");
			continue;
		}
		else
			break;
	}while(1);
	if(b<a)
	{	c=b;
		b=a;
		a=c;
	}
	c=1;
	ptr=head;
	ptr1=ptr;
	ptr2=ptr3=ptr1->next;
	ptr4=ptr3->next;
	while(ptr!=NULL)// && (c!=a || c!=b))
	{	if(c<a-1)
		{	ptr1=ptr1->next;
			ptr2=ptr2->next;
			ptr3=ptr3->next;
			ptr4=ptr4->next;
		}
		else if(c<b-2)
		{	ptr3=ptr3->next;
			ptr4=ptr4->next;
		}
		ptr=ptr->next;
		c++;
	}
	ptr1->next=ptr4;
	ptr3->next=ptr2;
	ptr3=ptr4->next;
	ptr4->next=ptr2->next;
	ptr2->next=ptr3;
	/*ptr=head;
	while(ptr!=NULL)
	{       if(c==a)
			ptr1=ptr;
		else if(c==b)
			ptr2=ptr;
		ptr=ptr->next;
		c++;
	}
	c=ptr1->data;
	ptr1->data=ptr2->data;
	ptr2->data=c;*/
}

void display()
{       printf("\n\tDisplaying List Items:-\n");
	ptr=head;
	while(ptr!=NULL)
	{	printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}