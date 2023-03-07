//stack using linklist,ok
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
void push(struct node **);
void pop(struct node **);
void displaystack(struct node *);

void main()
{       struct node *top;
	int c,i,z=0;
	clrscr();
	do
	{	clrscr();
		printf("\t\tM E N U");
		printf("\n\t1.PUSH");
		printf("\n\t2.POP");
		printf("\n\t3.Display Stack");
		printf("\n\t4.Exit");
		printf("\n\tEnter choice:-");
		scanf("%d",&c);
		switch(c)
		{	case 1:
				if(z==0)
				{	push(&top);
					z=1;
				}
				else
					push(&top);
				break;
			case 2:
				if(top==NULL)
				{	printf("Stack empty");
					getch();
				}
				else
					pop(&top);
				break;
			case 3:
				if(top==NULL)
				{	printf("Stack empty");
					getch();
				}
				else
					displaystack(top);
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

void push(struct node **tp)
{       struct node *new1;
	int x;
	printf("\nEnter node value - ");
	scanf("%d",&x);
	new1=getnode(x);
	new1->next=(*tp);
	(*tp)=new1;
}

void pop(struct node **tp)
{       struct node *new1;
	int x;
	if((*tp)->next==NULL)
	{	printf("\nDeleted data - %d",(*tp)->data);
		free(*tp);
		*tp=NULL;
		getch();
		return;
	}
	new1=(*tp);
	x=(*tp)->data;
	(*tp)=(*tp)->next;
	free(new1);
	printf("\nDeleted data - %d",x);
	getch();
}

void displaystack(struct node *tp)
{       struct node *new1;
	new1=tp;
	while(new1->next!=NULL)
	{	printf("%d\n",new1->data);
		new1=new1->next;
	}
	getch();
}




