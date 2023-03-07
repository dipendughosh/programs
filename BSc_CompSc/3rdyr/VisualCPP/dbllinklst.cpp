//double linked list

#include<iostream>

using namespace std;

class dlinklist
{
private:
	struct node
	{
		struct node *prev;
		int data;
		struct node *next;
	};
	struct node *head,*tail;
public:
	dlinklist()
	{
		head=NULL;
		tail=NULL;
	}
	void create();
	void insert();
	void delet();
	void display();
	~dlinklist()
	{
	}

};

void dlinklist::create()
{
	int x;
	struct node *temp;
	try
	{
		if(dlinklist::head!=NULL && dlinklist::tail!=NULL)
			throw 1;
	}
	catch(int i)
	{
		cout<<"List already in existence";
		return;
	}
	try
	{
		temp=new node;
	}
	catch(bad_alloc ex)
	{
		cout<<"Allocation Failure";
		return;
	}
	cout<<"Enter data:- ";
	cin>>x;
	temp->data=x;
	temp->prev=NULL;
	temp->next=NULL;
	dlinklist::head=temp;
	dlinklist::tail=temp;
}

void dlinklist::insert()
{
	int x;
	struct node *temp;
	try
	{
		if(dlinklist::head==NULL && dlinklist::tail==NULL)
			throw 1;
	}
	catch(int i)
	{
		cout<<"List is not in existence";
		return;
	}
	try
	{
		temp=new node;
	}
	catch(bad_alloc ex)
	{
		cout<<"Allocation Failure";
		return;
	}
	cout<<"Enter data:- ";
	cin>>x;
	temp->data=x;
	temp->prev=dlinklist::tail;
	temp->next=NULL;
	dlinklist::tail->next=temp;
	dlinklist::tail=temp;
}

void dlinklist::delet()
{
	int x;
	struct node *temp,*ptr1,*ptr2;
	try
	{
		if(dlinklist::head==NULL && dlinklist::tail==NULL)
			throw 1;
	}
	catch(int i)
	{
		cout<<"List is not in existence";
		return;
	}
	cout<<"Enter data to delete:- ";
	cin>>x;
	if(dlinklist::head->data==x && dlinklist::head==dlinklist::tail)
	{
		cout<<"Data deleted\n";
		temp=dlinklist::head;
		dlinklist::head=NULL;
		dlinklist::tail=NULL;
		delete temp;
		return;
	}
	if(dlinklist::head->data==x)
	{
		cout<<"Data deleted\n";
		temp=dlinklist::head;
		dlinklist::head=dlinklist::head->next;
		dlinklist::head->prev=NULL;
		delete temp;
		return;
	}
	if(dlinklist::tail->data==x)
	{
		cout<<"Data deleted\n";
		temp=dlinklist::tail;
		dlinklist::tail=dlinklist::tail->prev;
		dlinklist::tail->next=NULL;
		delete temp;
		return;
	}
	ptr1=dlinklist::head;
	ptr2=ptr1;
	while(ptr1!=dlinklist::tail && ptr1->data!=x)
	{
		ptr2=ptr1;
		ptr1=ptr1->next;
	}
	if(ptr1->data==x)
	{
		temp=ptr1;
		cout<<"Data deleted\n";
		ptr2->next=ptr1->next;
		ptr1->next->prev=ptr2;
		delete temp;
	}
	return;
}

void dlinklist::display()
{
	struct node *ptr;
	ptr=dlinklist::head;
	while(ptr!=NULL)
	{
		cout<<ptr->data;
		ptr=ptr->next;
	}
}
int main()
{
	int ch;
	char c;
	dlinklist ob;
	while(1)
	{
		cout<<"\tMENU\n";
		cout<<"1.Create\n";
		cout<<"2.Insert\n";
		cout<<"3.Delete\n";
		cout<<"4.Display\n";
		cout<<"5.Exit\n";
		cout<<"\nEnter choice:- ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				ob.create();
				break;
			case 2:
				ob.insert();
				break;
			case 3:
				ob.delet();
				break;
			case 4:
				ob.display();
				break;
			case 5:
				exit(0);
				break;
			default:
				cout<<"Wrong Input";
				break;
		}
		cout<<"Do you want to contuinue?";
		cin>>c;
		if(c!='y' && c!='Y')
			break;
	}
	return 0;
}