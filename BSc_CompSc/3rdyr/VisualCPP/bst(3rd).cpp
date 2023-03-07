//binary search tree

#include<iostream>
#include<exception>
#include<new>
//#define NULL 0

using namespace std;

class bst
{
private:
	struct node
	{	struct node *left_child;
		int data;
		struct node *right_child;
	};
	struct node *root;
public:
	bst()
	{
		root=NULL;
	}	
	void create();
	//void in();
	//void del();
	~bst()
	{
	}
};

//creation
void bst::create()
{   struct node *temp,*ptr,*ptr1;
	int x;
	char c;
	cout<<"Enter Root Node-";
	cin>>x;
	try
	{
		temp=new node;
	}
	catch(bad_alloc e)
	{
		cout<<"Allocation failure";
		return;
	}
	temp->data=x;
	temp->left_child=NULL;
	temp->right_child=NULL;
	root=temp;
	while(1)
	{   cout<<"Enter data - ";
		cin>>x;
		try
		{
			temp=new node;
		}
		catch(bad_alloc e)
		{
			cout<<"Allocation failure";
			return;
		}
		temp->data=x;
		temp->left_child=NULL;
		temp->right_child=NULL;
		ptr=root;
	//	cout<<ptr->data;
		while(ptr != NULL)
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
				ptr1->left_child=temp;
			else
				ptr1->right_child=temp;
		}
		else
			delete temp;
		cout<<"Do you want to continue?(y/Y) :- ";
		cin>>c;
		if(c != 'y' && c != 'Y')
			break;
	}
}

//inorder
/*void bst::in()
{	struct node *ptr1,*stk1[20];
	int tp;
	printf("\nInorder\n");
	tp=0;
	stk1[tp]=root;
	tp++;
	while(tp != 0)
	{	ptr1=stk1[tp-1]->left_child;
		while(ptr1 != NULL)
		{	stk1[tp]=ptr1;
			tp++;
			ptr1=ptr1->left_child;
		}
		if(stk1[tp-1]->right_child != NULL)
		{	cout<<"t"<<stk1[tp-1]->data;
			stk1[tp-1]=stk1[tp-1]->right_child;
		}
		if(stk1[tp-1]->right_child == NULL)
		{	cout<<"\t"<<stk1[tp-1]->data;
			tp--;
			if(tp!=0)
			{	cout<<"\t"<<stk1[tp-1]->data;
				stk1[tp-1]=stk1[tp-1]->right_child;
			}
		}
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
}*/
int main()
{   bst ob;
	ob.create();
	//ob.in();
	//ob.del();
	return 0;
}
