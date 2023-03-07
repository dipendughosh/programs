//Q using link list
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

//Node structure of a node of the queue
struct node
{	int data;
	struct node *next;
};

//To create a node with the data passed to the function
struct node* getnode(int x)
{       struct node *new1;
	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=x;
	return(new1);
}

void main()
{       //Declaring variables and functions
	struct node *front=NULL,*rear=NULL;
	int c,i;
	void insert(struct node **,struct node **);
	void delete1(struct node **,struct node **);
	void display(struct node *,struct node *);
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
				if(front==NULL)
				{	insert(&front,&rear);
				}
				else
					insert(&front,&rear);
				break;
			case 2:
				if(front==NULL)
				{	printf("\nQueue does not exist");
					getch();
				}
				else
				{	delete1(&front,&rear);
					getch();
				}
				break;
			case 3:
				if(front==NULL)
				{	printf("\nQueue does not exist");
					getch();
				}
				else
				{	display(front,rear);
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

void insert(struct node **f,struct node **r)
{       struct node *new1;
	int x;
	printf("Enter value - ");
	scanf("%d",&x);
	new1=getnode(x);
	if((*f)==NULL && (*r)==NULL)
	{       (*f)=new1;
		(*r)=new1;
	}
	else
	{	(*r)->next=new1;
		(*r)=new1;
	}
}


void delete1(struct node **f,struct node **r)
{       struct node *ptr;
	int item;
	if((*f)==(*r))
	{	printf("\nDeleted data - %d",(*f)->data);
		free(*f);
		*f=NULL;
		*r=NULL;
		return;
	}
	ptr=(*f);
	(*f)=(*f)->next;
	printf("\nDeleted data - %d",ptr->data);
	free(ptr);
}

void display(struct node *f,struct node *r)
{       printf("\n\tDisplaying List Items:-\n");
	while(f!=r)
	{	printf("%d\t",f->data);
		f=f->next;
	}
	printf("%d",f->data);
}

