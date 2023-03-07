//crcular linklist

#include<iostream>

using namespace std;

template<class type>
class cll
{
private:
	struct node
	{
		type data;
		struct node *next;
	};
	struct node *tail;
public:
	cll()
	{
		cll::tail=NULL;
	}
	void create();
	void insert();
	void delet();
	void display();
	void temp_type();
	~cll()
	{
		delete cll::tail;
	}
};

template<class type>
void cll<type>::create()
{
	type x;
	struct node *temp;
	try
	{
		if(tail!=NULL)
			throw 1;
	}
	catch(int i)
	{
		cout<<"Que in esistence";
		return;
	}
	try
	{
		temp=new node;
	}
	catch(bad_alloc ex)
	{
		cout<<"Allocation failure";
		return;
	}
	cout<<"Enter daat:- ";
	cin>>x;
	temp->data=x;
	temp->next=temp;
	cll<type>::tail=temp;
}

template<class type>
void cll<type>::insert()
{
	type x;	
	struct node *temp;
	try
	{
		if(cll<type>::tail==NULL)
			throw 1;
	}
	catch(int i)
	{
		cout<<"Que does not exist";
		return;
	}
	try
	{
		temp=new node;
	}
	catch(bad_alloc ex)
	{
		cout<<"Allocation failure";
		return;
	}
	cout<<"Enter daat:- ";
	cin>>x;
	temp->data=x;
	temp->next=cll<type>::tail->next;
	cll<type>::tail->next=temp;
	cll<type>::tail=temp;
}

template<class type>
void cll<type>::delet()
{
	struct node *temp;
	try
	{
		if(cll<type>::tail==NULL)
			throw 1;
	}
	catch(int i)
	{
		cout<<"Que does not exist";
		return;
	}
	temp=cll<type>::tail->next;
	cll<type>::tail->next=cll<type>::tail->next->next;
	cout<<"Deleted\t"<<temp->data<<endl;
	delete temp;
}

template<class type>
void cll<type>::display()
{
	struct node *ptr;
	ptr=cll<type>::tail->next;
	while(ptr!=cll<type>::tail)
	{
		cout<<ptr->data<<"\t";
		ptr=ptr->next;
	}
	cout<<ptr->data<<"\t";
	cout<<"\n";
}

template<class type>
void cll<type>::temp_type()
{
	char ch;
	int c;
	while(1)
	{
		cout<<"\tMENU\n1.Create\n2.Insert\n3.Delete\n4.Display\n5.Exit\nEnter choice:- ";
		cin>>c;
		switch(c)
		{
		case 1:
			create();
			break;
		case 2:
			insert();
			break;
		case 3:
			delet();
			break;
		case 4:
			display();
			break;
		case 5:
			exit(0);
			break;
		default:
			cout<<"Wrong Choice";
			break;
		}
		cout<<"\nDo you want to continue?(y/Y):-";
		cin>>ch;
		if(ch!='y' && ch!='Y')
			break;
	}
}

int main()
{
	char ch;
	cout<<"i.Integer\nf.Float\nc.Charecter\nEnter choice:- ";
	cin>>ch;
	if(ch=='i')
	{
		cll<int> ob1;
		ob1.temp_type();
	}
	if(ch=='f')
	{
		cll<float> ob2;
		ob2.temp_type();
	}
	if(ch=='c')
	{
		cll<char> ob3;
		ob3.temp_type();
	}
	return 0;
}