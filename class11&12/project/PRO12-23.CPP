//16
//linklist using class(done)
#include<iostream.h>  //including header files
#include<conio.h>     //including header files
#include<process.h>   //including header file
class linklist    //declaring class
      { private:
	struct node  //declaring structure
	       { int data;  //declaring data types
		 node *next;  //declaring data types
		 }*p;
	public:
	linklist();//constructor
	void createlist(int n);//function prototypes
	void append(int num);//function prototypes
	void add_at_beg(int num);//function prototypes
	void add_after(int c,int num); //function prototypes
	void del(int num);//function prototypes
	void display();   //function prototypes
	int count(); //function prototypes
	~linklist(); //destructor prototype
	};  //end of class
linklist::linklist() //constructor
	{ p=NULL;
	  };
void linklist::createlist(int n)//function to create list
	       { node *q,*r;int i; //declaring data types
		 //creating first node
		 p=new node;
		 cout<<"Enter value of 1st node:";
		 cin>>p->data;
		 p->next=NULL;
		 q=p;
		 //creating rest of the nodes
		 for(i=0;i<n-1;i++)
		    { r=new node;
		      cout<<"Enter the value of "<<i+2<<"th node:";
		      cin>>r->data;
		      r->next=NULL;
		      q->next=r;
		      q=r;
		      }
		  }
void linklist::add_after(int c,int num)//function for insertion of nodes
	      { node *q,*t;  //declaring data types
		int i=1;  //declaring data types
		q=p;
		while(q->next!=NULL)
		     { if(i==c)
			 { cout<<"\n You cannot enter in the first position";
			   cout<<" using this function"<<"\n";
			   return;
			   }
			if(c-1==i)//finding the desired position
			 { t=new node;
			   t->data=num;
			   t->next=q->next;
			   q->next=t;
			   break;
			   }
			else
			  { i++;
			    q=q->next;
			    }
			}
		if(c-1>i)
		  { cout<<"\n\t\twrong position";
		   }
		}
void linklist::append(int num)//appending list
	     { node *q,*t; //declaring data types
	       if(p==NULL)
		 { p=new node;
		   cout<<"\t\tEnter data:";
		   p->data=num;
		   p->next=NULL;
		   }
	       else
		  { q=p;
		    while(q->next!=NULL)
			 { q=q->next;
			   }
		    t=new node;
		    t->data=num;
		    t->next=NULL;
		    q->next=t;
		   }
	       }
void linklist::del(int n)//function to delete element
	       { node *q,*t; //declaring data types
		 int c=1;  //declaring data types
		 q=p;
		 while(q->next!=NULL) //searching for desired element
		      { if(q->data==n && c==1)
			  { p=q->next; //deleting element
			    return;
			    }
			else if(q->data==n)
			       { t->next=q->next; //deleting element
				 return;
				 }
			else
			   { c++;
			     t=q;
			     q=q->next;
			     }
			}
		 if(q->data==n && q->next==NULL)
		   { t->next=NULL; //deleting element
		     return;
		   }
		 cout<<"\n\t\tThe element is not present"<<"\n";
		 }
void linklist::add_at_beg(int num) //function to add element at begining
	       { node *t; //declaring data types
		 t=new node;
		 t->data=num;
		 t->next=p;
		 p=t;
		 }
void linklist::display()//function to display list
	    { node *q; //declaring data types
	      q=p;
	      cout<<"\t\t";
	      while(q->next!=NULL)
		   { cout<<q->data<<" ";
		     q=q->next;
		     }
	     if(q->next==NULL)
		cout<<q->data;
	     }
linklist::~linklist() //destructor
	  { node *q; //declaring data types
	    if(p==NULL)
	      { return;
	       }
	    while(p!=NULL)
		 { q=p->next;
		   delete p;
		   p=q;
		   }
	     }
int linklist::count() //function to count the number of element in list
	      { node *q;q=p; //declaring data types
		int i=0; //declaring data types
		while(q->next!=NULL)
		     { i++;
		       q=q->next;
		       }
		i++;
		return(i);
		}
void main() //start of main
{ clrscr();
  linklist l;  //declaring data types
  char ch;  //declaring data types
  int n,c,pos,d,a; //declaring data types
  cout<<"Enter no. of node:";
  cin>>a;
  l.createlist(a);//calling fuction to create list
  do
    { clrscr();
      cout<<"\t\t           MENU"<<"\n";
      cout<<"\t\t1.INSERT(anywhere in the list)"<<"\n";
      cout<<"\t\t2.DELETE"<<"\n";
      cout<<"\t\t3.APPEND"<<"\n";
      cout<<"\t\t4.ADD AT THE BEGINING"<<"\n";
      cout<<"\t\t5.Display"<<"\n";
      cout<<"\t\t6.Exit"<<"\n";
      cout<<"\t\tEnter choice:";
      cin>>c;
      l.display(); //displaying list
      cout<<"\n\t\tNumber of element in list is "<<l.count()<<"\n";
      switch(c)
	    { case 1://inserting data between any node
		     cout<<"\t\tEnter position to insert node:";
		     cin>>pos;
		     cout<<"\t\tEnter value:";
		     cin>>n;
		     l.add_after(pos,n);
		     break;
	      case 2://deleting data
		     cout<<"\t\tEnter value to be deleted:";
		     cin>>d;
		     l.del(d);
		     break;
	      case 3://appending
		     cout<<"\t\tEnter value:";
		     cin>>n;
		     l.append(n);
		     break;
	      case 4://adding data at begining
		     cout<<"\t\tEnter value:";
		     cin>>n;
		     l.add_at_beg(n);
		     break;
	      case 5://displaying list
		     l.display();
		     break;
	      case 6://exiting program
		     getch();
		     exit(0);
	      default:cout<<"\n\t\tWrong choice entered.";
		      cout<<" Please try again.";
		      break;
	      }
      cout<<"\n\t\tDo you want to continue?";
      cin>>ch;
      }while(ch!='n');
  l.display();//displaying list
  cout<<"\n\t\tNumber of element in list is "<<l.count();
  getch();
  } //end of main





