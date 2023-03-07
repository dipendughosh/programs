//converting array to linked kist,ok
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

struct node
{	int data;
	struct node *next;
}*head=NULL;

struct node *new1,*ptr;

struct node* getnode(int x)
{      	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=x;
	new1->next=NULL;
	return(new1);
}

void main()
{       int c,i,a[10];
	void createlist(int []);
	void display();
	clrscr();
	do
	{       clrscr();
		printf("\t\tM E N U");
		printf("\n\t1.Create Link List");
		printf("\n\t2.Display");
		printf("\n\t3.Exit");
		printf("\n\n\tEnter Choice : - ");
		scanf("%d",&c);
		switch(c)
		{	case 1:
				printf("\nEnter elements of an array:-\n");
				for(i=0;i<10;i++)
					scanf("%d",&a[i]);
				createlist(a);
				break;
			case 2:
				if(head==NULL)
					break;
				else
					display();
				break;
			case 3:
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

void createlist(int a[10])
{	int i=0;
	printf("\n\tCreating List:-\n");
	head=NULL;
	while(i<10)
	{	new1=getnode(a[i]);
		if(head==NULL)
			head=new1;
		else
		{	ptr=head;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new1;
		}
		i++;
	}
}

void display()
{	printf("\n\t\tDisplaying List:-\n");
	ptr=head;
	while(ptr!=NULL)
	{	printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	getch();
}