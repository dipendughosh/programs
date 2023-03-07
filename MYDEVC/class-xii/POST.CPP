//postfix from infix using stack
#include<iostream.h>

#include<process.h>
#include<iomanip.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<dos.h>

int bemdas(char);

class stack
{	private:
	char stk[51];
	int top;
	public:
	stack()
	{	top=-1;
	}
	void push(char s)
	{	stk[++top]=s;
	}
	void pop()
	{	top--;
	}
	char seetop()
	{	return stk[top];
	}
	char poptop()
	{	return stk[top--];
	}
};

void main()
{
	stack s;
	char inexp[51],r[51],t;
	int i,p=0;
	cout<<"\nEnter Infix Expression:";
	cin>>inexp;
	strcat(inexp,")");
	s.push('(');
	for(i=0;i<strlen(inexp);i++);
	{	t=inexp[i];
		if(isdigit(t))
			r[p++]=t;
		else if(t=='(')
			s.push(t);
		else if(t==')')
		{	while(s.seetop()!='(')
				r[p++]=s.poptop();
			s.pop();
		}
		else
		{	while(bemdas('+')<=bemdas(s.seetop()))
				r[p++]=s.poptop();
			s.push(t);
		}
	}
	r[p]='\0';
	cout<<"\nThe postfix expression is: "<<r;
	getche();
}

int bemdas(char c)
{	if(c=='^')
		return(4);
	if(c=='/' || c=='*')
		return(3);
	if(c=='%')
		return(2);
	if(c=='+' || c=='-')
		return(1);
	return(0);
}


 /*int bemdas(char);
class stack
{   private:
        char stk[51];
        int top;
    public:
        stack(){ top = -1;}
    void push(char s) { stk[++top] = s;}
    void pop(){ top--;}
    char seetop(){ return(stk[top]);}
    char poptop(){ return(stk[top--]);}
};

void main()
{   stack s;
    char inexp[51],r[51],t;
    int i,p = 0;
    cout << "Enter Infix Expression : ";
    cin >> inexp;
    strcat(inexp,")");
    s.push('(');
    for(i = 0; i < strlen(inexp); i++)
    {   t = inexp[i];
        if(isdigit(t)) r[p++] = t;
        else if(t == '(') s.push(t);
        else if(t == ')')
        {   while(s.seetop() != '(')
                r[p++] = s.poptop();
            s.pop();
        }
        else
        {   while(bemdas(t) <= bemdas(s.seetop()))
                r[p++] = s.poptop();
           	s.push(t);
        }
   	}
    r[p] = '\0';
    cout << "\nThe Postfix Expression : " << r << endl;
    cout<<endl;
    system("PAUSE");
}

int bemdas(char c)
{   if(c == '^') return(4);
    if(c == '/' || c == '*') return(3);
    if(c == '%') return(2);
    if(c == '+' || c=='-') return(1);
    return(0);
}  */































































































































