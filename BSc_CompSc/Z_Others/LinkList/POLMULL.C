//ss
//polynomial multiplication,using linklist,ok
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

struct node
{	int data;
	int exp;
	struct node *next;
};

struct node *new1,*ptr,*ptr1,*ptr2,*head1,*head2,*head3;

struct node* getnode(int x,int y)
{      	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=x;
	new1->exp=y;
	new1->next=NULL;
	return(new1);
}

void createlist();
void mul();
void display();
void sort();

void main()
{       int c,i;
	clrscr();
	do
	{       clrscr();
		printf("\t\tM E N U");
		printf("\n\t1.Create Link List of Polynomials");
		printf("\n\t2.Multiply the Polynomials");
		printf("\n\t3.Display Polynomials");
		printf("\n\t4.Exit");
		printf("\n\n\tEnter Choice : - ");
		scanf("%d",&c);
		switch(c)
		{	case 1:
				createlist();
				head3=NULL;
				break;
			case 2:
				if(head1==NULL || head2==NULL)
					break;
				else
				{	mul();
					getch();
				}
				break;
			case 3:
				if(head1==NULL || head2==NULL)// || head3==NULL)
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
{	int x,y;
	printf("\n\tCreating List of 1st Polynomial:-\n");
	head1=NULL;
	printf("Enter coefficient (-999 to stop) - ");
	scanf("%d",&x);
	printf("Enter exponent (-999 to stop) - ");
	scanf("%d",&y);
	while(x!=-999 || y!=-999)
	{	new1=getnode(x,y);
		if(head1==NULL)
			head1=new1;
		else
		{	ptr=head1;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new1;
		}
		printf("Enter coefficient (-999 to stop) - ");
		scanf("%d",&x);
		printf("Enter exponent (-999 to stop) - ");
		scanf("%d",&y);
	}
	printf("\n\tCreating List of 2nd Polynomial:-\n");
	head2=NULL;
	printf("Enter coefficient (-999 to stop) - ");
	scanf("%d",&x);
	printf("Enter exponent (-999 to stop) - ");
	scanf("%d",&y);
	while(x!=-999 || y!=-999)
	{	new1=getnode(x,y);
		if(head2==NULL)
			head2=new1;
		else
		{	ptr=head2;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new1;
		}
		printf("Enter coefficient (-999 to stop) - ");
		scanf("%d",&x);
		printf("Enter exponent (-999 to stop) - ");
		scanf("%d",&y);
	}
}

void sort()
{       int temp;
	ptr1=head3;
	while(ptr1!=NULL)
	{       ptr2=ptr1->next;
		while(ptr2!=NULL)
		{	if(ptr1->exp>=ptr2->exp)
			{	temp=ptr2->data;
				ptr2->data=ptr1->data;
				ptr1->data=temp;
				temp=ptr2->exp;
				ptr2->exp=ptr1->exp;
				ptr1->exp=temp;
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
	ptr1=head3;
	while(ptr1!=NULL)
	{       ptr2=ptr1->next;
		while(ptr2!=NULL)
		{	if(ptr1->exp==ptr2->exp)
			{	ptr1->data=ptr1->data+ptr2->data;
				ptr=ptr2;
				ptr1->next=ptr2->next;
				free(ptr);
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
}

void mul()
{       int z,y;
	ptr1=head1;
	while(ptr1!=NULL)
	{	ptr2=head2;
		while(ptr2!=NULL)
		{      	z=ptr1->data*ptr2->data;
			y=ptr1->exp+ptr2->exp;
			new1=getnode(z,y);
			if(head3==NULL)
				head3=new1;
			else
			{	ptr=head3;
				while(ptr->next!=NULL)
					ptr=ptr->next;
				ptr->next=new1;
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
	sort();
}

void display()
{       printf("\n\tDisplaying 1st Polynomial:-\n");
	ptr=head1;
	while(ptr!=NULL)
	{	if(ptr==head1 || ptr->data<0)
			printf("%dx^%d",ptr->data,ptr->exp);
		else if(ptr->data>=0)
			printf("+%dx^%d",ptr->data,ptr->exp);
		ptr=ptr->next;
	}
	printf("\n\tDisplaying 2nd Polynomial:-\n");
	ptr=head2;
	while(ptr!=NULL)
	{	if(ptr==head2 || ptr->data<0)
			printf("%dx^%d",ptr->data,ptr->exp);
		else if(ptr->data>=0)
			printf("+%dx^%d",ptr->data,ptr->exp);
		ptr=ptr->next;
	}
	if(head3!=NULL)
	{	printf("\n\tDisplaying Multiplied Polynomial:-\n");
		ptr=head3;
		while(ptr!=NULL)
		{	if(ptr==head3 || ptr->data<0)
				printf("%dx^%d",ptr->data,ptr->exp);
			else if(ptr->data>=0)
				printf("+%dx^%d",ptr->data,ptr->exp);
			ptr=ptr->next;
		}
	}
}