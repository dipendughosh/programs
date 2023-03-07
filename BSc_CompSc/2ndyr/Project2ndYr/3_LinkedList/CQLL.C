//Circular queue using link list
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

//Node structure of the circular queue
struct node
{	int data;
	struct node *next;
};

//To create a node with x as the data
struct node* getnode(int x)
{       struct node *new1;
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=x;
	return(new1);
}

void main()
{       //Declaring variables and functions
	struct node *tail=NULL;
	int c,i;
	void insert(struct node **);
	void delete1(struct node **);
	void display(struct node *);
	clrscr();
	do
	{       clrscr();
		printf("\t\tM E N U");
		printf("\n\t1.Insert");
		printf("\n\t2.Delete");
		printf("\n\t3.Display");
		printf("\n\t4.Exit");
		printf("\n\n\tEnter Choice : - ");
		scanf("%d",&c);
		switch(c)
		{	case 1:
				if(tail==NULL)
					insert(&tail);
				else
					insert(&tail);
				break;
			case 2:
				if(tail==NULL)
				{	printf("\nQueue does not exist");
					getch();
				}
				else
					delete1(&tail);
				break;
			case 3:
				if(tail==NULL)
				{	printf("\nQueue does not exist");
					getch();
				}
				else
				{	display(tail);
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

//Insert function to enter a data into the circular queue
void insert(struct node **t)
{       struct node *new1;
	int x;
	printf("Enter value - ");
	scanf("%d",&x);
	new1=getnode(x);
	if((*t)==NULL)
	{       (*t)=new1;
		(*t)->next=new1;
		return;
	}
	new1->next=(*t)->next;
	(*t)->next=new1;
	(*t)=new1;
}

//Delete function to delete a data from the circular queue
void delete1(struct node **t)
{       struct node *ptr;
	int item;
	if((*t)==(*t)->next)
	{	printf("\nDeleted data - %d",(*t)->data);
		getch();
		free(*t);
		*t=NULL;
		return;
	}
	ptr=(*t)->next;
	(*t)->next=(*t)->next->next;
	printf("\nDeleted data - %d",ptr->data);
	free(ptr);
	getch();
}

//Function to display the contents of the circular queue
void display(struct node *t)
{       struct node *ptr;
	printf("\n\tDisplaying List Items:-\n");
	ptr=t->next;
	while(ptr!=t)
	{	printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("%d",ptr->data);
}

