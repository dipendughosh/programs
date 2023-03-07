//link list using class
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
	int n, a, i, c, b;
	char ch;
	do
	{       clrscr();
		gotoxy(40,2);
		cout<<"MENU";
		gotoxy(30,3);
		cout<<"1.APPEND";
		gotoxy(30,4);
		cout<<"2.ADD AT BEGINING";
		gotoxy(30,5);
		cout<<"3.ADD AFTER";
		gotoxy(30,6);
		cout<<"4.DELETE";
		gotoxy(30,7);
		cout<<"5.DISPLAY";
		gotoxy(30,8);
		cout<<"6.EXIT";
		gotoxy(30,9);
		cout<<"Enter choice-> ";
		cin>>c;
		switch(c)
		{	case 1:
				cout<<"\nEnter number of elements to enter-> ";
				cin>>n;
				cout<<"\nEnter elements->\n";
				for(i=0;i<n;i++)
				{	cin>>a;
					l.append(a);
				}
				cout<<"\nNumber of elements in linklist "<<l.count()<<"\n";
				l.display();
			break;
			case 2:
				cout<<"\nEnter number of elements to enter at begining-> ";
				cin>>n;
				cout<<"\nEnter elements->\n";
				for(i=0;i<n;i++)
				{	cin>>a;
					l.addatbeg(a);
				}
				cout<<"\nNumber of elements in linklist "<<l.count()<<"\n";
				l.display();
			break;
			case 3:
				cout<<"\nEnter number of elements to enter after-> ";
				cin>>n;
				cout<<"\nEnter elements->\n";
				for(i=0;i<n;i++)
				{       cout<<"\nEnetr element-> ";
					cin>>a;
					cout<<"\nEnetr position-> ";
					cin>>b;
					l.addafter(a,b);
				}
				cout<<"\nNumber of elements in linklist "<<l.count()<<"\n";
				l.display();
			break;
			case 4:
				cout<<"\nEnter number of elements to delete-> ";
				cin>>n;
				cout<<"\nEnter elements->\n";
				for(i=0;i<n;i++)
				{	cin>>a;
					l.del(a);
				}
				cout<<"\nNumber of elements in linklist "<<l.count()<<"\n";
				l.display();
			break;
			case 5:
				l.display();
			break;
			case 6:
				exit(0);
				cout<<"\nEXITING.........";
				getche();
			break;
			default:
				cout<<"\nWRONG CHOICE\a!";
			break;
		}
		cout<<"\nDo you want to continue (y/n)->";
		cin>>ch;
	}while(ch == 'y' || ch == 'Y');

	getche();
}































































































































