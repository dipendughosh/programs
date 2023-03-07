#include<iostream.h>
#include<conio.h>
class trees
{
	private:
	struct node
	{	node *left, *right;
		char data;
	}
	*root;
	char *arr;
	int *lc, *rc;
	public:
	trees(char *a, int *l, int *r, int len);
	void addleaf(int index);
	node *grow(char *a, int *l, int *r, int index)
	{	node *temp = NULL;
		if(index != -1)
		{	temp = new node;
			temp->left = grow(a,l,r,*(l+index));
			temp->data = *(a+index);
			temp->right = grow(a,l,r,*(r+index));
		}
		return temp;
	}
	void show();
	void inorder(node *x);
};
trees::trees(char *a, int *l, int *r, int len)
{	root = NULL;
	arr = new  char[len];
	lc = new int[len];
	rc = new int[len];
	for(int i = 0; i < len; i++)
	{	*(arr+i) = *(a+i);
		*(lc+i) = *(l+i);
		*(rc+i) = *(r+i);
	}
}
void trees::addleaf(int index)
{	root = grow(arr,lc,rc,index);	}

/*node* trees::grow(char *a, int *l, int *r, int index)
{	node *temp = NULL;
	if(index != -1)
	{	temp = new node;
		temp->left = grow(a,l,r,*(l+index));
		temp->data = *(a+index);
		temp->right = grow(a,l,r,*(r+index));
	}
	return temp;
} */
void trees::show()
{	inorder(root);	}

void trees::inorder(node *x)
{	if(x != NULL)
	{	inorder(x->left);
		cout<<x->data<<"  ";
		inorder(x->right);
	}
}
void main()
{
	clrscr();
	char a[] = {'M','A','N','\0','G','O'};
	int l[] = { 1,3,-1,-1,5,-1};
	int r[] = { 2,4,-1,-1,-1,-1};
	int size = sizeof(a);
	trees mango(a,l,r,size);
	mango.addleaf(0);
	cout<<"\nInorder traversal..."<<endl;
	mango.show();
	getche();
}
