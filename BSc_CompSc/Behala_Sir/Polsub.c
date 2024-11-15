//polynomial subtraction,using linklist,ok
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

struct node
{	int data;
	int exp;
	struct node *next;
};

struct node *new1,*ptr,*ptr1,*ptr2,*head1,*head2,*head3,*head4;

struct node* getnode(int x,int y)
{      	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=x;
	new1->exp=y;
	new1->next=NULL;
	return(new1);
}

void sort();


void main()
{       int c,i,x=1;
	void createlist();
	void sub();
	void display();
	clrscr();
	do
	{       clrscr();
		printf("\t\tM E N U");
		printf("\n\t1.Create Link List of Polynomials");
		printf("\n\t2.Subtract the Polynomials");
		printf("\n\t3.Display Polynomials");
		printf("\n\t4.Exit");
		printf("\n\n\tEnter Choice : - ");
		scanf("%d",&c);
		switch(c)
		{	case 1:
				if(head1!=NULL && head2!=NULL)
				{	printf("Lists exists,Do you want to create new lists(y=1,n=0)");
					scanf("%d",&x);
				}
				if(x==1)
				{	head1=head2=head3=NULL;
					createlist();
				}
				break;
			case 2:
				if(head1==NULL || head2==NULL)
					break;
				else
				{	sub();
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

void sub()
{       int z,f=0;
	sort();
	ptr1=head1;
	while(ptr1!=NULL)
	{       ptr2=head2;
		while(ptr2!=NULL)
		{	if(ptr1->exp==ptr2->exp)
			{	z=ptr1->data-ptr2->data;
				new1=getnode(z,ptr1->exp);
				if(head3==NULL)
					head3=new1;
				else
				{	ptr=head3;
					while(ptr->next!=NULL)
						ptr=ptr->next;
					ptr->next=new1;
				}
				f=1;
				break;
			}
			ptr2=ptr2->next;
		}
		if(f==0)
		{	new1=getnode(ptr1->data,ptr1->exp);
			if(head3==NULL)
				head3=new1;
			else
			{	ptr=head3;
				while(ptr->next!=NULL)
					ptr=ptr->next;
				ptr->next=new1;
			}
		}
		f=0;
		ptr1=ptr1->next;
	}
	f=0;
	ptr1=head2;
	while(ptr1!=NULL)
	{       ptr2=head3;
		while(ptr2!=NULL)
		{	if(ptr1->exp==ptr2->exp)
			{	f=1;
				break;
			}
			ptr2=ptr2->next;
		}
		if(f==0)
		{	new1=getnode(ptr1->data,ptr1->exp);
			ptr=head3;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new1;
		}
		f=0;
		ptr1=ptr1->next;
	}
}


void display()
{       printf("\n\tDisplaying 1st Polynomial:-\n");
	ptr=head1;
	while(ptr!=NULL)
	{       if(ptr==head1 || ptr->data<0)
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
	{	printf("\n\tDisplaying Added Polynomial:-\n");
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

void sort()
{	new1=getnode(0,32767);
	new1->next=head1;
	head1=new1;
	head4=NULL;
	ptr=head1;
	while(ptr->next!=NULL)
	{       ptr2=ptr;
		ptr1=ptr->next;
		while(ptr1!=NULL)
		{	if(ptr2->exp>ptr1->exp)
			{	ptr2=ptr1;
				ptr1=ptr1->next;
			}
			else
				ptr1=ptr1->next;
		}
		new1=getnode(ptr2->data,ptr2->exp);
		if(head4==NULL)
			head4=new1;
		else
		{	ptr1=head4;
			while(ptr1->next!=NULL)
				ptr1=ptr1->next;
			ptr1->next=new1;
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
	head1=head4;
	new1=getnode(0,32767);
	new1->next=head2;
	head2=new1;
	head4=NULL;
	ptr=head2;
	while(ptr->next!=NULL)
	{       ptr2=ptr;
		ptr1=ptr->next;
		while(ptr1!=NULL)
		{	if(ptr2->exp>ptr1->exp)
			{	ptr2=ptr1;
				ptr1=ptr1->next;
			}
			else
				ptr1=ptr1->next;
		}
		new1=getnode(ptr2->data,ptr2->exp);
		if(head4==NULL)
			head4=new1;
		else
		{	ptr1=head4;
			while(ptr1->next!=NULL)
				ptr1=ptr1->next;
			ptr1->next=new1;
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
	head2=head4;
}
