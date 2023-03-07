//sorting a link list,(descending & ascending),(value),ok
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

struct node
{	int data;
	struct node *next;
};


struct node *new1,*ptr,*ptr1,*ptr2,*head,*head2;

struct node* getnode(int x)
{      	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=x;
	new1->next=NULL;
	return(new1);
}

void dscend();
void ascend();

void main()
{       int c,i;
	void createlist();
	void sort();
	void display();
	head=NULL;
	head2=NULL;
	clrscr();
	do
	{       clrscr();
		printf("\t\tM E N U");
		printf("\n\t1.Create Link List");
		printf("\n\t2.Sort List");
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
				{	sort();
					getch();
				}
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
}

void sort()
{       int c;
	clrscr();
	printf("\t\tM E N U");
	printf("\n\t1.Descending");
	printf("\n\t2.Ascending");
	printf("\n\n\tEnter Choice : - ");
	scanf("%d",&c);
	switch(c)
	{	case 1:
			dscend();
			break;
		case 2:
			ascend();
			break;
		default:
			printf("\n\n\aWrong input\a");
			break;
	}
}

void dscend()
{	int item;
	ptr1=head;
	while(ptr1->next!=NULL)
	{       ptr2=ptr1->next;
		while(ptr2!=NULL)
		{	if(ptr1->data>=ptr2->data)
			{	item=ptr2->data;
				ptr2->data=ptr1->data;
				ptr1->data=item;
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
}

void ascend()
{	int item;
	ptr1=head;
	while(ptr1->next!=NULL)
	{       ptr2=ptr1->next;
		while(ptr2!=NULL)
		{	if(ptr1->data<=ptr2->data)
			{	item=ptr2->data;
				ptr2->data=ptr1->data;
				ptr1->data=item;
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
}

void display()
{       printf("\n\tDisplaying List Items:-\n");
	ptr=head;
	while(ptr!=NULL)
	{	printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}