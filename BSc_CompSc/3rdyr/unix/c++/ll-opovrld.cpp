//node = node + 2
//node = node - 3

#include<iostream>
#include<exception>
#include<new>

using namespace std;

class nodeovrld
{
private:
	struct node
	{
		int data;
		node *next;
	};
	node *head;
public:
	nodeovrld();
	nodeovrld(const nodeovrld&);
	void create();
	void display();
	nodeovrld operator+(int);
	nodeovrld operator-(int);
	~nodeovrld();
};

nodeovrld::nodeovrld()
{
	nodeovrld::head=NULL;
}

nodeovrld::nodeovrld(const nodeovrld &ob)
{
	nodeovrld::head=ob.head;
}

void nodeovrld::create()
{
	int d;
	char y;
	node *temp,*ptr;
	while(true)
	{
		cout<<"Enter value to insert:- ";
		cin>>d;
		try
		{
			temp=new node;
		}
		catch(bad_alloc e)
		{
			cout<<"Allocation Failure\n";
				return;
		}
		temp->data=d;
		temp->next=NULL;
		if(nodeovrld::head == NULL)
			nodeovrld::head=temp;
		else
		{
			ptr=nodeovrld::head;
			while(ptr->next != NULL)
				ptr=ptr->next;
			ptr->next=temp;
		}
		cout<<"\nDo you want to continue?(y/Y)";
		cin>>y;
		if(y != 'y' && y != 'Y')
		       break;
	}
}	

void nodeovrld::display()
{
	node *ptr;
	ptr=nodeovrld::head;
	while(ptr != NULL)
	{
		cout<<ptr->data<<"\t";
		ptr=ptr->next;
	}
	cout<<"\n";
}

nodeovrld nodeovrld::operator+(int d)
{
	nodeovrld temp;
	node *ptr1,*ptr2,*ptr;
	temp.head=NULL;
	ptr1=nodeovrld::head;
	while(ptr1 != NULL)
	{
		try
		{	
			ptr=new node;
		}
		catch(bad_alloc e)
		{
			cout<<"Allocation Failure\n";
			throw 1;
		}
		ptr->data=ptr1->data;
		ptr->next=NULL;
		if(temp.head == NULL)
			temp.head=ptr;
		else
		{
			ptr2=temp.head;
			while(ptr2->next != NULL)
				ptr2=ptr2->next;
			ptr2->next=ptr;
		}
		ptr1=ptr1->next;
	}
	try
	{	
		ptr=new node;
	}
	catch(bad_alloc e)
	{
		cout<<"Allocation Failure\n";
		throw 1;
	}
	ptr->data=d;
	ptr->next=NULL;
	if(temp.head == NULL)
		temp.head=ptr;
	else
	{
		ptr2=temp.head;
		while(ptr2->next != NULL)
			ptr2=ptr2->next;
		ptr2->next=ptr;
	}
	return temp;
}

nodeovrld nodeovrld::operator-(int d)
{
	nodeovrld temp;
	node *ptr1,*ptr2,*ptr;
	ptr1=nodeovrld::head;
	temp.head=NULL;
	while(ptr1 != NULL)
	{
		try
		{	
			ptr=new node;
		}
		catch(bad_alloc e)
		{
			cout<<"Allocation Failure\n";
			throw 1;
		}
		if(ptr1->data != d)
		{
			ptr->data=ptr1->data;
			ptr->next=NULL;
			if(temp.head == NULL)
				temp.head=ptr;
			else
			{
				ptr2=temp.head;
				while(ptr2->next != NULL)
					ptr2=ptr2->next;
				ptr2->next=ptr;
			}
		}
		ptr1=ptr1->next;
	}
	return temp;
}

nodeovrld::~nodeovrld()
{
	node *ptr;
	while(nodeovrld::head != NULL)
	{
		ptr=nodeovrld::head;
		delete ptr;
		nodeovrld::head=nodeovrld::head->next;
	}
	delete head;
}

int main()
{
	nodeovrld ob;
	ob.create();
	ob.display();
	nodeovrld ob1=ob+2;
	cout<<"\nMain\n";
	ob1.display();
	nodeovrld ob2=ob-3;
	ob2.display();
	return 0;
}
