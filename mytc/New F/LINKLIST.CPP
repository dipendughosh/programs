//***LINK-LIST***
#include<iostream.h>
#include<conio.h>

struct link
{	int data;
	link *next;
};

class  linklist
{
	private:
		link *first;
	public:
		linklist()
			{  first=NULL;  }
		void additem(int d)
			{  link* newlink;
			   newlink = new link;
			   newlink->data=d;
			   newlink->next=first;
			   first=newlink;
			}
		void display();
		void displayat(int ,int);
};
void linklist::display()
{	link *current=first;
	while(current!=NULL)
	{	cout<<"\ncurrent data   " <<current->data;
		current =current->next;
	}
}
void linklist::displayat(int p,int size)
{	link *current=first;
	int pos=size-p,c=0;
	while(current!=NULL)
	{   if((c++)==pos)
		{	cout<<"\n req data  "<<current->data;
			break;
		}
		current = current->next;
	}
}

void main()
{	clrscr();
	linklist obj;   int in;
	for(int i=0;i<5;i++)
	{	cout<<"enter no  ";
		cin>>in;
		obj.additem(in);
	 }
	obj.display();
	obj.displayat(3,5);
	getche();
}

