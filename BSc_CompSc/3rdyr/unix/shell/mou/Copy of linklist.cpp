#include<iostream>
using namespace std;

class Linked
{
	private:
		struct node
		{
			int data;
			struct node *link;
		};
		struct node *head;
	public:
		Linked()
		{
			Linked::head=NULL;
		}
		/*Linked(int k)
		{
			Linked::i=k;
		}*/
		void create();
		Linked operator+(int);
		Linked operator-(int);
		void show();
		Linked(const Linked &ob);
		~Linked()
		{

		}
};

void Linked::create()
{
	struct node *temp;
	struct node *ptr;
	int data;
	int c;
	try
	{
		if(Linked::head!=NULL)
			throw 1;
	}
	catch(int i)
	{
		cout<<"List already exist..";
		throw 1;
	}
	while(1)
	{
		cout<<"Do u want to create node?(Y/y):- ";
		cin>>c;
		if(c=='Y' || c=='y')
		{
			try
			{
				temp=new node;
			}
			catch(bad_alloc)
			{
				cout<<"Allocation faliour.";
			}
			ptr=Linked::head;
			cout<<"Enter data: "<<endl;
			cin>>data;
			temp->data=data;
			temp->link=NULL;
			while(ptr->link!=NULL)
				ptr=ptr->link;
			ptr->link=temp;
		}
	}
}


Linked Linked::operator+(int i)
{
	Linked v;
	v.head=NULL;
	struct node *temp;
	struct node *ptr;
	struct node *ptr1;
	/*try
	{
		if(Linked::head==NULL)
			throw 1;
	}
	catch(int i)
	{
		cout<<"List does not exist.";
//		return;
	}*/
	ptr=Linked::head;
	ptr1=v.head;
	while(ptr->link!=NULL)
	{
		try
		{
			temp=new node;
		}
		catch(bad_alloc)
		{
			cout<<"Allocation faliour.";
		}
		temp->data=ptr->data;
		ptr1->link=temp;
		temp->link=NULL;
		ptr=ptr->link;
	}
	try
	{
		temp=new node;
	}
	catch(bad_alloc)
	{
		cout<<"Allocation faliour.";
	}
	temp->data=i;
	temp->link=NULL;
	ptr1->link=temp;
	return temp;
}

Linked Linked::operator-(int i)
{
	Linked v;
	struct node *temp;
	struct node *ptr1;
	struct node *ptr2;
	struct node *ptr3;
	struct node *ptr4;
	v.head=NULL;
	try
	{
		if(Linked::head==NULL)
			throw 1;
	}
	catch(int i)
	{
		cout<<"List does not exist.";
		throw 1;
	}
	if(Linked::head->data==i)
	{
		Linked::head=ptr1;
		Linked::head=Linked::head->link;
		delete ptr1;
	}
	Linked::head=ptr1=ptr3;
	while(ptr1->data!=i && ptr1->link!=NULL)
	{
		ptr1=ptr2;
		ptr1=ptr1->link;
	}
	if(ptr1->data==i)
	{
		ptr2->link=ptr1->link;
		delete ptr1;
	}
	ptr4=v.head;
	while(ptr3->link!=NULL)
	{
		try
		{
			temp=new node;
		}
		catch(bad_alloc)
		{
			cout<<"Allocation faliour.";
		}
		temp->data=ptr3->data;
		ptr4->link=temp;
		temp->link=NULL;
		ptr3=ptr3->link;
	}
}


void Linked::show()
{
	struct node *ptr;
	try
	{
		if(Linked::head==NULL)
			throw 1;
	}
	catch(int i)
	{
		cout<<"List does not exist.";
		throw 1;
	}
	Linked::head=ptr;
	while(ptr->link!=NULL)
	{
		cout<<ptr->data;
		ptr=ptr->link;
	}
}

Linked::Linked(const Linked &ob)
{
	Linked::head=ob
}

int main()
{
	Linked node1;
	int data;
	node1.create();
	cout<<"Enter the data of the next node: ";
	cin>>data;
	node1=node1+data;
	node1.show();
	return 1;
}







