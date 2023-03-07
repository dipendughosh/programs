//double circular link list all(passing head),ok
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

struct node
{       struct node *previous;
	int data;
	struct node *next;
};

struct node* getnode(int x)
{      	struct node *new1;
	new1=(struct node *)malloc(sizeof(struct node));
	new1->previous=NULL;
	new1->data=x;
	new1->next=NULL;
	return(new1);
}

void main()
{       struct node *head=NULL,*tail=NULL;
	int c,i,c1,c2;
/*1*/	void create(struct node **,struct node **);
/*2*/	void append(struct node **,struct node **);
/*3*/	void display(struct node *,struct node *);
/*4*/	void insertbefor(struct node **,struct node **);
/*5*/	void insertaftr(struct node **,struct node **);
/*6*/	void delete1(struct node **,struct node **);
/*7*/	void reverse(struct node **,struct node **);
/*8*/   void sort(struct node **,struct node **);
	clrscr();
	do
	{       clrscr();
		printf("\t\tM E N U");
		printf("\n\t1.Create Link List");
		printf("\n\t2.Append");
		printf("\n\t3.Display");
		printf("\n\t4.Insert Before");
		printf("\n\t5.Insert After");
		printf("\n\t6.Delete");
		printf("\n\t7.Reverse");
		printf("\n\t8.Sort");
		printf("\n\t9.Exit");
		printf("\n\n\tEnter Choice : - ");
		scanf("%d",&c);
		clrscr();
		switch(c)
		{	case 1:
				if(head!=NULL && tail!=NULL)
				{	printf("\nList Exists");
					break;
				}
				else
					create(&head,&tail);
				break;
			case 2:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					append(&head,&tail);
				break;
			case 3:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
				{	display(head,tail);
					getch();
				}
				break;
			case 4:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					insertbefor(&head,&tail);
				break;
			case 5:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					insertaftr(&head,&tail);
				break;
			case 6:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					delete1(&head,&tail);
				break;
			case 7:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					reverse(&head,&tail);
				break;
			case 8:
				if(head==NULL && tail==NULL)
				{	printf("\nList does not Exists");
					break;
				}
				else
					sort(&head,&tail);
				break;
			case 9:
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
		getch();
	}while(1);
}

/*1*/
void create(struct node **h,struct node **t)
{	struct node *new1;
	int x;
	printf("\n\tCreating List:-\n");
	printf("Enter value - ");
	scanf("%d",&x);
	new1=getnode(x);
	new1->next=new1;
	new1->previous=new1;
	*h=new1;
	*t=new1;
}

/*2*/
void append(struct node **h,struct node **t)
{	int x;
	struct node *new1,*ptr;
	printf("\n\tAppending List:-\n");
	printf("Enter value - ");
	scanf("%d",&x);
	new1=getnode(x);
	ptr=*h;
	while(ptr->next!=(*h))
		ptr=ptr->next;
	new1->next=ptr->next;
	new1->previous=ptr;
	ptr->next=new1;
	*t=new1;
	(*h)->previous=new1;
}

/*3*/
void display(struct node *h,struct node *t)
{       struct node *ptr;
	int c;
	printf("\n\tDisplaying List Items:-\n");
	printf("\t1.Forward Display\n\t2.Backward Display\n\tEnter Choice : - ");
	scanf("%d",&c);
	switch(c)
	{	case 1:
			ptr=h;
			while(ptr->next!=h)
			{	printf("%u | %d | %u\n",ptr->previous,ptr->data,ptr->next);
				ptr=ptr->next;
			}
			printf("%u | %d | %u\n",ptr->previous,ptr->data,ptr->next);
			break;
		case 2:
			ptr=t;
			while(ptr->previous!=t)
			{	printf("%u | %d | %u\n",ptr->previous,ptr->data,ptr->next);
				ptr=ptr->previous;
			}
			printf("%u | %d | %u\n",ptr->previous,ptr->data,ptr->next);
			break;
		default:
			printf("\nWrong input");
			break;
	}
}

/*4*/
void insertbefor(struct node **h,struct node **t)
{	int x,y;
	struct node *new1,*ptr;
	printf("\n\tInserting Element Before a Node:-");
	printf("\nEnter Node before which to add - ");
	scanf("%d",&x);
	printf("\nEnter value - ");
	scanf("%d",&y);
	new1=getnode(y);
	ptr=*h;
	if((*h)->data==x)
	{       new1->previous=(*h)->previous;
		(*h)->previous=new1;
		new1->next=(*h);
		*h=new1;
		(*t)->next=new1;
		return;
	}
	while(ptr->next!=*h)
	{       if(ptr->next->data==x)
		{	new1->next=ptr->next;
			new1->previous=ptr;
			ptr->next->previous=new1;
			ptr->next=new1;
			return;
		}
		ptr=ptr->next;
	}
	printf("%d does not exists",x);
}

/*5*/
void insertaftr(struct node **h,struct node **t)
{	int x,y;
	struct node *new1,*ptr;
	printf("\n\tInserting Element After a Node:-");
	printf("\nEnter Node after which to add - ");
	scanf("%d",&x);
	printf("\nEnter value - ");
	scanf("%d",&y);
	new1=getnode(y);
	ptr=*t;
	if((*t)->data==x)
	{       new1->next=(*t)->next;
		new1->previous=(*t);
		(*t)->next=new1;
		*t=new1;
		(*h)->previous=new1;
		return;
	}
	while(ptr->previous!=*t)
	{       if(ptr->previous->data==x)
		{	new1->previous=ptr->previous;
			new1->next=ptr;
			ptr->previous->next=new1;
			ptr->previous=new1;
			return;
		}
		ptr=ptr->previous;
	}
	printf("%d does not exists",x);
}

/*6*/
void delete1(struct node **h,struct node **t)
{       struct node *ptr,*ptr1,*ptr2;
	int x;
	printf("\n\tDeleting Element AnyWhere in the List:-");
	printf("\nEnter Value to delete - ");
	scanf("%d",&x);
	if(*h==*t && (*h)->data==x)
	{	free(*h);
		*h=*t=NULL;
		return;
	}
	if((*h)->data==x)
	{	ptr=*h;
		(*h)->next->previous=(*h)->previous;
		(*h)=(*h)->next;
		(*t)->next=*h;
		free(ptr);
		return;
	}
	if((*t)->data==x)
	{	ptr=*t;
		(*t)->previous->next=(*t)->next;
		(*t)=(*t)->previous;
		(*h)->previous=*t;
		free(ptr);
		return;
	}
	ptr1=ptr2=*h;
	while(ptr1->next!=*h && ptr1->data!=x)
	{	ptr2=ptr1;
		ptr1=ptr1->next;
	}
	if(ptr1->data==x)
	{	ptr2->next=ptr1->next;
		ptr1->next->previous=ptr2;
		free(ptr1);
		return;
	}
	printf("\n%d not found in list",x);
	getch();
}

/*7*/
void reverse(struct node **h,struct node **t)
{       struct node *ptr1,*ptr2,*ptr3;
	printf("\n\tReversing List");
	/*ptr1=*h;
	ptr2=(*h)->next;
	while(ptr1->next!=NULL)
	{       ptr3=ptr2->next;
		ptr2->next=ptr1;
		ptr1=ptr2;
		ptr2=ptr3;
	}
	(*h)->next=NULL;
	(*h)=ptr3;*/
	ptr3=(*h);
	(*t)->next=NULL;
	ptr1=NULL;
	while(ptr3!=NULL)
	{       ptr2=ptr1;
		ptr1=ptr3;
		ptr3=ptr3->next;
		ptr1->next=ptr2;
	}
	(*h)=ptr1;
	(*h)->previous=NULL;
	ptr1=(*h);
	while(ptr1->next!=NULL)
	{	ptr1->next->previous=ptr1;
		ptr1=ptr1->next;
	}
	(*t)=ptr1;
	(*h)->previous=*t;
	(*t)->next=*h;
}

/*8*/
void sort(struct node **h,struct node **t)
{       struct node *ptr,*ptr1,*ptr2,*new1;
	printf("\n\tDescending order sorting");
	new1=getnode(32767);
	new1->next=(*h);
	(*h)=new1;
	(*t)->next=NULL;
	ptr=(*h);
	*h=NULL;
	while(ptr->next!=NULL)
	{       ptr2=ptr;
		ptr1=ptr->next;
		while(ptr1!=NULL)
		{	if(ptr2->data>=ptr1->data)
			{	ptr2=ptr1;
				ptr1=ptr1->next;
			}
			else
				ptr1=ptr1->next;
		}
		new1=getnode(ptr2->data);
		if(*h==NULL)
		{	*h=new1;
			*t=new1;
		}
		else
		{	ptr1=*h;
			while(ptr1->next!=NULL)
				ptr1=ptr1->next;
			new1->previous=ptr1;
			ptr1->next=new1;
			*t=new1;
		}
		ptr1=ptr;
		while(ptr1!=NULL)
		{	if(ptr1->next==ptr2)
			{       ptr1->next=ptr2->next;
				free(ptr2);
				break;
			}
			else
				ptr1=ptr1->next;
		}
	}
	(*h)->previous=*t;
	(*t)->next=*h;
}