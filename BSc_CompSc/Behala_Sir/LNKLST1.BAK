#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

struct node
{	int data;
	struct node *next;
}*head;

void main()
{       struct node *new1,*ptr;
	int x;
	clrscr();
	head = NULL;
	printf("Enter value (-999 to stop) ");
	scanf("%d",&x);
	while(x!=-999)
	{	new1=(struct node *)malloc(sizeof(struct node));
		new1->data=x;
		new1->next=NULL;
		if(head==NULL)
			head=new1;
		else
		{	ptr=head;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new1;
		}
		printf("\nEnter value (-999 to stop) ");
		scanf("%d",&x);
	}
	ptr=head;
	while(ptr!=NULL)
	{	printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	getch();
}

