#include<iostream>

using namespace std;

template<class x>
class Stack
{
private:
	struct node
	{
		x data;
		node *next;
	};
	node *top;
public:
	static const int ERR=-1;
	Stack();
	void push(x);
	x pop();
};
	
template<class x>
Stack<x>::Stack()
{
	Stack::top=NULL;
}

template<class x>
void Stack<x>::push(x data)
{
	node *temp;
	try
	{
		temp=new node;
	}
	catch(bad_alloc ex)
	{
		cout<<"OverFlow"<<endl;
		return;
	}
	temp->data=data;
	temp->next=top;
	top=temp;
}

template<class x>
x Stack<x>::pop()
{
	if(top==NULL)
	{
		cout<<"UnderFlow"<<endl;
		return (x)(Stack::ERR);
	}
	int data;
	node *temp;
	temp=top;
	data=temp->data;
	top=top->next;
	delete temp;
	return data;
}

main()
{
	Stack<int> ob1;
	ob1.push(10);
	ob1.push(20);
	ob1.push(30);
	cout<<ob1.pop()<<endl;
	cout<<ob1.pop()<<endl;
	cout<<ob1.pop()<<endl;
	if(ob1.pop()==Stack<int>::ERR)
		cout<<"ERROR"<<endl;
}


