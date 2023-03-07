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
public:
	static const int ERR=-1;
	Stack();
	void push(x);
	x pop();
	~Stack();
};

Stack<x>::Stack()
{
	node *top=NULL;
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
	}
	temp->data=stack::data;
	temp->next=top;
	top=temp;
	delete temp;
}

template<class x>
x Stack<x>::pop()
{
	if(top==NULL)
	{
		cout<<"UnderFlow"<<endl;
		return (x)(ERR);
	}
	int data;
	node *temp;
	temp=top;
	top=top->next;
	delete temp;
	return data;
}

Stack<x>::~Stack()
{
	delete top;
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
	return 0;
}


