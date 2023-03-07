#include<iostream>
#include<new>
#include<exception>

using namespace std;

template<class type>
class bst
{
	typedef struct node
	{
		struct node *left;
		type data;
		struct node *right;
	}tree;
	tree *root;
public:
	bst();
	~bst();
	void insertion(type);
	int deletion(type);
	void display();
	void inorder(tree*);
	void preorder(tree*);
	void postorder(tree*);
	void manipulation();
};

template<class type>
bst<type>::bst()
{
	root=NULL;
}

template<class type>
bst<type>::~bst()
{
	delete root;
}

template<class type>
void bst<type>::insertion(type value)
{
	tree *temp;
	try
	{
		temp=new tree;
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

	node **p=&root;
	while((*p)!=NULL)
	{
		p=((*p)->data>=value)?&((*p)->left):&((*p)->right);
	}
	*p=temp;
}

template<class type>
int bst<type>::deletion(type value)
{
	if(root==NULL)
	{
		cout<<"\nEmpty tree!";
		return 0;
	}
	tree **p=&root;
	while((*p)!=NULL && (*p)->data!=value)
	{
		p=((*p)->data>=value)?&((*p)->left):&((*p)->right);
	}
	if((*p)==NULL)
	{
		cout<<"\nData not found in tree!";
		return 0;
	}
	tree *temp;
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
		tree *x;
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

template<class type>
void bst<type>::inorder(tree *r)
{
	if(!r)
		return;
	inorder(r->left);
	cout<<r->data<<" ";
	inorder(r->right);
}

template<class type>
void bst<type>::preorder(tree *r)
{
	if(!r)
		return;
	cout<<r->data<<" ";
	preorder(r->left);
	preorder(r->right);
}

template<class type>
void bst<type>::postorder(tree *r)
{
	if(!r)
		return;
	postorder(r->left);
	postorder(r->right);
	cout<<r->data<<" ";
}

template<class type>
void bst<type>::manipulation()
{
	int ch,x;
	type p;
	while(1)
	{
		cout<<"\nPress 1 for insertion!";
		cout<<"\nPress 2 for deletion!";
		cout<<"\nPress 3 for display!";
		cout<<"\nPress 0 for exit!";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		if(ch==1)
		{
			cout<<"\nEnter the value to insert : ";
			cin>>p;
			insertion(p);
		}
		else if(ch==2)
		{
			cout<<"\nEnter the value for search and delete : ";
			cin>>p;
			x=deletion(p);
			if(x)
				cout<<"\nDeletion successful!";
			else
				cout<<"\nDeletion unsuccessful!";
		}
		else if(ch==3)
		{
			display();
		}
		else if(!ch)
			return;
		else
			cout<<"\nERROR in choice!";
	}
}

int main()
{
	char ch;
	cout<<"\nPress 'i' for integer!";
	cout<<"\nPress 'f' for float!";
	cout<<"\nPress 'c' for character!";
	cout<<"\nEnter your choice : ";
	cin>>ch;
	if(ch=='i')
	{
		bst<int> a;
		a.manipulation();
	}
	else if(ch=='f')
	{
		bst<float> b;
		b.manipulation();
	}
	else if(ch=='c')
	{
		bst<char> c;
		c.manipulation();
	}
	else
		cout<<"\nERROR in choice!\n";
	return 0;
}
