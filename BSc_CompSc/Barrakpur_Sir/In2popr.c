//INPUT:-INFIX:-a+b*c-d
//OUTPUT:-POSTFIX:-abc*+d
//OUTPUT:-PREFIX:--+a*bcd

#include<stdio.h>
#include<conio.h>

struct stack
{	char data[20];
	int top;
};

void main()
{       struct stack s;
	char infix[20],postfix[20],prefix[20];
	int i,j;
	int prefer(char);
	clrscr();
	printf("Enter Infix expression - ");
	gets(infix);
	//postfix
	i=0;
	j=0;
	s.top=-1;
	while(infix[i]!='\0')
	{	if(infix[i]>='a' && infix[i]<='z')// || infix[i]>='A' && infix[i]<='Z')
			postfix[j++]=infix[i];
		else
		{	while(s.top!=-1)
			{	if(prefer(infix[i])<=prefer(s.data[s.top]))
					postfix[j++]=s.data[s.top--];
				else
				{	s.data[++s.top]=infix[i];
					break;
				}
			}
			if(s.top==-1)
				s.data[++s.top]=infix[i];
		}
		i++;
	}
	while(s.top!=-1)
		postfix[j++]=s.data[s.top--];
	postfix[j]='\0';
	//prefix
	i=strlen(infix);
	j=i;
	s.top=-1;
	i--;
	prefix[j--]='\0';
	while(i>=0)
	{	if(infix[i]>='a' && infix[i]<='z')// || infix[i]>='A' && infix[i]<='Z')
			prefix[j--]=infix[i];
		else
		{	while(s.top!=-1)
			{	if(prefer(infix[i])<prefer(s.data[s.top]))
					prefix[j--]=s.data[s.top--];
				else
				{	s.data[++s.top]=infix[i];
					break;
				}
			}
			if(s.top==-1)
				s.data[++s.top]=infix[i];
		}
		i--;
	}
	while(s.top!=-1)
		prefix[j--]=s.data[s.top--];
	prefix[j]='\0';
	clrscr();
	printf("\nINFIX:-%s\nPOSTFIX:-%s\nPREFIX:-%s",infix,postfix,prefix);
	getch();
}

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