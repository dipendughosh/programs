//Programe to enter or delete numbers from a stack
#include<iostream.h>        //including header file
#include<conio.h>         //including header file
struct node       //declaring structure
       { int data;    //declaring data types
	 node *link;  //declaring data types
	 };
class stack     //declaring class
      { private:
	node *top;  //declaring data types
	public:
	stack() //constructor
	     { top=NULL;
	       }
	void push(int num)//function to enter items in stack
		 { node *temp;    //declaring data types
		   temp=new node;
		   if(temp==NULL)
		      cout<<"\nStack is empty"<<"\n";
		   temp->data=num;
		   temp->link=top;
		   top=temp;
		   }
       int pop() //function to delete items
	      { if(top==NULL)
		  { cout<<"Stack is empty";
		    return(NULL);
		    }
		node *temp;   //declaring data types
		int item;    //declaring data types
		temp=new node;
		temp=top;
		item=temp->data;
		top=top->link;
		delete(temp);
		return(item);
		}
       ~stack();
	};//end of class
stack::~stack() //destructor
	{ if(top==NULL)
	    return;
	  node *temp;  //declaring data types
	  while(top!=NULL)
	       { temp=top;
		 temp=top;
		 top=top->link;
		 delete temp;
		 }
	   }
void main() //starting of main
{ clrscr();
  stack s;  //declaring data types
  char ch;  //declaring data types
  int i,c,n;   //declaring data types
  do
    { clrscr();
      cout<<"        MENU"<<"\n";
      cout<<"1.Push"<<"\n";
      cout<<"2.POP"<<"\n";
      cout<<"Enter your choice";
      cin>>c;
      switch(c)
	    { case 1://entering  item in the stack
		     cout<<"Enter number you want to enter in stack:";
		     cin>>n;
		     s.push(n);//callingfunction
		     break;
	      case 2://deletink items from stack
		     i=s.pop(); //calling function
		     cout<<"\nItem popped is "<<i;
		     break;
	      default:cout<<"\nWrong choice entered";
		      break;
	       }
      cout<<"\nDo you want to continue?";;
      cin>>ch;
      }while(ch!='n');//end of do-loop
  getch();
  } //end of main







