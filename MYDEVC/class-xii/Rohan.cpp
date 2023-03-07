#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>

struct node
{	int info;
	node *next;
}*start,*newptr,*save,*ptr,*rear;
node *create_new_node(int);
void insert_beg(node *);
void display(node *);
void delnode();

void main()
{
	start=rear=NULL;
	int inf;
	char ch='y';
	while(ch=='y' || ch=='Y')
	{
		cout<<"\nEnter information for new node ";
		cin>>inf;
		cout<<"\nCreating new node press 'ENTER'";
		getche();
		newptr=create_new_node(inf);
		if(newptr!=NULL)
		{	cout<<"\nNew node created press 'ENTER'";
			getche();
		}
		else
		{	cout<<"\nCannot create new node \n ABORTING";
			getche();
			exit(1);
		}
		cout<<"\nNow inserting this node in begining of list "
		    <<"\nPress 'ENTER'";
		getche();
		insert_beg(newptr);
		cout<<"\nPress y to enter more node,n to exit ";
		cin>>ch;
	}

	do
	{
		cout<<"\nNow the list is : \n";
		display(start);
		cout<<"\nWant to delete first node :";
		cin>>ch;
		if(ch=='y' ||ch=='Y')
			delnode();
	}while(ch=='y' || ch=='Y');
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

node *create_new_node(int n)
{	ptr=new node;
	ptr->info=n;
	ptr->next=NULL;
	return ptr;
}

void insert_beg(node *np)
{	if(start == NULL)
	{	start=np;
		rear=np;
	}
	else
	{       rear->next=np;
		rear=np;
	}
}

void display(node *np)
{	while(np!=NULL)
	{	cout<<np->info<<"->";
		np=np->next;
	}
	cout<<"!!!!";
}

void delnode()
{	if(start==NULL)
		cout<<"\nUNDERFLOW";
	else
	{	ptr=start;
		start=start->next;
		delete ptr;
	}
}
