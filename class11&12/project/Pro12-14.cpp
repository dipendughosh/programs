//stack and queue
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

struct node
{	int data;
	node *link;
};

class stack
{	private:
	node *top;
	public:
	stack();
	void push(int);
	int pop();
	~stack();
};

stack::stack()
{	top=NULL;
}

void stack::push(int num)
{	node *temp;
	temp = new node;
	if(temp == NULL)
	{	cout<<"\nStack is full->";
		temp->data=num;
		temp->link=top;
		top=temp;
	}
}

int stack::pop()
{       if(top==NULL)
	{	cout<<"\nStack is empty.....";
		return NULL;
	}
	node *temp;
	int item;
	temp=top;
	item=temp->data;
	top=top->link;
	delete temp;
	return item;
}

stack::~stack()
{	if(top==NULL)
	{	return;
	}
	node *temp;
	while(top!=NULL)
	{	temp=top;
		top=top->link;
		delete temp;
	}
}

void main()
{	clrscr();
	stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	int i=s.pop();
	cout<<"\nItem pop = "<<i;
	i=s.pop();
	cout<<"\nItem pop = "<<i;
	getche();
}































































































































