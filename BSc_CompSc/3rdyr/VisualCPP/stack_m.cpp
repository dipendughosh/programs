//Overflow and underflow in stack

#include<iostream>

using namespace std;

//Template bass class
template<class x>
class Stack
{
//Begining of public scope     	
public:
//Node structure of the nodes:-Data part-data,address part-*next
	struct node
	{
		x data;
		node *link;
	};
	//Pointers of the Stack top
	struct node *top;
	//Constructor to initialze Stack pointers
	Stack()
	{
		Stack::top=NULL;
	}
	//Prototypes of Virtual functions for the basic operations of Stack
	virtual void create();
	virtual void push();
	virtual void pop();
	void display();
	//Destructor
	~Stack()
	{
	}
};

//Base class virtual function to create the stack
template<class x>
void Stack<x>::create()
{
	x data;
	struct node *temp;
	if(Stack<x>::top != NULL)
	{
		cout<<"Stack already exist so canot creat new stack.";
		return;
	}
	cout<<"Enter the 1st data: ";
	cin>>data;
	temp=new node;
	temp->data=data;
	temp->link=top;
	Stack<x>::top=temp;
}

//Base class virtual function to push node into the stack
template<class x>
void Stack<x>::push()
{
	x data;
	struct node *temp;
	cout<<"Enter data to be inserted: ";
	cin>>data;
	temp=new node;
	temp->data=data;
	temp->link=top;
	Stack<x>::top=temp;
}

//Base class virtual function to pop node from the stack
template<class x>
void Stack<x>::pop()
{
	struct node *temp;
	x data;
	temp=top;
	data=temp->data;
	cout<<"Deleting data"<<data;
	top=top->link;
	delete temp;
	if(Stack<x>::top == NULL)
		Stack<x>::top=NULL;
}

//Function to display the elements of the stack
template<class x>
void Stack<x>::display()
{
	struct node *temp;
	if(Stack<x>::top == NULL)
	{
		cout<<"Stack is empty,nothing to display.";
	}
	else
	{
		temp=Stack<x>::top;
		while(temp != NULL)
		{
			cout<<temp->data;
			temp=temp->link;
		}
	}
}

//Inherited MyStack class to handle the exceptions
template<class x>
class MyStack:public Stack<x>
{
//Begining of public scope     	
public:
	//Default constructor of the inherited class
	MyStack()
	{
	}
        //Overridden virtual functions
	void create();
	void push();
	void pop();
        //Destructor
	~MyStack()
	{
	}
};

//Overriden function create in the inherited class
template<class x>
void MyStack<x>::create()
{
	x data;
	struct node *temp;
	//Check if stack exists
	try
	{
		if(Stack<x>::top != NULL)
		{
			throw 1;
		}
		
	}
	catch(int i)
	{
		cout<<"Stack already exit so cannot create new stack.";
		return;
	}
	//Check if allocation can be done
	try
	{
		temp=new node;
	}
	catch(bad_alloc)
	{
		cout<<"allocation falior..";
	}
        //If space can be allocated data is inserted
	cout<<"Enter the 1st datai:- ";
	cin>>data;
	temp=new node;
	temp->data=data;
	temp->link=Stack<x>::top;
	Stack<x>::top=temp;
}

//Overriden function push in the inherited class
template<class x>
void MyStack<x>::push()
{
	x data;
	struct node *temp;
        //Check if allocation can be done
	try
	{
		temp=new node;
	}
	catch(bad_alloc)
	{
		cout<<"Overflow.";
	}
        //If space can be allocated data is inserted
	cout<<"Enter data to be inserted: ";
	cin>>data;
	temp->data=data;
	temp->link=Stack<x>::top;
	Stack<x>::top=temp;
}

//Overriden function pop in the inherited class
template<class x>
void MyStack<x>::pop()
{
	struct node *temp;
	x data;
       //Checking if stack exists
	try
	{
		if(Stack<x>::top == NULL)
		{
			throw 1;
		}
	}
	catch(bad_alloc)
	{
		cout<<"Underflow";
	}
	temp=Stack<x>::top;
	data=temp->data;
	cout<<"Deleting data"<<data;
	Stack<x>::top=Stack<x>::top->link;
	delete temp;
	if(Stack<x>::top == NULL)
		Stack<x>::top=NULL;
}

//Main function
main()
{
        //Declaring variables
	int ch,c;
	char x;
        //Declaring base class pointers for different types to be passed as parameter
	Stack<int> *p;
	Stack<char> *q;
	Stack<double> *r;
        //User's choice to select which type of data type to be used
	cout<<"\n\tMain Menu";
	cout<<"\n1.Integer";
	cout<<"\n2.Charactor";
	cout<<"\n3. Float";
	cout<<"\nEnter Choice";
	cin>>ch;
        //Creating objects depending on user's choice
	if(ch == 1)
	{
		Stack<int> ob;
		MyStack<int> ob1;
		p=&ob1;
	}

	if(ch == 2)
	{
		Stack<char> ob2;
		MyStack<char> ob3;
		q=&ob3;
	}

	if(ch == 3)
	{
		Stack<double> ob4;
		MyStack<double> ob5;
		r=&ob5;
	}
        //Infinite loop in which creation,inserton,deletion and display of stack is done
	while(1)
	{
		cout<<"\tSub Menu:";
		cout<<"\n1.Creat stack";
		cout<<"\n2.Push";
		cout<<"\n3.Pop";
		cout<<"\n4.Display stack";
		cout<<"\n5.Exit";
		cout<<"Enter choice: ";
		cin>>c;
		switch(c)
		{
			case 1://Creating stack
				if(ch==1)
					p->create();
				if(ch==2)
					q->create();
				if(ch==3)
					r->create();
				break;
			case 2://push into stack
				if(ch==1)
					p->push();
				if(ch==2)
					q->push();
				if(ch==3)
					r->push();
				break;
			case 3://pop from stack
				if(ch==1)
					p->pop();
				if(ch==2)
					q->pop();
				if(ch==3)
					r->pop();
				break;
			case 4://Displaying stack
				if(ch==1)
					p->display();
				if(ch==2)
					q->display();
				if(ch==3)
					r->display();
				break;
			case 5:
				cout<<"Exit...";
				break;
			default:
				cout<<"Wrong input";
				break;
		}
		cout<<"Do you want to exit?(y/Y) ";
		cin>>x;
		if(x!='y' && x!='Y')
			break;
	}
	return 0;
}


