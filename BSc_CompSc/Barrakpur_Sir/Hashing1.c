//chain hashing
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define NULL 0

struct node
{	int roll;
	char name[30];
	struct node *next;
};

void main()
{       struct node *a[100];
	void insert(struct node **);
	void search(struct node **);
	void traverse(struct node **);
	void delete1(struct node **);
	int i,ch;
	clrscr();
	for(i=0;i<100;i++)
		a[i]=NULL;
	while(1)
	{       clrscr();
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
				insert(a);
				break;
			case 2:
				search(a);
				break;
			case 3:
				traverse(a);
				break;
			case 4:
				delete1(a);
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
		getch();
	}
}

void insert(struct node **a)
{	int item,k;
	struct node *ptr,*new1;
	new1=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter Key - ");
	scanf("%d",&item);
	printf("\nEnter Name-");
	fflush(stdin);
	gets(new1->name);
	new1->roll=item;
	new1->next=NULL;
	k=item%100;
	ptr=(*a+k);
	if(ptr==NULL)
	{	ptr=new1;
		return;
	}
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=new1;
}

void search(struct node **a)
{	int item,k;
	struct node *ptr;
	printf("\nEnter key of item to search - ");
	scanf("%d",&item);
	k=item%100;
	ptr=(*a+k);
	while(ptr!=NULL && ptr->roll!=item)
		ptr=ptr->next;
	if(ptr==NULL)
	{	printf("\n%d not in list",item);
		return;
	}
	printf("%d",ptr->roll);
	puts(ptr->name);
}

void traverse(struct node **a)
{	struct node *ptr,*ptr1;
	int k=0;
	ptr=*a;
	while(k<100)
	{	ptr1=ptr;
		while(ptr1!=NULL)
		{	printf("\n%d",ptr->roll);
			puts(ptr->name);
			ptr1=ptr1->next;
		}
		k++;
		ptr=ptr+k;
	}
}

void delete1(struct node **a)
{	struct node *ptr,*ptr1;
	int item,k;
	printf("\nEnter item to delete - ");
	scanf("%d",&item);
	k=item%100;
	ptr=(*a+k);
	if(ptr->roll==item)
	{	printf("\nDeleteing\n%d",ptr->roll);
		puts(ptr->name);
		ptr1=ptr;
		ptr=ptr->next;
		free(ptr1);
		return;
	}
	while(ptr!=NULL && ptr->roll!=item)
	{	ptr1=ptr;
		ptr=ptr->next;
	}
	if(ptr==NULL)
	{	printf("\n%d not in list",item);
		return;
	}
	ptr1->next=ptr->next;
	printf("\nDeleteing\n%d",ptr->roll);
	puts(ptr->name);
	free(ptr);
}
