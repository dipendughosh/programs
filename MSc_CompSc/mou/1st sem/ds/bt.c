#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


struct node
{
	int val[10];//values
	int nd;//no of values
	struct node *ad[10];//children
	int nl;//no of children
};
int n;//order of the tree
struct node *getnode()
{
	int i;
	struct node *new1;
	new1=(struct node *)malloc(sizeof(struct node));
	for(i=1;i<=n;i++)
	{
		new1->val[i]=0;
		new1->ad[i]=NULL;
	}
	new1->ad[i]=NULL;
	new1->nd=0;
	new1->nl=1;
	return(new1);
}

struct node *root,*ptr,*ptr1,*stk[50];

void main()
{
	void insert();
	void split();
	void display();
	root=NULL;
	printf("Enter order of the B-Tree - ");
	scanf("%d",&n);
	insert();
	display();
}

void insert()
{
	int v,i,f,tp=-1,a=0;
	struct node *new1;
	printf("\nEnter value - ");
	scanf("%d",&v);
	if(root==NULL)
	{
		new1=getnode();
		new1->val[1]=v;
		new1->nd++;
		new1->nl++;
		root=new1;
	}
	ptr=root;
	f=1;
	do
	{
		if(f==1)
		{
			printf("\nEnter value - ");
			scanf("%d",&v);
		}
		if(ptr->ad[1]==NULL && ptr->nd<n)
		{
			for(i=ptr->nd;i>=1;i--)
			{
				if(ptr->val[i]>v)
				{
					ptr->val[i+1]=ptr->val[i];
					ptr->ad[i+2]=ptr->ad[i+1];
				}
				else
					break;
			}
			ptr->val[i+1]=v;
			ptr->ad[i+2]=NULL;
			ptr->nd++;
			ptr->nl++;
		}
		else if(ptr->ad[1]!=NULL && ptr->nd<n)
		{
			stk[++tp]=ptr;
			for(i=1;i<n;i++)
			{
				if(v<ptr->val[i])
					break;
			}
			ptr=ptr->ad[i];
			f=0;
			continue;
		}
		else if(ptr->nd==n-1)
		{
			if(tp==-1)
				ptr1=NULL;
			else
				ptr1=stk[tp--];
			if(a==0)
			{
				for(i=ptr->nd;i>=1;i--)
				{
					if(ptr->val[i]>v)
					{
						ptr->val[i+1]=ptr->val[i];
						ptr->ad[i+2]=ptr->ad[i+1];
					}
					else
						break;
				}
				ptr->val[i+1]=v;
				ptr->ad[i+2]=NULL;
				ptr->nd++;
				ptr->nl++;
				a=1;
			}
			split();
			if(ptr1!=NULL)
				ptr=ptr1;
			else
				ptr=root;
			f=0;
			continue;
		}
		printf("\nDo you want to continue? (1=YES,0=NO) :- ");
		scanf("%d",&f);
		ptr=root;
		a=0;
	}while(f==1);
}

void split()
{
	int i,x,y,z,v;
	struct node *new1,*new2;
	new1=getnode();
	new2=getnode();
	if(ptr->nd%2!=0)
		x=(ptr->nd/2)+1;
	else
		x=(ptr->nd)/2;
	y=x-1;
	z=x+1;
	v=ptr->val[x];
	for(i=1;i<=y;i++)
	{
		new1->val[i]=ptr->val[i];
		new1->nd++;
		new1->nl++;
	}
	for(i=z,y=1;i<=ptr->nd;i++,y++)
	{
		new2->val[y]=ptr->val[i];
		new2->nd++;
		new2->nl++;
	}
	if(ptr1==NULL)
	{
		ptr1=getnode();
		ptr1->val[1]=v;
		ptr1->nd++;
		ptr1->nl++;
		ptr1->ad[1]=new1;
		ptr1->ad[2]=new2;
		root=ptr1;
	}
	else
	{
		for(i=ptr1->nd;i>=1;i--)
		{
			if(ptr1->val[i]>v)
			{
				ptr1->val[i+1]=ptr1->val[i];
				ptr1->ad[i+2]=ptr1->ad[i+1];
			}
			else	
				break;
		}
		ptr1->val[i+1]=v;
		ptr1->ad[i]=new1;
		ptr1->ad[i+1]=new2;
		ptr1->nd++;
		ptr1->nl++;
	}
	ptr=ptr1;
}

void display()
{
	struct node *qu[50];
	int f=-1,r=-1,i,x;
	ptr=root;
	qu[++r]=ptr;
	while(f!=r)
	{
		for(i=1;i<qu[++f]->nd;i++)
				printf("%d\t",qu[f]->val[i]);
		x=qu[r]->nl;
		for(i=1;i<=x;i++)
		{
			if(ptr->ad[i]!=NULL)
				qu[++r]=ptr->ad[i];
		}
		printf("\n");
	}
}
