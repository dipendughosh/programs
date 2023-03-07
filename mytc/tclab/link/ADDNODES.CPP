//Adding nodes at the begining or at the rear
#include<iostream.h>
#include<conio.h>
class list
{	private:
	struct node
	{	int data;
		node *address;
	}*x;
	public:
	list() {	x = NULL;	}
	void addfront(int n);
	void addback(int n);
	void sholist();
	//~list();
};
void list::addfront(int num)
{	node *temp;
	temp = new node;
	temp->data = num;
	temp->address = x;
	x = temp;
}
void list::addback(int num)
{	node *temp,*newnode;
	if(x == NULL)
	{   temp = new node;
		temp->data = num;
		temp->address = NULL;
	}
	else
	{	temp = x;
		while(temp->address != NULL)
			temp = temp->address;
		newnode = new node;
		newnode->data = num;
		newnode->address = NULL;
		temp->address = newnode;
	}
}
void list::sholist()
{	node *temp = x;
	cout<<"\nThe Link-List is ...\n";
	while(temp != NULL)
	{	cout<<temp->data<<"  ";
		temp = temp->address;
	}
}
void main()
{	list obj;
	clrscr();
	int valu, choice;
	cout<<"Enter value for First node : "; cin >> valu;
	obj.addfront(valu);
	for(int i = 0; i < 5; i++)
	{
		cout<<"Choice : 1(Front)/0(Back)---> "; cin>>choice;
		cout<<"Enter value : "; cin>>valu;
		if(choice == 1)
			obj.addfront(valu);
		else
			obj.addback(valu);
	}
	cout<<endl;
	obj.sholist();
	getche();
}




