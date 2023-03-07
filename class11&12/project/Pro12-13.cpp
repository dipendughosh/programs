//queue
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

class queue
{	private:
	node *front,*rare;
	public:
	queue();
	void addqueue(int);
	int delqueue();
	~queue();
};

queue::queue()
{	front=rare=NULL;
	rare=rare->link;
}

void queue::addqueue(int num)
{	node *temp;
	temp=new node;
	int item;
	if(temp==NULL)
	{	cout<<"\nQue is full";
	}
	temp->data=item;
	temp->link=NULL;
	if(front==NULL)
	{	front=rare=temp;
		return;
	}
	rare->link=temp;
	rare=rare->link;
}

int queue::delqueue()
{	if(front==NULL)
	{	cout<<"\nQueue is empty....";
	}
	node *temp;
	int item;
	item=front->data;
	temp=front;
	front=front->link;
	delete temp;
	return item;
}

queue::~queue()
{	if(front==NULL)
	{	return;
	}
	node *temp;
	while(front!=NULL)
	{	temp=front;
		front=front->link;
		delete temp;
	}
}

void main()
{	clrscr();
	queue q;
	q.addqueue(1);
	q.addqueue(2);
	q.delqueue();
	getche();
}































































































































