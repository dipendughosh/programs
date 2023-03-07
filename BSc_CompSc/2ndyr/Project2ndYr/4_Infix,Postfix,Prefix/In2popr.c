//To find the prefix and postfix notations of a infix notation
//INPUT:-INFIX:-a+b*c-d
//OUTPUT:-POSTFIX:-abc*+d
//OUTPUT:-PREFIX:--+a*bcd

#include<stdio.h>
#include<conio.h>

//Stack structure
struct stack
{	char data[20];
	int top;
};

void main()
{       //Declaring variables and functions
	struct stack s;
	char infix[20],postfix[20],prefix[20];
	int i,j,f;
	int prefer(char);
	clrscr();
	//Taking the Infix notation as input
	printf("Enter Infix expression - ");
	gets(infix);
	//Logic to convert the Infix notatio to its equivalant Postfix notation
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
	//Logic to convert the Infix notation to its equivalant Prefixo notation
	i=strlen(infix);
	j=i;
	s.top=-1;
	i--;
	prefix[j--]='\0';
	while(i>=0)
	{       f=0;
		if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z') || (infix[i]>='0' && infix[i]<='9'))
			prefix[j--]=infix[i];
		else
		{	while(s.top!=-1)
			{       if(infix[i]==')')
				{	s.data[++s.top]=infix[i];
					break;
				}
				if(infix[i]=='(')
				{       while(s.data[s.top]!=')')
						prefix[j--]=s.data[s.top--];
					s.top--;
					i--;
					f=1;
					break;
				}
				if(prefer(infix[i])<=prefer(s.data[s.top]))
					prefix[j--]=s.data[s.top--];
				else
				{     	s.data[++s.top]=infix[i];
					break;
				}
			}
			if(s.top==-1 && f==0)
				s.data[++s.top]=infix[i];
		}
		if(f!=1)
			i--;
	}
	while(s.top!=-1)
		prefix[j--]=s.data[s.top--];
	prefix[j]='\0';
	//clrscr();
	//Displaying the conversions
	printf("\nINFIX Notation :- %s\nPOSTFIX Notation :- %s\nPREFIX Notation :- %s",infix,postfix,prefix);
	getch();
}

//Function to find the preference of the operators
int prefer(char c)
{	switch(c)
	{	case '+':
		case '-':
			return(1);
		case '*':
		case '/':
			return(2);
	}
	return(0);
}