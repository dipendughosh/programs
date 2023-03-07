//single circular link list all(item)(not passing head)OK
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

typedef struct node
{	int data;
	struct node *next;
}node;

node *head;

node *new1,*ptr,*ptr1,*ptr2;

node* getnode(int x)
{      	new1=(node *)malloc(sizeof(node));
	new1->data=x;
	return(new1);
}

void main()
{       int c,i;
	void createlist();
	void insertatbeg();
	void insertatend();
	void insertatmid();
	/*void deleteatbeg();
	void deleteatend();*/
	void delete1();
	void display();
	clrscr();
	do
	{       clrscr();
		printf("\t\tM E N U");
		printf("\n\t1.Create Link List");
		printf("\n\t2.Insert at Begining");
		printf("\n\t3.Insert at End");
		printf("\n\t4.Insert at Middle");
		/*printf("\n\t5.Delete at Begining");
		printf("\n\t6.Delete at End");*/
		printf("\n\t5.Delete Element");
		printf("\n\t6.Display list");
		printf("\n\t7.Exit");
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
					insertatbeg();
				break;
			case 3:
				if(head==NULL)
					break;
				else
					insertatend();
				break;
			case 4:
				if(head==NULL)
					break;
				else
					insertatmid();
				break;
			/*case 5:
				if(head==NULL)
					break;
				else
					deleteatbeg();
				break;
			case 6:
				if(head==NULL)
					break;
				else
					deleteatend();
				break;*/
			case 5:
				if(head==NULL)
					break;
				else
					delete1();
				break;
			case 6:
				if(head==NULL)
					break;
				else
				{	display();
					getch();
				}
				break;
			case 7:
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
	printf("Enter value (-999 to stop) - ");
	scanf("%d",&x);
	while(x!=-999)
	{	new1=getnode(x);
		if(head==NULL)
		{	head=new1;
			new1->next=head;
		}
		else
		{	ptr=head;
			while(ptr->next!=head)
				ptr=ptr->next;
			ptr->next=new1;
			new1->next=head;
		}
		printf("Enter value (-999 to stop) - ");
		scanf("%d",&x);
	}
}

void insertatbeg()
{	int x;
	printf("\n\tInserting Element at Begining:-");
	printf("\nEnter value - ");
	scanf("%d",&x);
	new1=getnode(x);
	ptr=head;
	while(ptr->next!=head)
		ptr=ptr->next;
	new1->next=head;
	head=new1;
	ptr->next=head;
}

void insertatend()
{	int x;
	printf("\n\tInserting Element at End:-");
	printf("\nEnter value - ");
	scanf("%d",&x);
	new1=getnode(x);
	ptr=head;
	while(ptr->next!=head)
		ptr=ptr->next;
	ptr->next=new1;
	new1->next=head;
}

void insertatmid()
{	int x,pos,y=1;
	printf("\n\tInserting Element at Middle:-");
	printf("\nEnter position - ");
	scanf("%d",&pos);
	ptr=head;
	if(pos==1)
		insertatbeg();
	else
	{	ptr=head;
		while(ptr->next!=head && y<=pos-1)
		{	ptr=ptr->next;
			y++;
		}
		if(ptr->next==head)
			insertatend();
		else
		{	printf("\nEnter value - ");
			scanf("%d",&x);
			new1=getnode(x);
			new1->next=ptr->next;
			ptr->next=new1;
		}
	}
}

/*void deleteatbeg()
{       printf("\n\tDeleting Element at Begining:-");
	ptr=head;
	head=head->next;
	free(ptr);
	getch();
}

void deleteatend()
{       printf("\n\tDeleting Element at End:-");
	ptr1=head;
	ptr2=head;
	while(ptr2->next!=NULL)
	{	ptr1=ptr2;
		ptr2=ptr2->next;
	}
	ptr1->next=NULL;
	free(ptr2);
	getch();
} */

void delete1()
{	int item;
	printf("\n\tDeleting Element at Given Position:-");
	printf("\nEnter item - ");
	scanf("%d",&item);
	ptr1=ptr2=head;
	while(ptr1->next!=head && ptr1->data!=item)
	{	ptr2=ptr1;
		ptr1=ptr1->next;
	}
	if(ptr1->data==item)
	{	if(ptr1==ptr2 && ptr1->next==head)
		{	head=NULL;
			free(ptr1);
		}
		else if(ptr1==ptr2 && ptr1->next!=head)
		{	ptr2=head;
			while(ptr2->next!=head)
				ptr2=ptr2->next;
			head=head->next;
			ptr2->next=head;
			free(ptr1);
		}
		else
		{	ptr2->next=ptr1->next;
			free(ptr1);
		}
	}
	else
		printf("\nItem not found");
	getch();
}

void display()
{       printf("\n\tDisplaying List Items:-\n");
	ptr=head;
	while(ptr->next!=head)
	{	printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("%d",ptr->data);
}