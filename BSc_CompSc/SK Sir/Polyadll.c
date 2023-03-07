
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0

//Node structure
struct node
{	int data;//data part
	int exp;//exponential part
	struct node *next;//next node address part
};

//Structure type variables declared globally
struct node *new1,*ptr,*ptr1,*ptr2,*head1,*head2,*head3,*head4,*head5;

//Function to create a node with x as its data and y as its exponent
struct node* getnode(int x,int y)
{      	new1=(struct node *)malloc(sizeof(struct node));
	new1->data=x;
	new1->exp=y;
	new1->next=NULL;
	return(new1);
}

//Functions declared globally
void sort();
void createlist();
void add();
void sub();
void display();

void main()
{       //Variable declaration
	int c;
	clrscr();
	do
	{       clrscr();
		head1=head2=head3=NULL;
	//Calling the functions one at a time to perform the jobs
		createlist();
		sort();
		add();
		sub();
		display();
		printf("\nDo you want to continue?(Yes=1,No=0)");
		scanf("%d",&c);

	}while(c==1);
}

//Function to create the 2 polynomial lists
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

//Function to add the 2 polynomials
void add()
{       int z,f=0;
	ptr1=head1;
	while(ptr1!=NULL)
	{       ptr2=head2;
		while(ptr2!=NULL)
		{	if(ptr1->exp==ptr2->exp)
			{	z=ptr1->data+ptr2->data;
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

//Function to subtract the second polynomial from the first polynomial
void sub()
{       int z,f=0;
	ptr1=head1;
	while(ptr1!=NULL)
	{       ptr2=head2;
		while(ptr2!=NULL)
		{	if(ptr1->exp==ptr2->exp)
			{	z=ptr1->data-ptr2->data;
				new1=getnode(z,ptr1->exp);
				if(head5==NULL)
					head5=new1;
				else
				{	ptr=head5;
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
			if(head5==NULL)
				head5=new1;
			else
			{	ptr=head5;
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
	{       ptr2=head5;
		while(ptr2!=NULL)
		{	if(ptr1->exp==ptr2->exp)
			{	f=1;
				break;
			}
			ptr2=ptr2->next;
		}
		if(f==0)
		{	new1=getnode((-1*ptr1->data),ptr1->exp);
			ptr=head5;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new1;
		}
		f=0;
		ptr1=ptr1->next;
	}
}

//Function to display all the polynomials
void display()
{       //Displaying list 1
	printf("\n\tDisplaying 1st Polynomial:-");
	ptr=head1;
	while(ptr!=NULL)
	{       if(ptr==head1 || ptr->data<0)
			printf("%dx^%d",ptr->data,ptr->exp);
		else if(ptr->data>0)
			printf("+%dx^%d",ptr->data,ptr->exp);
		ptr=ptr->next;
	}
	//Displaying list 2
	printf("\n\tDisplaying 2nd Polynomial:-");
	ptr=head2;
	while(ptr!=NULL)
	{	if(ptr==head2 || ptr->data<0)
			printf("%dx^%d",ptr->data,ptr->exp);
		else if(ptr->data>0)
			printf("+%dx^%d",ptr->data,ptr->exp);
		ptr=ptr->next;
	}
	//Displaying added list
	if(head3!=NULL)
	{	printf("\n\tDisplaying Added Polynomial:-");
		ptr=head3;
		while(ptr!=NULL)
		{	if(ptr==head3 || ptr->data<0)
				printf("%dx^%d",ptr->data,ptr->exp);
			else if(ptr->data>0)
				printf("+%dx^%d",ptr->data,ptr->exp);
			ptr=ptr->next;
		}
	}
	//Displaying subtracted list
	if(head5!=NULL)
	{	printf("\n\tDisplaying Subtracted Polynomial:-");
		ptr=head5;
		while(ptr!=NULL)
		{	if(ptr==head5 || ptr->data<0)
				printf("%dx^%d",ptr->data,ptr->exp);
			else if(ptr->data>0)
				printf("+%dx^%d",ptr->data,ptr->exp);
			ptr=ptr->next;
		}
	}
}

//Function to sort the 2 given polynomials
void sort()
{       //Sorting list 1
	new1=getnode(0,32767);
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
	//Sorting list 2
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


