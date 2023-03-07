#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define Max 10

//class declaration
//template<class sclass> 
class stack
{
	//sclass a[Max];
	int a[Max];
	int top;
	
	public:
		void push(int value);
		void pop();
		void display();
		
	stack()
	{
		top=-1;
	}
};

//template <class sclass>
void stack/*sclass>*/::push(int value)
{
	if(top==Max-1)
		cout<<"\nStack full!";
	else
	{
		top++;
		cout<<"\ntesting";
		cout<<"\nInside push() the value is="<<value;
		a[top]=value;
		cout<<a[top]<<endl;
	}
}

//template <class sclass>
void stack/*<sclass>*/::pop()
{
	if(top==-1)
		cout<<"\nStack empty!";
	else
	{	cout<<"\nPoped value :- "<<a[top];
        top--;    	
    }
}

//template <class sclass>
void stack/*<sclass>*/::display()
{
	if(top==-1)
		cout<<"\nStack empty!";
	else
	{
	 int j;
	 for(j=0;j<top;j++)
		cout<<a[j];
    }
}


int main()
{
    stack s1;
	//stack<float> s2;
//	stack<char> s3;
	int ch;
	do
	{
		cout<<"MENU"<<endl<<endl;
		cout<<"Press 1 for integer array."<<endl;
		cout<<"Press 2 for floating point array."<<endl;
		cout<<"Press 3 for character array."<<endl;
		cout<<"Press 4 for Exit"<<endl;
		cout<<"\nEnter Your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				int i;
				//stack<int> s1;
			    cout<<"Press 1 for Push operation"<<endl;
				cout<<"Press 2 for Pop operation"<<endl;
				cout<<"Press 3 for display"<<endl;
				cin>>i;
				switch(i)
				{
					case 1:
						int val;
						cout<<"Enter value:";
						cin>>val;
						cout<<"Inside main the value is="<<val;
						s1.push(val);
						
						break;
						
					case 2:
						s1.pop();
						break;
						
					case 3:
						s1.display();
						break;
				}
				break;
			
//			case 2:
//				//stack<float> s2;
//				cout<<"Press 1 for Push operation"<<endl;
//				cout<<"Press 2 for Pop operation"<<endl;
//				cout<<"Press 3 for display"<<endl;
//				cin>>i;
//				switch(i)
//				{
//					case 1:
//						float val;
//						cout<<"Enter value:";
//						cin>>val;
//						s2.push(val);
//						break;
//						
//					case 2:
//						s2.pop();
//						break;
//						
//					case 3:
//						s2.display();
//						break;
//				}
//				break;
				
			//case 3:
//				//stack<char> s3;
//				cout<<"Press 1 for Push operation"<<endl;
//				cout<<"Press 2 for Pop operation"<<endl;
//				cout<<"Press 3 for display"<<endl;
//				cin>>i;
//				switch(i)
//				{
//					case 1:
//						char val;
//						cout<<"Enter value:";
//						val=getchar();
//						s3.push(val);
//						break;
//						
//					case 2:
//						s3.pop();
//						break;
//						
//					case 3:
//						s3.display();
//						break;
//				}
//				break;
				
			case 4:
				exit(0);
				
			default:
				cout<<"Wrong Entry!"<<endl;
		}
	}while(1);
	return 0;
}

			
				