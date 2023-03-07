//Template Linklist Class

#include<iostream>
#include<new>
#include<exception>
//#define NULL 0

using namespace std;

//Template linklist class
template<class type>
class Linklist
{
//Begining of private scope
private:
	//Structure of each node of the list:
	//Data part-information;Address part-link
	struct node
	{
		type information;
		node *link;
	};
	//Head pointer of the list
	struct node *head;
//Begining of public scope
public:
	//Default destructor
	Linklist()
	{
		head=NULL;
	}
	//Declaring prototypes of the member functions
	void create();
	void append();
	void insertanywhere();
	void deletenode();
	void traverse();
	void reverse();
	void temp_type();
	//Destructor
	~Linklist()
	{
	}
};

//Function to create the link list
template<class type>
void Linklist<type>::create()
{
	//Declaring variables
	struct node *temp;
	type data;
	//Checking if list exists
	try
	{
		if(head != NULL)
			throw 1;
	}
	catch(int i)
	{
		cout<<"\nList exists";
		return;
	}
	//Creating the list
	cout<<"\nCreating list..";
	try
	{
		temp=new node;
	}
	catch(bad_alloc)
	{
		cout<<"\nAllocation Failure";
	}
	//Entering data into the node and then inserting node to the list
	cout<<"\nEnter data :- ";
	cin>>data;
	temp->information=data;
	temp->link=NULL;
	head=temp;
}

//Function to append the link list
template<class type>
void Linklist<type>::append()
{
	//Declaring variables
	struct node *temp;
	struct node *ptr;
	type data;
	//Checking if list exists or not
	try
	{
		if(head == NULL)
			throw 1;
	}
	catch(int i)
	{
		cout<<"\nList does not exit";
		return;
	}
	//If list exists then entering the data,
	//creating the node and inserting the node
	cout<<"\nAppending List..";
	cout<<"\nEnter value:- ";
	cin>>data;
	try
	{
		temp=new node;
	}
	catch(bad_alloc e)
	{
		cout<<"\nAllocation Failure";
	}
	temp->information=data;
	temp->link=NULL;
	ptr=head;
	while(ptr->link != NULL)
		ptr=ptr->link;
	ptr->link=temp;
}

//Function to insert a node any where in the link list
template<class type>
void Linklist<type>::insertanywhere()
{
	//Declaring variables
	struct node *temp;
	struct node *ptr;
	type data,data1;
	//Checking if list exists or not
	try
	{
		if(head == NULL)
			throw 1;
	}
	catch(int i)
	{
		cout<<"\nList does not exist";
		return;
	}
	//If list exists then entering the data after which 
	//to enter data and the data to be entered,creating the 
	//node and inserting the node at the specified position
	cout<<"\nInserting node..";
	cout<<"\nEnter the data to be inserted:- ";
	cin>>data;
	cout<<"\nEnter the data after which new node is to be inserted:- ";
	cin>>data1;
	try
	{	
		temp=new node;
	}
	catch(bad_alloc)
	{
		cout<<"\nAllocation Failed";
	}
	temp->information=data;
	temp->link=NULL;
	ptr=head;
	while(ptr->information != data1 && ptr->link != NULL)
		ptr=ptr->link;
	if(ptr->information == data1)
	{
		temp->link=ptr->link;
		ptr->link=temp;
	}
	if(ptr->link == NULL)
	{
		cout<<"\nNot presesnt so inserting at end";
		ptr->link=temp;

	}
}

//Function to delete a node from the link list
template<class type>
void Linklist<type>::deletenode()
{	
	//Declaring variables
	struct node *ptr1,*ptr2;
	type data;
	//Checking if list exists or not
	try
	{
		if(head == NULL)
			throw 1;
	}
	catch(int i)
	{
		cout<<"\nList does not exist";
		return;
	}
	//If list exists then entering the data to be deleted 
	//searching for that data,if present deleting else 
	//showing error
	cout<<"\nEnter data to delete:- ";
	cin>>data;
	if(head->information == data)
	{
		ptr1=head;
		head=head->link;
		delete ptr1;
		return;
	}
	ptr1=head;
	ptr2=head;
	while(ptr1->link != NULL && ptr1->information != data)
	{	
		ptr2=ptr1;
		ptr1=ptr1->link;
	}
	if(ptr1->information == data)
	{
		ptr2->link=ptr1->link;
		delete ptr1;
	}
	else
		cout<<"\nElement not present in the list:";
}

//Function to traverse the link list
template<class type>
void Linklist<type>::traverse()
{
	//Declaring variables
	struct node *ptr;
	//Checking if list exists or not
	try
	{
		if(head==NULL)
			throw 1;
	}
	catch(int i)
	{
		cout<<"\nList does not exist";
		return;
	}
	//If list exists then traversing the list 
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->information<<" ";
		ptr=ptr->link;
	}
}

//Function to reverse the link list
template<class type>
void Linklist<type>::reverse()
{
	//Declaring variables
	struct node *ptr1,*ptr2,*ptr3;
	//Checking if list exists or not
	try
	{
		if(head==NULL)
			throw 1;
	}
	catch(int i)
	{
		cout<<"\nList does not exist";
		return;
	}
	//If list exists then traversing the list
	cout<<"\nReversing list..";
	ptr3=head;
	ptr1=NULL;
	while(ptr3 != NULL)
	{
		ptr2=ptr1;
		ptr1=ptr3;
		ptr3=ptr3->link;
		ptr1->link=ptr2;
	}
	head=ptr1;
}

//Choice of the user
template<class type>
void Linklist<type>::temp_type()
{
	int ch;
	char c;
	//Menu for the user
	do
	{
		cout<<"\nMAIN MENU";
		cout<<"\n1.Create link list";
		cout<<"\n2.Append";
		cout<<"\n3.Insert any where";
		cout<<"\n4.Deletenode";
		cout<<"\n5.Traverse";
		cout<<"\n6.Reverse";
		cout<<"\n7.Exit";
		cout<<"\nEnter the choice:- ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				append();
				break;
			case 3:
				insertanywhere();
				break;
			case 4:
				deletenode();
				break;
			case 5:
				traverse();
				break;
			case 6:
				reverse();
				break;
			case 7:
				cout<<"\nExit program";
				return;
			default:
				cout<<"\nWrong choice";
				break;
		}
		cout<<"\nDo you want to continue?(Y/y):- ";
		cin>>c;
		if(c != 'y' && c != 'Y')
			break;
	}while(1);
}
//Main function
int main()
{
	//Declaring variables and objects of the class
	char ch;
	cout<<"\nSUB_MENU";
	cout<<"\n'i' for integer";
	cout<<"\n'f' for float";
	cout<<"\n'c' for character";
	cout<<"\nEnter your choice : ";
	cin>>ch;
	if(ch=='i')
	{
		Linklist<int> a;
		a.temp_type();
	}
	else if(ch=='f')
	{
		Linklist<float> b;
		b.temp_type();
	}
	else if(ch=='c')
	{
		Linklist<char> c;
		c.temp_type();
	}
	else
		cout<<"\nERROR in choice!\n";
	return 0;
}
