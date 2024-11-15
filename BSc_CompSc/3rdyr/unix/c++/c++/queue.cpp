//Overflow and under flow in queue

#include<iostream>
//#define NULL 0

using namespace std;

//Template Base class
template<class x>
class Queue
{
//Begining of public scope     	
public:
//Node structure of the nodes:-Data part-data,address part-*next	
	struct node
	{
		x data;
		node *next;
	};
	//Pointers of the Queue front and rear
	struct node *front,*rear;
	//Constructor to initialze Queue pointers
	Queue()
	{
		Queue::front=NULL;
		Queue::rear=NULL;
	}
	//Prototypes of Virtual functions for the basic operations of Queue
	virtual void create();
	virtual void Insert();
	virtual void Delete();
	void Display();
	//Destructor
	~Queue()
	{
	}
};

//Base class virtual function to create the queue
template<class x>
void Queue<x>::create()
{
	x n;
	struct node *temp;
	if(Queue::front != NULL && Queue::rear != NULL)
	{
		cout<<"Queue already exists so cannot create a new Queue";
		return;
	}
	cout<<"Enter 1st data to - ";
	cin>>n;
	temp=new node;
	temp->data=n;
	temp->next=NULL;
	Queue::front=temp;
	Queue::rear=temp;
}

//Base class virtual function to insert node into the queue
template<class x>
void Queue<x>::Insert()
{
	x n;
	struct node *temp;
	cout<<"Enter data to Insert - ";
	cin>>n;
	temp=new node;
	temp->data=n;
	temp->next=NULL;
	Queue::rear->next=temp;
	Queue::rear=temp;
}

//Base class virtual function to delete node from the queue
template<class x>
void Queue<x>::Delete()
{
	x n;
	struct node *temp;
	temp=Queue::front;
	Queue::front=Queue::front->next;
	n=temp->data;
	delete temp;
	cout<<"Deleted data - "<<n;
	if(Queue::front == NULL)
	{
		Queue::front=NULL;
		Queue::rear=NULL;
	}
}

//Function to display the elements of the queue
template<class x>
void Queue<x>::Display()
{
	struct node *f,*r;
	if(Queue::front == NULL && Queue::rear == NULL)
	{
		cout<<"Queue empty nothing to display";
		return;
	}
	f=Queue::front;
	r=Queue::rear;
	while(f != NULL)
	{
		cout<<f->data<<"\t";
		f=f->next;
	}
}

//Inherited MyQueue class to handle the exceptions
template<class x>
class MyQueue:public Queue<x>
{	
//Begining of public scope     	
public:
	//Default constructor of the inherited class
	MyQueue()
	{
	}
	//Overridden virtual functions
	void create();
	void Insert();
	void Delete();
	//Dextructor
	~MyQueue()
	{
	}
};

//Overriden function create in the inherited class
template<class x>
void MyQueue<x>::create()
{
	x n;
	struct node *temp;
	//Check if queue exists
	try
	{
		if(Queue<x>::front != NULL && Queue<x>::rear != NULL)
			throw 1;
	}
	catch(int i)
	{
		cout<<"Queue already exists so cannot create a new Queue";
		return;
	}
	//Check if allocation can be done
	try
	{
		temp=new node;
	}
	catch(bad_alloc e)
	{
		cout<<"Overflow";
	}
	//If space can be allocated data is inserted
	cout<<"Enter 1st data - ";
	cin>>n;
	temp->data=n;
	temp->next=NULL;
	Queue<x>::front=temp;
	Queue<x>::rear=temp;
}

//Overriden function Insert in the inherited class
template<class x>
void MyQueue<x>::Insert()
{
	x n;
	struct node *temp;
	//Check if allocation can be done
	try
	{
		temp=new node;
	}
	catch(bad_alloc e)
	{
		cout<<"Overflow";
	}
	//If space can be allocated data is inserted
	cout<<"Enter data to Insert - ";
	cin>>n;
	temp->data=n;
	temp->next=NULL;
	Queue<x>::rear->next=temp;
	Queue<x>::rear=temp;
}

//Overriden function Delete in the inherited class
template<class x>
void MyQueue<x>::Delete()
{
	x n;
	struct node *temp;
	//Checking if queue exists
	try
	{
		if(Queue<x>::front == NULL)
			throw 1;
		else
		{
			temp=Queue<x>::front;
			Queue<x>::front=Queue<x>::front->next;
			n=temp->data;
			delete temp;
			cout<<"Deleted data - "<<n;
			if(Queue<x>::front == NULL)
			{
				Queue<x>::front=NULL;
				Queue<x>::rear=NULL;
			}
		}
	}
	catch(int i)
	{
		cout<<"Underflow";
	}
}

//Main function
int main()
{
	//Declaring variables
	int c,ch;
	char x;
	//Declaring base class pointers for different types to be passed as parameter
	Queue<int> *p;
	Queue<float> *q;
	Queue<char> *s;
	//User's choice to select which type of data type to be used
	cout<<"\n\tMenu";
	cout<<"\n1.Integer";
	cout<<"\n2.Float";
	cout<<"\n3.Character";
	cout<<"\nEnter choice:- ";
	cin>>ch;
	//Creating objects depending on user's choice
	if(ch == 1)
	{
		Queue<int> ob1;
		MyQueue<int> ob2;
		p=&ob2;
	}
	if(ch == 2)
	{
		Queue<float> ob3;
		MyQueue<float> ob4;
		q=&ob4;
	}
	if(ch == 3)
	{
		Queue<char> ob5;
		MyQueue<char> ob6;
		s=&ob6;		
	}
	//Infinite loop in which creation,inserton,deletion and display of que is done
	while(1)
	{
		cout<<"\tMenu";
		cout<<"\n1.Create Queue";
		cout<<"\n2.Insert Queue";
		cout<<"\n3.Delete Queue";
		cout<<"\n4.Display Queue";
		cout<<"\n5.Exit";
		cout<<"\n\nEnter choice :- ";
		cin>>c;
		switch(c)
		{
			case 1://Creating queue
				if(ch == 1)
					p->create();
				if(ch == 2)
					q->create();
				if(ch == 3)
					s->create();
				break;
			case 2://Inserting into queue
				if(ch == 1)
					p->Insert();
				if(ch == 2)
					q->Insert();
				if(ch == 3)
					s->Insert();
				break;
			case 3://Deleing from queue
				if(ch == 1)
					p->Delete();
				if(ch == 2)
					q->Delete();
				if(ch == 3)
					s->Delete();
				break;
			case 4://Displaying queue
				if(ch == 1)
					p->Display();
				if(ch == 2)
					q->Display();
				if(ch == 3)
					s->Display();
				break;
			case 5:
				cout<<"Exiting Program";
				break;	
			default:
				cout<<"Wrong Choice :- Re-Enter";
				break;
		}
		cout<<"\nDo you want to enter :- ";
		cin>>x;
		if(x != 'y' && x != 'Y')
			break;
	}
	cout<<"\n";
	return 0;
}
