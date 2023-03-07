//q using link list all,ok
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
	return(new1);
}

void main()
{       struct node *tail;
	int c,i,z=0;

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
				if(z==0)
				{	insert(&tail);
					z=1;
				}
				else
					insert(&tail);
				break;
			case 2:
				if(tail==NULL)
					printf("\nQueue does not exist");
				else
					delete1(&tail);
				break;
			case 3:
				if(tail==NULL)
					printf("\nQueue does not exist");
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

void display(struct node *t)
{       struct node *ptr;
	printf("\n\tDisplaying List Items:-\n");
	ptr=t->next;
	while(ptr!=t)
	{	printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("%d",ptr->data);
	printf("<-front");
	getch();
}

