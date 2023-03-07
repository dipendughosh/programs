//stacks
#include<iostream.h>
#include<conio.h>
class stack
 {    int arr[5];
	  int top;
   public:
	  stack()
	  {     top=0;  }
	  void push(int var)
	  {		arr[++top]=var;    }
	  int pop()
	  {		return arr[top--];  }
 };
 void main()
 {  clrscr();
	stack obj;  int n,i;
		obj.push(22);
		obj.push(33);
		obj.push(44);
		obj.push(55);
		cout<<obj.pop()<<"   ";
		cout<<obj.pop()<<"   ";
		cout<<obj.pop()<<"   ";
		cout<<obj.pop()<<"   ";
	getche();
 }

