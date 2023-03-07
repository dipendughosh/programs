#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

class linklist
{	private:
	struct node
	{	int data;
		node *link;
	}	*p;
	public:
	linklist();
	void append(int);
	void addatbeg(int);
	void addafter(int,int);
	void del(int);
	void display();
	int count();
	~linklist();
};

linklist::linklist()
{	p=NULL;
}

void linklist::append(int num)
{	node *q,*t;
	if(p==NULL)
	{	p=new node;
		p->data=num;
		p->link=NULL;
	}
	else
	{	q=p;
		while(q->link!=NULL)
		{	q=q->link;
		}
		t=new node;
		t->data=num;
		t->link=NULL;
		q->link=t;
	}
}

void linklist::addatbeg(int num)
{       node *q;
	q=new node;
	q->data=num;
	q->link=NULL;
	p=q;
}

void linklist::addafter(int c,int num)
{	node *q,*t;
	int i;
	for(i=0,q=p;i<c;i++)
	{	q=q->link;
		if(q==NULL);
		{	cout<<"\nThere are less than "<<c<<" elements";
			return;
		}
	}
	t=new node;
	t->data=num;
	t->link=NULL;
	q->link=t;
}

void linklist::del(int num)
{	node *q,*t;
	q=p;
	if(q->data==NULL)
	{	p=q->link;
		delete q;
		return;
	}
	t=q;
	while(q!=NULL)
	{	if(q->data==num)
		{	t->link=q->link;
			delete q;
			return;
		}
		t=q;
		q=q->link;
	}
	cout<<"\nElement "<<num<<" not found";
}

void linklist::display()
{	node *q;
	for(q=p;q!=NULL;q=q->link)
	{	cout<<"\n"<<q->data;
	}
}

int linklist::count()
{	node *q;
	int c=0;
	for(q=p;q!=NULL;q=q->link)
	{	c++;
	}
	return c;
}

linklist::~linklist()
{	node *q;
	if(p==NULL)
	{	return;
	}
	while(p!=NULL)
	{	q=p->link;
		delete p;
		p=q;
	}
}

void main()
{	clrscr();
	linklist l;
	cout<<"\nNumber of elements in linklist "<<l.count();
	l.append(10);
	l.addatbeg(20);
	l.addafter(1,40);
	l.display();
	cout<<"\nNumber of elements in linklist "<<l.count();
	l.del(10);
	cout<<"\nNumber of elements in linklist "<<l.count();
cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}































































































































