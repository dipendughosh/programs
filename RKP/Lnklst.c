//Single Linked List
#include<stdio.h>
#include<conio.h>
//#include<alloc.h>
//#define NULL 0

//Node structure of the link list
struct node
{	int data;//Data part of the node
	struct node *next;//Address part of the node
};

//Function to create a node with x as its data
struct node* getnode(int x)
{      	struct node *new1;
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=x;
	new1->next=NULL;
	return(new1);
}

int main()
{       //Declaring variables and functions
	struct node *head=NULL,*head2=NULL;
	int c,i,c1,c2;
	void create(struct node **);
	void append(struct node *);
	void display(struct node *,struct node *);
	void insertatbeg(struct node **);
	void insertatend(struct node *);
//	clrscr();
	do
	{//       clrscr();
		printf("\t\tM E N U");
		printf("\n\t1.Create Link List");
		printf("\n\t2.Append");
		printf("\n\t3.Display");
		printf("\n\t4.Insert Begin");
		printf("\n\t5.Insert End");
		printf("\n\t6.Exit");
		printf("\n\n\tEnter Choice : - ");
		scanf("%d",&c);
	//	clrscr();
		switch(c)
		{	case 1:
				if(head!=NULL)
				{	printf("\nList Exists");
					break;
				}
				else
					create(&head);
				break;
			case 2:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					append(head);
				break;
			case 3:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
				{	display(head,head2);
					getch();
				}
				break;
			case 4:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					insertatbeg(&head);
				break;
			case 5:
				if(head==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					insertatend(head);
				break;
			case 6:
				printf("Exiting Program");
				getch();
				exit(0);
			default:
				printf("\n\n\aWrong input\a");
				break;
		}
		getch();
	}while(1);
	return(0);
}

//Function to create the linked list
void create(struct node **h)
{	struct node *new1;
	int x;
	printf("\n\tCreating List:-\n");
	printf("Enter value - ");
	scanf("%d",&x);
	new1=getnode(x);
	*h=new1;
}

//Function to append the linked list
void append(struct node *h)
{	int x;
	struct node *new1,*ptr;
	printf("\n\tAppending List:-\n");
	printf("Enter value - ");
	scanf("%d",&x);
	new1=getnode(x);
	ptr=h;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=new1;
}

//Function to display the elements of the list
void display(struct node *h1,struct node *h2)
{       struct node *ptr;
	printf("\n\tDisplaying List Items:-\n");
	ptr=h1;
	while(ptr!=NULL)
	{	printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	ptr=h2;
	if(ptr!=NULL)
	{       printf("\nCopied List is-:\n");
		while(ptr!=NULL)
		{	printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}

//Function to insert an element at the begining of the list
void insertatbeg(struct node **h)
{	int x;
	struct node *new1;
	printf("\n\tInserting Element at Begining:-");
	printf("\nEnter value - ");
	scanf("%d",&x);
	new1=getnode(x);
	new1->next=*h;
	*h=new1;
}

//Function to insert an element at the end of the list
void insertatend(struct node *h)
{	int x;
	struct node *new1,*ptr;
	printf("\n\tInserting Element at End:-");
	printf("\nEnter value - ");
	scanf("%d",&x);
	new1=getnode(x);
	ptr=h;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=new1;
}
