#include <iostream>
using namespace std;
template <class x>
class Stack
{
	struct node
	{
		x data;
		node*next;
	};
	node *top;
public:
	static const int ERR=-1;
	Stack();
	void push(x);
	x pop();
};
template <class x>
Stack<x>::Stack()
{
	Stack::top=NULL;
}
template <class x>
void Stack<x>::push(x data)
{
	node*tmp;
	try
	{
		tmp=new node;
	}
	catch(bad_alloc ex)
	{
		cerr<<"Overflow."<<endl;
		return;
	}
	tmp->data=data;
	tmp->next=top;
	top=tmp;
} 
template <class x>
x Stack<x>::pop()
{
	if(Stack::top==NULL)
	{
		cerr<<"Underflow."<<endl;
		return (x)Stack::ERR;
	}
	x data;
	node*tmp;
	tmp=top;
	top=top->next;
	data=tmp->data;
	delete tmp;
	return data;
}
main()
{
	Stack<int>s;
	Stack<float>f;
	s.push(10);
	s.push(20);
	s.push(30);
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	if(s.pop()==Stack<int>::ERR)
	{
		cout<<"Error"<<endl;
	}
	f.push(10.67);
	f.push(20.3);
	f.push(30.78);
	cout<<f.pop()<<endl;
	cout<<f.pop()<<endl;
	cout<<f.pop()<<endl;
	if(f.pop()==Stack<float>::ERR)
	{
		cout<<"Error"<<endl;
	}
}
