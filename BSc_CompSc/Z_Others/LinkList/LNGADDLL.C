//Long number addition,using linklist
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

struct node
{	int data;
	struct node *next;
};

struct node *new1,*ptr,*ptr1,*ptr2,*ptr3,*head1,*head2,*head3;

struct node* getnode(int x)
{      	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=x;
	new1->next=NULL;
	return(new1);
}

void main()
{       void createlist();
	void add();
	void reverse();
	void display();
	clrscr();
	head1=NULL;
	head2=NULL;
	head3=NULL;
	createlist();
	add();
	reverse();
	display();
	getch();
}

void createlist()
{	char num1[20],num2[20];
	int x,y;
	printf("Enter 1st number :- ");
	gets(num1);
	y=strlen(num1)-1;
	do
	{       x=num1[y]-48;
		y--;
		new1=getnode(x);
		if(head1==NULL)
			head1=new1;
		else
		{	ptr=head1;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new1;
		}
	}while(y!=-1);
	printf("Enter 2nd number :- ");
	gets(num2);
	y=strlen(num2)-1;
	do
	{	x=num2[y]-48;
		y--;
		new1=getnode(x);
		if(head2==NULL)
			head2=new1;
		else
		{	ptr=head2;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new1;
		}
	}while(y!=-1);
}

void add()
{       int z,c=0;
	ptr1=head1;
	ptr2=head2;
	while(ptr1!=NULL && ptr2!=NULL)
	{	z=ptr1->data+ptr2->data+c;
		if(z>=10)
		{	z=z-10;
			c=1;
		}
		else
			c=0;
		new1=getnode(z);
		if(head3==NULL)
			head3=new1;
		else
		{	new1->next=head3;
			head3=new1;
		}
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}
	if(c==1)
	{	new1=getnode(c);
		new1->next=head3;
		head3=new1;
	}
}

void reverse()
{       ptr1=head1;
	ptr2=head1->next;
	while(ptr1->next!=NULL)
	{       ptr3=ptr2->next;
		ptr2->next=ptr1;
		ptr1=ptr2;
		ptr2=ptr3;
	}
	head1->next=NULL;
	head1=ptr3;
	ptr1=head2;
	ptr2=head2->next;
	while(ptr1->next!=NULL)
	{       ptr3=ptr2->next;
		ptr2->next=ptr1;
		ptr1=ptr2;
		ptr2=ptr3;
	}
	head2->next=NULL;
	head2=ptr3;
}

void display()
{       printf("\n\tDisplaying 1st Number:-\n");
	ptr=head1;
	while(ptr!=NULL)
	{	printf("%d",ptr->data);
		ptr=ptr->next;
	}
	printf("\n\tDisplaying 2nd Number:-\n");
	ptr=head2;
	while(ptr!=NULL)
	{	printf("%d",ptr->data);
		ptr=ptr->next;
	}
	printf("\n\tDisplaying Result:-\n");
	ptr=head3;
	while(ptr!=NULL)
	{	printf("%d",ptr->data);
		ptr=ptr->next;
	}
}