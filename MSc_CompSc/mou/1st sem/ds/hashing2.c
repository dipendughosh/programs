//chaining hashing
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


struct node
{	int data;
	struct node *next;
};

struct node *a[10];
int n;

void main()
{   
	void insert();
	void search();
	void traverse();
	void delete1();
	int i,ch;
	printf("\nEnter number of buckets:- ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=(struct node *)malloc(sizeof(struct node));
		a[i]->data=i;
		a[i]->next=NULL;
	}
	do
	{   
		printf("\t\tMenu");
		printf("\n\t1.Insert");
		printf("\n\t2.Search");
		printf("\n\t3.Traverse");
		printf("\n\t4.Delete");
		printf("\n\t5.Exit");
		printf("\nEnter choice-");
		scanf("%d",&ch);
		switch(ch)
		{	case 1:
				insert();
				break;
			case 2:
				search();
				break;
			case 3:
				traverse();
				break;
			case 4:
				delete1();
				break;
			case 5:
				printf("\nExiting prgram......");
				getch();
				exit(0);
			default:
				printf("\nWrong choice");
				getch();
				break;
		}
	}while(1);
}

void insert()
{	
	int item,k;
	struct node *ptr,*new1;
	new1=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter Key - ");
	scanf("%d",&item);
	new1->data=item;
	new1->next=NULL;
	k=item%n;
	if(a[k]->next==NULL)
	{	
		a[k]->next=new1;
		return;
	}
	ptr=a[k]->next;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=new1;
}

void search()
{	
	int item,k;
	struct node *ptr;
	printf("\nEnter key of item to search - ");
	scanf("%d",&item);
	k=item%n;
	ptr=a[k]->next;
	while(ptr!=NULL && ptr->data!=item)
		ptr=ptr->next;
	if(ptr==NULL)
	{	printf("\n%d not in list",item);
		return;
	}
	printf("%d in list\n",ptr->data);
}

void traverse()
{	
	struct node *ptr,*ptr1;
	int k=0;
	ptr=a[k]->next;
	while(k<n)
	{	ptr1=ptr;
		printf("\n%d",a[k]->data);
		while(ptr1!=NULL)
		{
			printf("\t%d",ptr1->data);
			ptr1=ptr1->next;
		}
		k++;
		if(k!=n)
			ptr=a[k]->next;
	}
}

void delete1()
{	
	struct node *ptr,*ptr1;
	int item,k;
	printf("\nEnter item to delete - ");
	scanf("%d",&item);
	k=item%n;
	ptr=a[k]->next;
	if(ptr->data==item)
	{	
		printf("\nDeleteing\n%d",ptr->data);
		a[k]->next=ptr->next;
		free(ptr);
		return;
	}
	while(ptr!=NULL && ptr->data!=item)
	{	
		ptr1=ptr;
		ptr=ptr->next;
	}
	if(ptr==NULL)
	{	
		printf("\n%d not in list",item);
		return;
	}
	ptr1->next=ptr->next;
	printf("\nDeleteing\n%d",ptr->data);
	free(ptr);
}
