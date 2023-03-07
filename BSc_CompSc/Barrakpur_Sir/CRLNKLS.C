//single circular link list all,ok
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
{       struct node *tail=NULL;
	int c,i;
/*1*/	void create(struct node **);
/*2*/	void append(struct node **);
/*3*/	void insertbefr(struct node *);
/*4*/	void insertaftr(struct node **);
/*5*/	void delete1(struct node **);
/*6*/	void reverse(struct node **);
/*7*/	void sort(struct node **);
/*8*/	void display(struct node *);
	clrscr();
	do
	{       clrscr();
		printf("\t\tM E N U");
		printf("\n\t1.Create List");
		printf("\n\t2.Append List");
		printf("\n\t3.Insert Before");
		printf("\n\t4.Insert After");
		printf("\n\t5.Delete");
		printf("\n\t6.Sort");
		printf("\n\t7.Reverse");
		printf("\n\t8.Display list");
		printf("\n\t9.Exit");
		printf("\n\n\tEnter Choice : - ");
		scanf("%d",&c);
		switch(c)
		{	case 1:
				if(tail!=NULL)
					printf("List exists");
				else
					create(&tail);
				break;
			case 2:
				if(tail==NULL)
					break;
				else
					append(&tail);
				break;
			case 3:
				if(tail==NULL)
					break;
				else
					insertbefr(tail);
				break;
			case 4:
				if(tail==NULL)
					break;
				else
					insertaftr(&tail);
				break;
			case 5:
				if(tail==NULL)
					break;
				else
					delete1(&tail);
				break;
			case 6:
				if(tail==NULL)
					break;
				else
					sort(&tail);
				break;
			case 7:
				if(tail==NULL)
					break;
				else
					reverse(&tail);
				break;
			case 8:
				if(tail==NULL)
					break;
				else
				{	display(tail);
					getch();
				}
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
	}while(1);
}

/*1*/
void create(struct node **t)
{       int x;
	printf("\n\tCreating List:-\n");
	printf("Enter value - ");
	scanf("%d",&x);
	(*t)=getnode(x);
	(*t)->next=(*t);
}

/*2*/
void append(struct node **t)
{       struct node *new1;
	int x;
	printf("Enter value - ");
	scanf("%d",&x);
	new1=getnode(x);
	new1->next=(*t)->next;
	(*t)->next=new1;
	(*t)=new1;
}

/*3*/
void insertbefr(struct node *t)
{	struct node *new1,*ptr;
	int  item,x;
	printf("\nEnter value of the node:-");
	scanf("%d",&item);
	printf("\nEnter value of the node before which to add the given node:-");
	scanf("%d",&x);
	new1=getnode(item);
	ptr=t;
	if(ptr->data==x)
	{	while(ptr->next!=t)
			ptr=ptr->next;
		new1->next=ptr->next;
		ptr->next=new1;
		return;
	}
	while(ptr->next!=t && ptr->next->data!=x)
		ptr=ptr->next;
	if(ptr->next->data==x)
	{	new1->next=ptr->next;
		ptr->next=new1;
		return;
	}
	printf("\n%d is not present in the list",x);
	getch();
}

/*4*/
void insertaftr(struct node **t)
{	struct node *new1,*ptr;
	int item,x;
	printf("\nEnter value of the node:-");
	scanf("%d",&item);
	printf("\nEnter value of the node after which to add the given node:-");
	scanf("%d",&x);
	new1=getnode(item);
	ptr=(*t);
	if(ptr->data==x)
	{	new1->next=ptr->next;
		ptr->next=new1;
		(*t)=new1;
		return;
	}
	while(ptr->next!=(*t) && ptr->data!=x)
		ptr=ptr->next;
	if(ptr->data==x)
	{	new1->next=ptr->next;
		ptr->next=new1;
		return;
	}
	printf("\n%d is not present in the list",x);
	getch();
}

/*5*/
void delete1(struct node **t)
{       struct node *ptr1,*ptr2;
	int item;
	printf("\n\tDeleting a given Element  :-");
	printf("\nEnter item - ");
	scanf("%d",&item);
	ptr1=(*t);
	if(ptr1->data==item)
	{	ptr2=ptr1;
		ptr1=ptr1->next;
		while(ptr1->next!=ptr2)
			ptr1=ptr1->next;
		ptr1->next=ptr2->next;
		(*t)=ptr1;
		free(ptr2);
		getch();
		return;
	}
	while(ptr1->next->data!=item && ptr1->next!=(*t))
		ptr1=ptr1->next;
	if(ptr1->next->data==item)
	{	ptr2=ptr1->next;
		ptr1->next=ptr1->next->next;
		free(ptr2);
		getch();
		return;
	}
	printf("\nItem does not exists in the list");
	getch();
}

/*6*/
void reverse(struct node **t)
{	struct node *ptr1,*ptr2,*ptr3,*ptr4;
	ptr1=ptr4=(*t)->next;
	ptr3=(*t);
	while(ptr1!=(*t))
	{	ptr2=ptr1;
		ptr1=ptr1->next;
		ptr2->next=ptr3;
		ptr3=ptr2;
	}
	ptr1->next=ptr3;
	(*t)=ptr4;
}

/*7*/
void sort(struct node **t)
{	struct node *new1,*ptr,*ptr1,*ptr2,*tail1;
	new1=getnode(32767);
	new1->next=(*t)->next;
	(*t)->next=new1;
	tail1=NULL;
	ptr=(*t)->next;
	while(ptr->next!=(*t))
	{       ptr2=ptr;
		ptr1=ptr->next;
		while(ptr1!=(*t))
		{	if(ptr2->data>=ptr1->data)
			{	ptr2=ptr1;
				ptr1=ptr1->next;
			}
			else
				ptr1=ptr1->next;
		}
		new1=getnode(ptr2->data);
		new1->next=NULL;
		if(tail1==NULL)
			tail1=new1;
		else
		{	ptr1=tail1;
			while(ptr1->next!=NULL)
				ptr1=ptr1->next;
			ptr1->next=new1;
		}
		ptr1=ptr;
		while(ptr1!=(*t))
		{	if(ptr1->next==ptr2)
			{       ptr1->next=ptr2->next;
				free(ptr2);
				break;
			}
			else
				ptr1=ptr1->next;
		}
	}
	if(tail1->data>=(*t)->data)
	{	(*t)->next=tail1;
		tail1=(*t);
	}
	else
	{	ptr=tail1;
		while(ptr->next!=NULL)
		{	if((*t)->data>=ptr->data)
				ptr=ptr->next;
			else
				break;
		}
		(*t)->next=ptr->next;
		ptr->next=(*t);
	}
	ptr=tail1;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=tail1;
	(*t)=ptr;
}

/*8*/
void display(struct node *t)
{       struct node *ptr;
	printf("\n\tDisplaying List Items:-\n");
	ptr=t->next;
	while(ptr!=t)
	{	printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("%d",ptr->data);
}

