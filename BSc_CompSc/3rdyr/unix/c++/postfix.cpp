#include<iostream>
#include<string.h>
using namespace std;
class Inttopost
{
private:
	struct stack
	{
		char data[100];
		int top;
	};
	struct stack s;
	char infix[20];
	char postfix[20];

public:
	Inttopost()
	{
		s.top=-1;
	}
	Inttopost(char *a)
	{
		strcpy (infix,a);
	}
	void postfix1();
	void show();
		int prefer(char);
	~Inttopost()
	{
	}
};


void Inttopost::postfix1()
{
	int i,j,f;
	i=0;
	j=0;
	s.top=-1;
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

void Inttopost::show()
{
	cout<<"Infix :- ";
	puts(infix);
	cout<<"Postfix :- ";
	puts(postfix);
}

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
