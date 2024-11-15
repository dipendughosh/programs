//To perform Binary Search Tree operations
#include<iostream>
#include<new>
#include<exception>

using namespace std;

//Template class bst
template<class type>
class bst
{
//Begining of private scope
	//Node structure
private:
	struct node
	{
		struct node *left;
		type data;
		struct node *right;
	};
	//Root pointer
	struct node *root;
//Begining of public scope
public:
	//Default constructor
	bst()
	{
		root=NULL;
	}
	//Prototypes of functions
	void insert(type);
	int delet(type);
	void display();
	void inorder(struct node*);
	void preorder(struct node*);
	void postorder(struct node*);
	void temp_type();
	//Destructor
	~bst()
	{
		delete root;
	}
};

//Function to insert an element into the tree
template<class type>
void bst<type>::insert(type value)
{
	struct node *temp;
	try
	{
		temp=new node;
	}
	catch(bad_alloc xa)
	{
		cout<<"\nAllocation failure!\n";
		terminate();
	}
	temp->data=value;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
		return;
	}
	struct node **p=&root;
	while((*p)!=NULL)
	{
		p=((*p)->data>=value)?&((*p)->left):&((*p)->right);
	}
	*p=temp;
}

//Function to delete an element from the tree
template<class type>
int bst<type>::delet(type value)
{
	if(root==NULL)
	{
		cout<<"\nEmpty tree!";
		return 0;
	}
	struct node **p=&root;
	while((*p)!=NULL && (*p)->data!=value)
	{
		p=((*p)->data>=value)?&((*p)->left):&((*p)->right);
	}
	if((*p)==NULL)
	{
		cout<<"\nData not found in tree!";
		return 0;
	}
	struct node *temp;
	if((*p)->left==NULL)
	{
		temp=*p;
		*p=(*p)->right;
		temp->right=NULL;
		delete temp;	
	}
	else if((*p)->right==NULL)
	{
		temp=*p;
		*p=(*p)->left;
		temp->left=NULL;
		delete temp;
	}
	else
	{
		struct node *x;
		temp=*p;
		x=(*p)->right;
		*p=(*p)->left;
		temp->left=NULL;
		temp->right=NULL;
		delete temp;
		for(;(*p)->right!=NULL;p=&((*p)->right));
		(*p)->right=x;
	}
	return 1;
}

//Function to display the tree in different forms
template<class type>
void bst<type>::display()
{
	cout<<"\nInorder traversal : ";
	inorder(root);
	cout<<"\nPreorder traversal : ";
	preorder(root);
	cout<<"\nPostorder traversal : ";
	postorder(root);
}

//Inorder traversal
template<class type>
void bst<type>::inorder(struct node *r)
{
	if(!r)
		return;
	inorder(r->left);
	cout<<r->data<<" ";
	inorder(r->right);
}

//Preorder traversal
template<class type>
void bst<type>::preorder(struct node *r)
{
	if(!r)
		return;
	cout<<r->data<<" ";
	preorder(r->left);
	preorder(r->right);
}

//Postorder traversal
template<class type>
void bst<type>::postorder(struct node *r)
{
	if(!r)
		return;
	postorder(r->left);
	postorder(r->right);
	cout<<r->data<<" ";
}

//Choice of the user
template<class type>
void bst<type>::temp_type()
{
	int ch,x;
	type p;
	while(1)
	{
		cout<<"\n1.Insert";
		cout<<"\n2.Delete";
		cout<<"\n3.Display";	
		cout<<"\n4.Exit";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the value to insert : ";
				cin>>p;
				insert(p);
				break;
			case 2:
				cout<<"\nEnter the value for search and delete : ";
				cin>>p;
				x=delet(p);
				if(x == 1)
					cout<<"\nDeletion successful!";
				else
					cout<<"\nDeletion unsuccessful!";
				break;
			case 3:
				display();
				break;
			case 4:
				return;
			default:
				cout<<"\nERROR in choice!";
				break;
		}
	}
}

//Main function
int main()
{
	char ch;
	cout<<"\n'i' for integer!";
	cout<<"\n'f' for float!";
	cout<<"\n'c' for character!";
	cout<<"\nEnter your choice : ";
	cin>>ch;
	if(ch=='i')
	{
		bst<int> a;
		a.temp_type();
	}
	else if(ch=='f')
	{
		bst<float> b;
		b.temp_type();
	}
	else if(ch=='c')
	{
		bst<char> c;
		c.temp_type();
	}
	else
		cout<<"\nERROR in choice!\n";
	return 0;
}
