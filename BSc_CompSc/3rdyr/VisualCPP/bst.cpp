//binary search tree

#include<iostream>
#define NULL 0

using namespace std;

class bst
{
private:
	struct node
	{	struct node *left_child;
		int data;
		struct node *right_child;
	};
public:
	struct node *root;
	bst()
	{
		root=NULL;
	}	
	struct node *getnode(int x)
	{
		struct node *temp;
		temp=new node;
		temp->data=x;
		temp->left_child=NULL;
		temp->right_child=NULL;
		return temp;
	}

	void create();
	void in_recur(struct node *);
	void del();
	~bst()
	{
	}
};

//creation
void bst::create()
{   struct node *new1,*ptr,*ptr1;
	int x;
	char c;
	cout<<"Enter Root Node-";
	cin>>x;
	try
	{
		new1=new node;
	}
	catch(bad_alloc e)
	{
		cout<<"Allocation failure";
		return;
	}
	new1->data=x;
	new1->left_child=NULL;
	new1->right_child=NULL;
	root=new1;
	while(1)
	{       cout<<"Enter data - ";
		cin>>x;
	/*try
		{
			new1=new node;
		}
		catch(bad_alloc e)
		{
			cout<<"Allocation failure";
			return;
		}**/
		new1=getnode(x);
		new1->data=x;
		new1->left_child=NULL;
		new1->right_child=NULL;
		ptr=root;
		cout<<ptr->data;
		while(ptr != NULL && ptr->data!=x)
		{	if(x < ptr->data)
			{	ptr1=ptr;
				ptr=ptr->left_child;
			}
			else if(x > ptr->data)
			{	ptr1=ptr;
				ptr=ptr->right_child;
			}
			else
			{	cout<<"\nDuplicate";
				break;
			}
		}
		if(x != ptr->data)
		{	if(x < ptr1->data)
				ptr1->left_child=new1;
			else
				ptr1->right_child=new1;
		}
		/*else
			delete new1;*/
		cout<<"Do you want to continue?(y/Y) :- ";
		cin>>c;
		if(c != 'y' && c != 'Y')
			break;
	}
}

void bst::in_recur(struct node *temp)
{   
	if(temp!=NULL)
	{	in_recur(temp->left_child);
		cout<<"\t"<<temp->data;
		in_recur(temp->right_child);
	}
}

void bst::del()
{	struct node *ptr,*par,*ptr1,*ptr2;
	int x;
	cout<<"\nDeleting a node\n";
	cout<<"Enter node to delete- ";
	cin>>x;
	par=ptr=root;
	while(ptr != NULL && ptr->data != x)
	{	par=ptr;
		if(x < ptr->data)
			ptr=ptr->left_child;
		else
			ptr=ptr->right_child;
	}
	if(ptr->right_child == NULL && ptr->left_child == NULL)
	{       if(x == root->data)
		{	cout<<"\nDeleted - "<<ptr->data;
			delete root;
			root=NULL;
			cout<<"\nTree empty";
			return;
		}
		if(par->right_child==ptr)
			par->right_child=NULL;
		else
			par->left_child=NULL;
		cout<<"\nDeleted - "<<ptr->data;
		delete ptr;
	}
	else if(ptr->right_child == NULL || ptr->left_child == NULL)
	{       if(root -> data == x)
		{	if(ptr->right_child == NULL)
				root=ptr->left_child;
			else
				root=ptr->right_child;
			return;
		}
		if(ptr->right_child == NULL)
		{	if(par->right_child==ptr)
				par->right_child=ptr->left_child;
			else
				par->left_child=ptr->left_child;
		}
		if(ptr->left_child == NULL)
		{	if(par->right_child==ptr)
				par->right_child=ptr->right_child;
			else
				par->left_child=ptr->right_child;
		}
		cout<<"\nDeleted - "<<ptr->data;
		delete ptr;
	}
	else
	{       ptr1=ptr2=ptr->right_child;
		while(ptr2->left_child != NULL)
		{	ptr1=ptr2;
			ptr2=ptr2->left_child;
		}
		ptr1->left_child=ptr2->right_child;
		ptr2->right_child=ptr->right_child;
		ptr2->left_child=ptr->left_child;
		if(par == ptr)
			root=ptr2;
		else
		{	if(par->right_child == ptr)
				par->right_child=ptr2;
			else
				par->left_child=ptr2;
		}
	}
}
int main()
{       bst ob;
	ob.create();
	ob.in_recur(ob.root);
	ob.del();
	return 0;
}
