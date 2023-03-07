//To convert a infix notation to postfix notation
#include<iostream>
#include<string.h>

using namespace std;

//Class Infix to Postfix 
class Inttopost
{
//Begining of private scope
private:
	//Stack structure
	struct stack
	{
		char data[100];
		int top;
	};
	//Declaring class member variables
	struct stack s;
	char infix[20],postfix[20];
	//Private function prototype
	int prefer(char);
//Begining of public scope
public:
	//Default constructor
	Inttopost()
	{
		s.top=-1;
	}
	//Parameterized constructor to assign the infix input
	Inttopost(char *a)
	{
		s.top=-1;
		strcpy (infix,a);
	}
	//Prototypes of functions
	void postfix1();
	void show();
	//Destructor
	~Inttopost()
	{
	}
};

//Function to convert to postfix notation
void Inttopost::postfix1()
{
	//Declaring variables and functions
	int i,j,f;
	i=0;
	j=0;
	//Logic to convert the Infix notatio to its equivalant Postfix notation
	while(infix[i]!='\0')
	{       f=0;
		if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z') || (infix[i]>='0' && infix[i]<='9'))
			postfix[j++]=infix[i];
		else
		{	while(s.top!=-1)
			{       if(infix[i]=='(')
				{	s.data[++s.top]=infix[i];
					break;
				}
				if(infix[i]==')')
				{       while(s.data[s.top]!='(')
						postfix[j++]=s.data[s.top--];
					s.top--;
					i++;
					f=1;
					break;
				}
				if(prefer(infix[i])<=prefer(s.data[s.top]))
					postfix[j++]=s.data[s.top--];
				else
				{       s.data[++s.top]=infix[i];
					break;
				}
			}
			if(s.top==-1 && f==0)
				s.data[++s.top]=infix[i];
		}
		if(f!=1)
			i++;
	}
	while(s.top!=-1)
		postfix[j++]=s.data[s.top--];
	postfix[j]='\0';
}

//Function to decide preference of the arithematic operators
int Inttopost::prefer(char c)
{
	switch(c)
	{
		case '+':
		case '-':
			return(1);
		case '*':
		case '/':
			return(2);
	}
	return(0);
}

//Function to display the converted values
void Inttopost::show()
{
	cout<<"Infix :- ";
	puts(infix);
	cout<<"Postfix :- ";
	puts(postfix);
}

//Main function
int main()
{
	char s[20];
	cout<<"Enter infix notation:- ";
	cin>>s;
	Inttopost ob(s);
	ob.postfix1();
	ob.show();
	return 0;
}
