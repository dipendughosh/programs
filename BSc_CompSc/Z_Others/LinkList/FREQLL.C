//frequency counting in a linked list,ok
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

struct node
{	int data;
	struct node *next;
}*head=NULL;

struct node *new1,*ptr,*ptr1,*ptr2,*ptr3;

struct node* getnode(int x)
{      	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=x;
	new1->next=NULL;
	return(new1);
}

void main()
{       int c,i;
	void createlist();
	void freq();
	clrscr();
	do
	{       clrscr();
		printf("\t\tM E N U");
		printf("\n\t1.Create Link List");
		printf("\n\t2.Count number of time each elemnt is in list");
		printf("\n\t3.Exit");
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
					freq();
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
	ptr=head;
	while(ptr!=NULL)
	{	printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	getch();
}

void freq()
{       int i;
	ptr=head;
	while(ptr!=NULL)
	{	ptr2=ptr;
		ptr1=ptr->next;
		i=1;
		while(ptr1!=NULL)
		{	if(ptr->data==ptr1->data)
			{	i++;
				ptr3=ptr1;
				ptr2->next=ptr1->next;
				ptr1=ptr1->next;
				free(ptr3);
			}
			else
			{	ptr1=ptr1->next;
				ptr2=ptr2->next;
			}
		}
		printf("\n%d occors %d times",ptr->data,i);
		ptr=ptr->next;
	}
	getch();
}
