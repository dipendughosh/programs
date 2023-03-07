#include<iostream.h>
#include<conio.h>
struct link
{ int data;
  int *next;
};
class linklist
{ link *first;
   public:
   linklist()
   { first=NULL;}
  void additem(int d)
  { link* newlink=new link;
	newlink->data=d;
	newlink->next=first;
	first=newlink;
  }
  void display();
};
 void linklist::display()
 { link* current=first;
   while(current!= NULL)
	{cout<<current->data<<",";
	 current=current->next;
	}
 }
void main()
{ linklist obj; int in;
 /* long int n,x; int m;
  cout<<" the no ?";
  cin>>n;    x=n;
   while(x!=0)
   { m=x % 10;
	 obj.additem(m);
	 x=x / 10;
   }*/
   for(int i=0;i<5;i++)
	{	cout<<"enter no  ";
		cin>>in;
		obj.additem(in);
	 }
 //	obj.display();
  obj.display();
  getche();
}
